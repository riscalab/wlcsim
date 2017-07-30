!---------------------------------------------------------------!
!
!
!     This subroutine calculates the change in field interaction
!     energy for a MC move which swaps two chains.
!
!
!     Written by Quinn in 2016 based on code from Andrew Spakowitz and Shifan

subroutine MC_int_swap(wlc_p,wlc_d,I1,I2,I3,I4)
use params
implicit none

TYPE(wlcsim_params), intent(inout) :: wlc_p   ! <---- Contains output
TYPE(wlcsim_data), intent(inout) :: wlc_d
integer, intent(in) :: I1      ! Test bead position 1
integer, intent(in) :: I2      ! Test bead position 2
integer, intent(in) :: I3      ! Test bead, first bead of second section
integer, intent(in) :: I4      ! Test bead, second bead of second section

!   Internal variables
integer I                 ! For looping over bins
integer IB                ! Bead index
integer IB2               ! Index you are swapping with
integer rrdr ! -1 if r, 1 if r + dr
integer IX(2),IY(2),IZ(2)
real(dp) WX(2),WY(2),WZ(2)
real(dp) WTOT       ! total weight ascribed to bin
real(dp) RBin(3)    ! bead position
integer inDBin              ! index of bin
integer ISX,ISY,ISZ
LOGICAL isA   ! The bead is of type A

! Copy so I don't have to type wlc_p% everywhere
integer NBinX(3)
real(dp) temp    !for speeding up code
NBinX = wlc_p%NBinX


if (I2-I1 + 1.ne.wlc_p%NB) then
    print*, "Error in MC_int_swap. I2-I1 + 1.ne.NB"
    stop 1
endif
if (I4-I3 + 1.ne.wlc_p%NB) then
    print*, "Error in MC_int_swap. I2-I1 + 1.ne.NB"
    stop 1
endif

! -------------------------------------------------------------
!
!  Calculate change of phi for A and B
!
!--------------------------------------------------------------

wlc_d%NPHI = 0
do IB = I1,I2
  IB2 = IB + I3-I1
  !No need to do calculation if identities are the same
  if (wlc_d%AB(IB).eq.wlc_d%ABP(IB2)) cycle
  do rrdr = -1,1,2
   ! on initialize only add current position
   ! otherwise subract current and add new
   if (rrdr.eq.-1) then
       RBin(1) = wlc_d%R(IB,1)
       RBin(2) = wlc_d%R(IB,2)
       RBin(3) = wlc_d%R(IB,3)
       isA = wlc_d%AB(IB).eq.1
   else
       RBin(1) = wlc_d%RP(IB,1)
       RBin(2) = wlc_d%RP(IB,2)
       RBin(3) = wlc_d%RP(IB,3)
       isA = wlc_d%ABP(IB).eq.1
   endif
   ! --------------------------------------------------
   !
   !  Interpolate beads into bins
   !
   ! --------------------------------------------------
   call interp(wlc_p%confineType,RBin,wlc_p%LBOX,wlc_p%NBinX,wlc_p%dbin,IX,IY,IZ,WX,WY,WZ)

   ! -------------------------------------------------------
   !
   ! Count beads in bins
   !
   ! ------------------------------------------------------
   !   Add or Subtract volume fraction with weighting from each bin
   !   I know that it looks bad to have this section of code twice but it
   !   makes it faster.
   if (isA) then
       do ISX = 1,2
          if ((IX(ISX).le.0).OR.(IX(ISX).ge.(NBinX(1) + 1))) CYCLE
          do ISY = 1,2
             if ((IY(ISY).le.0).OR.(IY(ISY).ge.(NBinX(2) + 1))) CYCLE
             do ISZ = 1,2
                if ((IZ(ISZ).le.0).OR.(IZ(ISZ).ge.(NBinX(3) + 1))) cycle
                WTOT = WX(ISX)*WY(ISY)*WZ(ISZ)
                inDBin = IX(ISX) + (IY(ISY)-1)*NBinX(1) + (IZ(ISZ)-1)*NBinX(1)*NBinX(2)
                ! Generate list of which phi's change and by how much
                I = wlc_d%NPHI
                do
                   if (I.eq.0) then
                      wlc_d%NPHI = wlc_d%NPHI + 1
                      wlc_d%inDPHI(wlc_d%NPHI) = inDBin
                      temp = rrdr*WTOT*wlc_p%beadVolume/wlc_d%Vol(inDBin)
                      wlc_d%DPHIA(wlc_d%NPHI) = temp
                      wlc_d%DPHIB(wlc_d%NPHI) = -temp
                      exit
                   elseif (inDBin == wlc_d%inDPHI(I)) then
                      temp = rrdr*WTOT*wlc_p%beadVolume/wlc_d%Vol(inDBin)
                      wlc_d%DPHIA(I) = wlc_d%DPHIA(I) + temp
                      wlc_d%DPHIB(I) = wlc_d%DPHIB(I)-temp
                      exit
                   else
                      I = I-1
                   endif
                enddo
             enddo
          enddo
       enddo
   else
       do ISX = 1,2
          if ((IX(ISX).le.0).OR.(IX(ISX).ge.(NBinX(1) + 1))) CYCLE
          do ISY = 1,2
             if ((IY(ISY).le.0).OR.(IY(ISY).ge.(NBinX(2) + 1))) CYCLE
             do ISZ = 1,2
                if ((IZ(ISZ).le.0).OR.(IZ(ISZ).ge.(NBinX(3) + 1))) cycle
                WTOT = WX(ISX)*WY(ISY)*WZ(ISZ)
                inDBin = IX(ISX) + (IY(ISY)-1)*NBinX(1) + (IZ(ISZ)-1)*NBinX(1)*NBinX(2)
                ! Generate list of which phi's change and by how much
                I = wlc_d%NPHI
                do
                   if (I.eq.0) then
                      wlc_d%NPHI = wlc_d%NPHI + 1
                      wlc_d%inDPHI(wlc_d%NPHI) = inDBin
                      temp = rrdr*WTOT*wlc_p%beadVolume/wlc_d%Vol(inDBin)
                      wlc_d%DPHIA(wlc_d%NPHI) = -temp
                      wlc_d%DPHIB(wlc_d%NPHI) = temp
                      exit
                   elseif (inDBin == wlc_d%inDPHI(I)) then
                      temp = rrdr*WTOT*wlc_p%beadVolume/wlc_d%Vol(inDBin)
                      wlc_d%DPHIA(I) = wlc_d%DPHIA(I)-temp
                      wlc_d%DPHIB(I) = wlc_d%DPHIB(I) + temp
                      exit
                   else
                      I = I-1
                   endif
                enddo
             enddo !ISZ
          enddo !ISY
       enddo !ISX
   endif
 enddo ! loop over rrdr.  A.k.a new and old
enddo ! loop over IB  A.k.a. beads
call hamiltonian(wlc_p,wlc_d,.false.)

RETURN
END

!---------------------------------------------------------------!