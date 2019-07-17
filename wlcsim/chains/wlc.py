"""Generate equilibrium conformations of Wormlike Chains (WLCs) exactly."""
import numpy as np
from numpy.random import random_sample as urand
import scipy
import scipy.optimize
from scipy.special import erfi
from numba import jit

from functools import partial

def wlc_bob(N, L, lp, lt=0):
    l0 = L/(N-1)
    eps = l0/lp

    r = np.zeros((N,3))
    u = np.zeros((N,3))
    u[:,2] = 1
    n = np.zeros((N,3))
    n[:,1] = 1
    for j in range(1, N):
        # first get an arbitrary basis n1, n2 to the cotangent plane to u[j-1]
        n1 = np.array([0, 0, 1])
        n1 = n1 - (n1@u[j-1])*u[j-1]
        mag = np.linalg.norm(n1)
        # if we accidentally chose vector parallel to u[j-1]
        if np.isclose(mag, 0):
            n1 = np.array([0, 1, 0])
            n1 = n1 - (n1@u[j-1])*u[j-1]
            mag = np.linalg.norm(n1)
        n1 = n1/mag
        n2 = np.cross(n1, u[j-1])
        n2 = n2/np.linalg.norm(n2)

        # now at a random angle in cotangent plane
        theta = 2*np.pi*urand(1)
        # WLC formula for the magnitude of u[j]@u[j-1]
        z = (1/eps)*np.log(2*urand()*np.sinh(eps)+np.exp(-eps))
        u[j] = np.sqrt(1-z*z)*(np.cos(theta)*n1 + np.sin(theta)*n2 + z*u[j-1])
        u[j] = u[j]/np.linalg.norm(u[j])

        r[j] = r[j-1] + l0*u[j]
    return r, u, n

def phi_indef_(phi, eps):
    """indefinite integral of sin(phi)exp(-phi**2/(2*sigma))"""
    return np.real(np.sqrt(np.pi*eps/2)/2*np.exp(-eps/2)*(
        - erfi((eps - 1j*phi)/np.sqrt(2*eps))
        - erfi((eps + 1j*phi)/np.sqrt(2*eps))
    ))

def phi_z_(eps):
    """normalization factor. phi_indef_(pi)-phi_indef_(0)"""
    return np.real(np.sqrt(np.pi*eps/2)/2*np.exp(-eps/2)*(
        - erfi((eps - 1j*np.pi)/np.sqrt(2*eps))
        + 2*erfi(np.sqrt(eps/2))
        - erfi((eps + 1j*np.pi)/np.sqrt(2*eps))
    ))

def phi_cdf(phi, eps):
    """The cumulative distribution of a given azimuthal angle :math:`phi` given
    a distance between neighboring beads of :math:`\Epsilon = ds/l_p`."""
    return (phi_indef_(phi, eps) - phi_indef_(0, eps))/phi_z_(eps)

def phi_prob(phi, eps):
    """The probability distribution of a given azimuthal angle :math:`phi`
    given a distance between neighboring beads of :math:`\Epsilon = ds/l_p`."""
    return np.sin(phi)*np.exp(-np.power(phi, 2)/2/eps)/phi_z_(eps)

def dphi_prob(phi, eps):
    """Derivative of phi_prob w.r.t. phi."""
    dphi = np.cos(phi)*np.exp(-np.power(phi, 2)/2/eps) \
         - np.sin(phi)*np.exp(-np.power(phi, 2)/2/eps)*2*phi/2/eps
    return dphi/phi_z_(eps)

@jit(nopython=True)
def cot_plane(u, unit=True, tol=1e-8):
    """Return an arbitrary basis to the cotangent plane given the tangent
    vector (assumed unit vector unless otherwise specified)."""
    if not unit:
        u = u/np.linalg.norm(u)
    n1 = np.array([0.0, 0.0, 1.0])
    n1 = n1 - (n1@u)*u
    mag = np.linalg.norm(n1)
    # if we accidentally chose vector parallel to u
    if np.abs(mag) < tol:
        n1 = np.array([0.0, 1.0, 0.0])
        n1 = n1 - (n1@u)*u
        mag = np.linalg.norm(n1)
    n1 = n1/mag
    # n2 = np.cross(n1, u)
    # for jit
    n2 = np.array([n1[1]*u[2] - n1[2]*u[1],
                   n1[2]*u[0] - n1[0]*u[2],
                   n1[0]*u[1] - n1[1]*u[0]])

    n2 = n2/np.linalg.norm(n2)
    return n1, n2

def wlc(N, L, lp):
    r"""Draw discrete wormlike chain steps.

    The energy of the wormlike chain is proportional to the curvature of the
    chain squared. We make the assumption that the curvature is constant, and
    that we are approximating the curve via its osculating circle at each
    point.

    For the discrete WLC, we want the next bead to be on the sphere centered at
    the previous bead with radius equal to the length of chain between the
    beads (we call this eps).

    To decide where on that sphere the next bead should be placed, we write the
    curve as r(s) and define the azimuthal angle between the two beads to be
    phi(ds) = arccos(u(s) . u(s+ds)), where ds is the path length between the
    beads. Assuming constant curvature between the two beads, we have simply
    that phi(ds) = kappa*ds. Thus, the probability of a given azimuthal angle
    is just

    .. math::

        P(\phi | \theta) \propto e^{-\beta \frac{l_p}{2} \phi / ds}

    or just a Gaussian, with variance given by :math:`ds/l_p`, the number of
    persistence lengths between the beads.

    Recall the shape of the sphere means that correctly integrating over the
    uniform distribution in the spherical angle leaves us with

    .. math::

        P(\phi) \propto \sin(\phi) e^{-\beta \frac{l_p}{2} \phi / ds}

    the normalization factor to make this a probability distribution for a
    given :math:`ds/l_p` can be calculating analytically (restricting
    explicitly to :math:`\phi\in[0,\pi]` makes the formula uglier but
    WolframAlpha can still do it), yielding an exact probability distribution

    .. math::
        P(\phi) = \sqrt{\frac{2}{\pi (ds/l_p)}} \frac{-1}{e^{ds/2l_p}
        \erf{\sqrt{ds/2l_p}}} \sin(\phi) e^{phi^2/2(ds/l_p)}

    which we can use to inverse-transform sample phi, then draw theta
    uniformly.

    Given theta, phi, we can then get the next tangent vector (and thus next
    location, since for discrete WLC we define u = diff(r)) from the current
    one.

    Notes
    -----
    We using the formalism above, we can get an estimate for what values of
    :math:`ds/l_p` are reasonable to use. For example, for eps=0.1,
    we will typically see values of phi less than pi/3. for eps=0.01, we see
    phi less than phi/10 or so.
    """
    l0 = L/(N-1)
    eps = l0/lp # ds

    r = np.zeros((N,3))
    r[1,2] = eps # initial in z-direction
    for j in range(2, N):
        # first draw the direction of the next tangent vector w.r.t. the
        # previous one
        xi = urand()
        fphi = lambda phi: phi_cdf(phi, eps=eps) - xi
        # 0.1 rads is a reasonable starting value so that the initial
        # derivative isn't zero
        phi = scipy.optimize.toms748(fphi, 0, np.pi, k=2)
        # this doesn't provably work always, sometimes leaves interval
        # phi = scipy.optimize.newton(fphi, 0.1, fprime=partial(phi_prob, eps=eps),
        #                             fprime2=partial(dphi_prob, eps=eps))
        theta = 2*np.pi*urand()

        # now map phi,theta to local coordinates of chain
        u_prev = (r[j-1] - r[j-2])/eps
        n1, n2 = cot_plane(u_prev)

        u_next = n1*np.cos(theta)*np.sin(phi) \
               + n2*np.sin(theta)*np.sin(phi) \
               + u_prev*np.cos(phi)
        r[j] = r[j-1] + eps*u_next

    return r

def dwlc(N, L, lp, lt):
    """Generate a wormlike chain with potentially less beads than is wise for
    direct sampling of WLC with 'quadratic' approximation used by wlc
    function, by "regridding" more finely then only saving the beads that were
    originally requested."""

    fortran_code = """subroutine effective_wormlike_chain_init(R, U, NT, wlc_p, rand_stat)
    use mersenne_twister
    use params, only : wlcsim_params, dp, max_wlc_l0, maxWlcDelta
    use vector_utils, only: randomUnitVec
    use polydispersity, only: length_of_chain
    implicit none
    integer, intent(in) :: nt
    type(wlcsim_params), intent(in) :: wlc_p
    real(dp), intent(out) :: R(3,nt), U(3,nt)
    type(random_stat), intent(inout) :: rand_stat

    integer IB, NgB, i, j
    real(dp) l0, eps
    real(dp) urand(3)
    real(dp), dimension(:,:), allocatable :: tmpR, tmpU

    IB = 1
    if (wlc_p%DEL > max_wlc_l0) then
        NgB = ceiling(wlc_p%DEL/max_wlc_l0) + 1
    else
        NgB = 1 + 1
    endif
    allocate(tmpR(3,NgB))
    allocate(tmpU(3,NgB))
    l0 = wlc_p%DEL/(NgB - 1)
    EPS = WLC_P__LP/l0 ! bending rigidity for wormlike chain
    do I = 1,WLC_P__NP
        ! uniformly first bead inside box
        call random_number(urand,rand_stat)
        R(1,IB) = urand(1)*WLC_P__LBOX_X
        R(2,IB) = urand(2)*WLC_P__LBOX_Y
        R(3,IB) = urand(3)*WLC_P__LBOX_Z
        ! uniformly from unit sphere first tan vec
        call randomUnitVec(U(:,IB),rand_stat)
        IB = IB + 1
        do J = 2,length_of_chain(I)
            tmpR(:,1) = R(:,IB-1)
            tmpU(:,1) = U(:,IB-1)
            call wlc_init(tmpR, tmpU, NgB, EPS, l0, rand_stat)
            R(:,IB) = tmpR(:,NgB)
            U(:,IB) = tmpU(:,NgB)
            IB = IB + 1
        enddo
    enddo
    deallocate(tmpR)
    deallocate(tmpU)
end subroutine effective_wormlike_chain_init
"""

