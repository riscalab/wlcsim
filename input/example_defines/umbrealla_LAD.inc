! ------------------------------------
! Generaged by: Quinn
!
! Description:
! Chromatin Lamina Associated Domain simulation at nucleosome level with LEFs
! ------------------------------------

! ----------------------------
!
!   General Switches
!
! ---------------------------

#define WLC_P__CODENAME "quinn"
! VARIABLE COMMENT: ! which simulation code to run
! DEFAULTS COMMENT: ! This input is based on Quinn's code
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__WARNING_LEVEL 1
! VARIABLE COMMENT: ! 0 = no warnings, 1 = moderate performance impact, 2 = considerable slowdown
! DEFAULTS COMMENT: !
! TYPE: INTEGER

#define WLC_P__RING .FALSE.
! VARIABLE COMMENT: ! whether the polymer is a ring
! DEFAULTS COMMENT: ! not a ring by default
! TYPE: LOGICAL

#define WLC_P__LOCAL_TWIST .FALSE.
! VARIABLE COMMENT: ! whether to include twist energy (local)
! DEFAULTS COMMENT: ! don't include twist by default
! TYPE: LOGICAL

#define WLC_P__TWIST .FALSE.
! VARIABLE COMMENT: ! whether to include twist (wlc_p only for now)
! DEFAULTS COMMENT: ! don't include twist by default
! TYPE: LOGICAL

#define WLC_P__CONFINETYPE 'cube'
! VARIABLE COMMENT: ! type of Boundary Conditions
! DEFAULTS COMMENT: ! spherical nucleus
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__BOUNDARY_TYPE "SolidEdgeBin"
! VARIABLE COMMENT: ! type of Boundary Conditions
! DEFAULTS COMMENT: ! based on geometery of current problem
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__FRACTIONAL_BIN .FALSE.
! VARIABLE COMMENT: ! whether to use fractional bin volumes in field treatment
! DEFAULTS COMMENT: ! If in doubt make it false
! TYPE: LOGICAL

#define WLC_P__INITCONDTYPE 'multiRing'
! VARIABLE COMMENT: ! initial condition type
! DEFAULTS COMMENT: ! needed to matach boundary/binding conditions
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__INTRAPOLYMER_STICK_CROSSING_ENFORCED .FALSE.
! VARIABLE COMMENT: ! prevent polymer from ever crossing itself
! DEFAULTS COMMENT: ! NOT IMPLEMENTED
! TYPE: LOGICAL

#define WLC_P__CHEM_STATE_FROM_FILE .FALSE.
! VARIABLE COMMENT: ! read initial chemical sequence from file
! DEFAULTS COMMENT: ! don't read binding state from file
! TYPE: LOGICAL

#define WLC_P__CHEM_SEQ_FROM_FILE .TRUE.
! VARIABLE COMMENT: ! read initial chemical/methylation state from file
! DEFAULTS COMMENT: ! read in methelation state
! TYPE: LOGICAL

#define WLC_P__FRMFILE .FALSE.
! VARIABLE COMMENT: ! read initial condition R from file
! DEFAULTS COMMENT: ! don't load initial bead positions from file
! TYPE: LOGICAL

#define WLC_P__FRMFIELD .FALSE.
! VARIABLE COMMENT: ! read initial field from file
! DEFAULTS COMMENT: ! don't load initial field values from file
! TYPE: LOGICAL

#define WLC_P__COLLISIONDETECTIONTYPE 0
! VARIABLE COMMENT: ! save first passage time vectors to file
! DEFAULTS COMMENT: ! don't track first passage time collisions between beads
! TYPE: INTEGER

#define WLC_P__RESTART .FALSE.
! VARIABLE COMMENT: ! whether we are restarting from a previous sim or not
! DEFAULTS COMMENT: ! don't restart from previously saved simulation
! TYPE: LOGICAL

#define WLC_P__INTERP_BEAD_LENNARD_JONES .FALSE.
! VARIABLE COMMENT: ! whether to have inter bead lennard jones energies
! DEFAULTS COMMENT: ! no intrapolymer interactions by default
! TYPE: LOGICAL

#define WLC_P__CHANGINGCHEMICALIDENTITY .TRUE.
! VARIABLE COMMENT: ! Allows chemical A/B sequence to change
! DEFAULTS COMMENT: ! Meth state needs to change with time
! TYPE: LOGICAL

#define WLC_P__VARIABLE_CHEM_STATE .TRUE.
! VARIABLE COMMENT: ! Does model contain changing chemical state
! DEFAULTS COMMENT: ! Yes, binding state changes
! TYPE: LOGICAL

#define WLC_P__FIELD_INT_ON .TRUE.
! VARIABLE COMMENT: whether or not to execute mc_int
! DEFAULTS COMMENT: ! no interactions by default
! TYPE: LOGICAL

#define WLC_P__FIELDINTERACTIONTYPE 'chromatin'
! VARIABLE COMMENT: ! Choose the Hamiltonian you would like
! DEFAULTS COMMENT: ! See MC_Hamiltonian
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__RECENTER_ON .FALSE.
! VARIABLE COMMENT: ! Wheter to move drifted chains back in periodic BC
! DEFAULTS COMMENT: ! Not in periodic BC
! TYPE: LOGICAL

#define WLC_P__CYLINDRICAL_CHAIN_EXCLUSION .FALSE.
! VARIABLE COMMENT: ! Chains cannont occupy the same place at same time
! DEFAULTS COMMENT: ! We care about collisions
! TYPE: LOGICAL

#define WLC_P__NEIGHBOR_BINS .FALSE.
! VARIABLE COMMENT: ! Keep track of neighbors by recursive binning
! DEFAULTS COMMENT: ! Set off because expensive
! TYPE: LOGICAL

#define WLC_P__APPLY_EXTERNAL_FIELD .TRUE.
! VARIABLE COMMENT: ! Externally applied field (e.g. radial binding)
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__EXTERNAL_FIELD_TYPE "nonSpecificToCubeSide"
! VARIABLE COMMENT: ! options: "nonSpecificToCubeSide",  "nonSpecificToSphere", "toExcludedSphereInPeriodic", "NSTCS_plus_binding"
! DEFAULTS COMMENT: !
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__APPLY_2body_potential .FALSE.
! VARIABLE COMMENT: ! Externally applied field (e.g. radial binding)
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__EXPLICIT_BINDING .TRUE.
! VARIABLE COMMENT: ! Include specific interactions between specified beads
! DEFAULTS COMMENT: ! Not included by default
! TYPE: LOGICAL

#define WLC_P__NETWORK .FALSE.
! VARIABLE COMMENT: ! Include specific interactions between specified beads
! DEFAULTS COMMENT: ! Not included by default
! TYPE: LOGICAL

#define WLC_P__NO_LEF_CROSSING .FALSE.
! VARIABLE COMMENT: ! no explicit binding pairs can cross eachother, e.g. 1-to-10 and 5-15
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__ELASTICITY_TYPE "constant"
! VARIABLE COMMENT: ! which simulation code to run
! DEFAULTS COMMENT: ! not bruno, brad, or quinn, so will error unless specified elsewehre
! TYPE: CHARACTER(MAXPARAMLEN)

#define WLC_P__INCLUDE_NUC_TRANS .TRUE.
! VARIABLE COMMENT: ! Whether to include the translation across the nucleosome
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__CHI_L2_ABLE .FALSE.
! VARIABLE COMMENT: ! Whether the l=2 component is ever calcualted
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__UMBRELLA .TRUE.
! VARIABLE COMMENT: ! Whether the l=2 component is ever calcualted
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

! ----------------------------
!
!   Output
!
! ---------------------------

#define WLC_P__EXITWHENCOLLIDED .FALSE.
! VARIABLE COMMENT: ! stop sim after every n^2 loops have formed at least once
! DEFAULTS COMMENT: ! don't stop sim when coltimes is full by default
! TYPE: LOGICAL

#define WLC_P__SAVER .TRUE.
! VARIABLE COMMENT: ! save R vectors to file
! DEFAULTS COMMENT: ! do save orientation vectors (makes restart of ssWLC possible)
! TYPE: LOGICAL

#define WLC_P__SAVEU .FALSE.
! VARIABLE COMMENT: ! save U vectors to file
! DEFAULTS COMMENT: ! don't save orientation vectors (makes restart of ssWLC possible)
! TYPE: LOGICAL

#define WLC_P__SAVEAB .TRUE.
! VARIABLE COMMENT: ! save AB (chemical identity) to file
! DEFAULTS COMMENT: ! dont' save AB by default, almost nobody uses this
! TYPE: LOGICAL

#define WLC_P__SAVEPHI .FALSE.
! VARIABLE COMMENT: ! save Phi vectors to file
! DEFAULTS COMMENT: ! don't save A/B density per bin (not needed for restart)
! TYPE: LOGICAL

#define WLC_P__APPEND_R .FALSE.
! VARIABLE COMMENT: ! Output all r(t) to same file
! DEFAULTS COMMENT: ! Use old output format
! TYPE: LOGICAL

! ----------------------------
!
!   Number / Chemical identity variables
!
! ---------------------------

#define WLC_P__NB 390387
! VARIABLE COMMENT: ! Number of beads in a polymer NB = nMpP*nBpM
! DEFAULTS COMMENT: ! From Chr 16 at 200bp per nucleosome
! TYPE: INTEGER

#define WLC_P__NMPP WLC_P__NB/WLC_P__NBPM
! VARIABLE COMMENT: ! Number of monomers (NOT BEADS!) in a polymer
! DEFAULTS COMMENT: None
! TYPE: INTEGER

#define WLC_P__NBPM 1
! VARIABLE COMMENT: ! number beads per monomer
! DEFAULTS COMMENT: Each bead is a nucleosome
! TYPE: INTEGER

#define WLC_P__NP 1
! VARIABLE COMMENT: ! Number of polymers
! DEFAULTS COMMENT: ! one polymer
! TYPE: INTEGER

#define WLC_P__NT WLC_P__NB*WLC_P__NP
! VARIABLE COMMENT: ! Total Number of beads
! DEFAULTS COMMENT: ! assuming same number of beads on each polymer
! TYPE: INTEGER

#define WLC_P__POLY_DISP_TYPE "None"
! VARIABLE COMMENT: ! Whether to include chains of different lengths
! DEFAULTS COMMENT: ! "None" for all the same length, "FromFile" for different
! TYPE: INTEGER

#define WLC_P__FA 0.0_DP
! VARIABLE COMMENT: ! Fraction of A beads
! DEFAULTS COMMENT: ! Initial fraction methelated
! TYPE: REAL(DP)

#define WLC_P__LAM 0.0_DP
! VARIABLE COMMENT: ! Chemical correlation parameter (eigenvalue of transition matrix that generates A/B's)
! DEFAULTS COMMENT: ! perfectly random sequence  (see generating_sequences.rst for details)
! TYPE: REAL(DP)

#define WLC_P__F_METH 0.0_DP
! VARIABLE COMMENT: ! Fraction methalated is using option 2 ( for initialization )
! DEFAULTS COMMENT: ! not used
! TYPE: REAL(DP)

#define WLC_P__LAM_METH 0.0_DP
! VARIABLE COMMENT: ! eigenvalue of transition matrix generating initial methalation
! DEFAULTS COMMENT: ! not used
! TYPE: REAL(DP)

#define WLC_P__ASYMMETRICALTERNATINGCHEM .FALSE.
! VARIABLE COMMENT: ! initialize asymmetric alturnating chain
! DEFAULTS COMMENT: ! Nope
! TYPE: LOGICAL

#define WLC_P__TWO_TAIL .TRUE.
! VARIABLE COMMENT: ! Chromatin with two histon tails per bead
! DEFAULTS COMMENT: ! This is more realistic
! TYPE: LOGICAL

#define WLC_P__N_SPHERES_TO_SIDE 1
! VARIABLE COMMENT: ! Number of spheres
! DEFAULTS COMMENT: ! one, wont be used unless you use corrisponding B.C.
! TYPE: INTEGER

#define WLC_P__MAX_BACEPAIRS_PER_BEAD 350
! VARIABLE COMMENT: ! Number of spheres
! DEFAULTS COMMENT: ! 203 linker + 147 wrap
! TYPE: INTEGER

#define WLC_P__N_EXTERNAL_BIND_POINTS 10
! VARIABLE COMMENT: ! number of points bound to boundary
! DEFAULTS COMMENT: ! 0 for off
! TYPE: INTEGER

! ----------------------------
!
!   Length variables
!
! ---------------------------

#define WLC_P__LENGTH_PER_BP 0.332_DP
! VARIABLE COMMENT: ! length along dna for one bace pair
! DEFAULTS COMMENT: ! in nm
! TYPE: REAL(DP)

#define WLC_P__LL 50
! VARIABLE COMMENT: ! linker length in bp between adjacent nucleosomes
! DEFAULTS COMMENT: ! 38bp is like mouse-ish
! TYPE: INTEGER

#define WLC_P__L 224438.519_dp
! VARIABLE COMMENT: ! length of each polymer in simulation
! DEFAULTS COMMENT: ! chr 16 / Delta
! TYPE: REAL(DP)

#define WLC_P__L0 (WLC_P__L/(WLC_P__NB-1.0_DP))
! VARIABLE COMMENT: ! bead spacing, Remove the "-1.0_dp" if ring
! DEFAULTS COMMENT: ! derive from L and NB, (WLC_P__L/(WLC_P__NB-1.0_DP))
! TYPE: REAL(DP)

#define WLC_P__LP 0.662_DP
! VARIABLE COMMENT: ! persistence length
! DEFAULTS COMMENT: ! 50nm / Delta
! TYPE: REAL(DP)

#define WLC_P__LT 1.524_DP
! VARIABLE COMMENT: ! twist persistence length
! DEFAULTS COMMENT: ! twist persistence length equals persistence length by default
! TYPE: REAL(DP)

#define WLC_P__LENGTH_PER_BP 0.33
! VARIABLE COMMENT: ! length along dna for one bace pair
! DEFAULTS COMMENT: ! in nm
! TYPE: REAL(DP)

#define WLC_P__BEADVOLUME 0.02200_DP
! VARIABLE COMMENT: ! Bead volume
! DEFAULTS COMMENT: ! From nucleosome volume estimate of 520 nm^3
! TYPE: REAL(DP)

#define WLC_P__COLLISIONRADIUS 0.174_DP
! VARIABLE COMMENT: ! radius triggering collisions to be recorded in "coltimes"
! DEFAULTS COMMENT: ! consistant with bead volume
! TYPE: REAL(DP)

#define WLC_P__K_FIELD 0.0_DP
! VARIABLE COMMENT: ! wave vector of applied sinusoidal field (used in PT to step around 1st order phase transition)
! DEFAULTS COMMENT: ! No field
! TYPE: REAL(DP)

#define WLC_P__NCOLBIN 1
! VARIABLE COMMENT: ! Number of collision-detection bins on each edge
! DEFAULTS COMMENT: ! not used.  equivalent to collisionDetectionType = 1
! TYPE: INTEGER

#define WLC_P__NBIN_X 64
! VARIABLE COMMENT: ! Number of MC bins on an edge
! DEFAULTS COMMENT: ! set number density of nucleus
! TYPE: INTEGER

#define WLC_P__NBIN_Y WLC_P__NBIN_X
! VARIABLE COMMENT: ! Number of MC bins on an edge
! DEFAULTS COMMENT: ! same
! TYPE: INTEGER

#define WLC_P__NBIN_Z WLC_P__NBIN_X
! VARIABLE COMMENT: ! Number of MC bins on an edge
! DEFAULTS COMMENT: ! same
! TYPE: INTEGER

#define WLC_P__LBOX_X 64.0_dp
! VARIABLE COMMENT: ! monte carlo field bin total box length (approximate)
! DEFAULTS COMMENT: ! box size/confinment, *MUST* be set by user
! TYPE: REAL(DP)

#define WLC_P__LBOX_Y WLC_P__LBOX_X
! VARIABLE COMMENT: ! monte carlo field bin total box length (approximate)
! DEFAULTS COMMENT: ! box size/confinment, *MUST* be set by user
! TYPE: REAL(DP)

#define WLC_P__LBOX_Z WLC_P__LBOX_X
! VARIABLE COMMENT: ! monte carlo field bin total box length (approximate)
! DEFAULTS COMMENT: ! box size/confinment, *MUST* be set by user
! TYPE: REAL(DP)

#define WLC_P__DBIN 1.0_dp
! VARIABLE COMMENT: ! monte carlo field bin discretization size (approximate)
! DEFAULTS COMMENT: ! should always be 1.0_dp according to quinn
! TYPE: REAL(DP)

#define WLC_P__CONFINEMENT_CUBE_LENGTH 64.0_dp
! VARIABLE COMMENT: !
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)

#define WLC_P__CONFINEMENT_SLIT_WIDTH NAN
! VARIABLE COMMENT: !  Size of confinement. Set = LBOX -2*DBIN if bin interation is on
! DEFAULTS COMMENT: ! Must set if in use
! TYPE: REAL(DP)

#define WLC_P__CONFINEMENT_SPHERE_DIAMETER 62_dp
! VARIABLE COMMENT: !
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)

#define WLC_P__CONFINEMENT_ECOLI_LENGTH 0.0_dp
! VARIABLE COMMENT: !
! DEFAULTS COMMENT: ! zero for sphere
! TYPE: REAL(DP)

#define WLC_P__CONFINEMENT_ECOLI_DIAMETER NAN
! VARIABLE COMMENT: ! Size of confinement. Set = LBOX - 2*DBIN if bin interaction on
! DEFAULTS COMMENT: ! Must set if in use
! TYPE: REAL(DP)

#define WLC_P__BINDING_R 1.0_DP
! VARIABLE COMMENT: ! Binding Radius
! DEFAULTS COMMENT: ! 3-5nm / Delta in nm
! TYPE: REAL(DP)

#define WLC_P__HP1_BINDING_R 0.1024_DP
! VARIABLE COMMENT: ! Binding Radius
! DEFAULTS COMMENT: ! 3-5nm / Delta in nm
! TYPE: REAL(DP)

#define WLC_P__CHAIN_D 0.0_DP
! VARIABLE COMMENT: Diameter of chain for exclusion
! DEFAULTS COMMENT: Set to zero for no exclusion
! TYPE: REAL(DP)


! ----------------------------
!
!   Energy variables
!
! ---------------------------

#define WLC_P__EU (-1.52_DP)
! VARIABLE COMMENT: ! Energy of HP1 binding for unmethalated sites
! DEFAULTS COMMENT: ! From Pete's paper
! TYPE: REAL(DP)

#define WLC_P__EM 0.01_DP
! VARIABLE COMMENT: ! Energy of HP1 binding for methalated sites
! DEFAULTS COMMENT: ! by default, no hp1 binding energy included
! TYPE: REAL(DP)

#define WLC_P__CHI (-1.0_DP)
! VARIABLE COMMENT: ! Chi paremter
! DEFAULTS COMMENT: ! Poly-solvent Chi, unknown, set <0 so output looks OK
! TYPE: REAL(DP)

#define WLC_P__MU -1.0_DP
! VARIABLE COMMENT: ! HP1 chemical potential
! DEFAULTS COMMENT: ! overridden by PT
! TYPE: REAL(DP)

#define WLC_P__HA 0.0_DP
! VARIABLE COMMENT: ! Applied Field
! DEFAULTS COMMENT: ! no applied field
! TYPE: REAL(DP)

#define WLC_P__COUPLING_ENERGY -4.0_DP
! VARIABLE COMMENT: ! Coupling energy between beads (negative = attractive)
! DEFAULTS COMMENT: ! from pete's paper
! TYPE: REAL(DP)

#define WLC_P__HP1_BIND WLC_P__COUPLING_ENERGY*((4.0_DP/3.0_DP)*3.1416_DP*WLC_P__HP1_BINDING_R**3)*(WLC_P__DBIN**3)/(2.0_DP*WLC_P__BEADVOLUME**2)
! VARIABLE COMMENT: ! Strength of Coupling
! DEFAULTS COMMENT: ! (-4.0 kT)*v_a*(del^3)/(2*v_b^2)
! TYPE: REAL(DP)

#define WLC_P__KAP 10000_DP
! VARIABLE COMMENT: ! Degree if incompressibility
! DEFAULTS COMMENT: ! incompressable
! TYPE: REAL(DP)

#define WLC_P__CHI_L2 0.0_DP
! VARIABLE COMMENT: ! prop. to . Maier Saupe parameter
! DEFAULTS COMMENT: ! zero for simplitity
! TYPE: REAL(DP)

#define WLC_P__EXPLICIT_BIND_ENERGY 50.0_DP
! VARIABLE COMMENT: ! Include specific interactions between specified beads
! DEFAULTS COMMENT: ! Not included by default
! TYPE: REAL(DP)

#define WLC_P__AmplitudeExternalField -0.3_DP
! VARIABLE COMMENT: ! For an extra potential I wanted to put in
! DEFAULTS COMMENT: ! Not included by default
! TYPE: REAL(DP)

#define WLC_P__Amplitude2beadPotential 0.0_DP
! VARIABLE COMMENT: ! Amplitude of two body potential
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)

#define WLC_P__EXCLUDE_NEIGHBORS_IN_POTENTIAL 2
! VARIABLE COMMENT: ! Amplitude of two body potential
! DEFAULTS COMMENT: !
! TYPE: INTEGER

#define WLC_P__MAX_RXN_COORD 1.0_DP
! VARIABLE COMMENT: ! Max of umbrella sampled reaction coordinate
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)

#define WLC_P__MIN_RXN_COORD 0.0_DP
! VARIABLE COMMENT: ! Min of umbrella sampled reaction coordinate
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)


! ----------------------------
!
!   Time / steps variables
!
! ---------------------------

#define WLC_P__STEPSPEREXCHANGE 6000
! VARIABLE COMMENT: ! number of steps between parallel tempering.  Was 6000000
! DEFAULTS COMMENT: ! 100 steps between parallel tempering is pretty frequent
! TYPE: INTEGER

#define WLC_P__NREPLICAEXCHANGEPERSAVEPOINT 500
! VARIABLE COMMENT: ! read teh variable name
! DEFAULTS COMMENT: ! make this large
! TYPE: INTEGER

#define WLC_P__NUMSAVEPOINTS 110
! VARIABLE COMMENT: ! total number of save points
! DEFAULTS COMMENT: !
! TYPE: INTEGER

#define WLC_P__STEPSPERSAVE 0
! VARIABLE COMMENT: ! number of simulation steps to take, BD
! DEFAULTS COMMENT: ! This is MC simulation not BD
! TYPE: INTEGER

#define WLC_P__NNOINT 10
! VARIABLE COMMENT: ! save points before turning on NNoInt
! DEFAULTS COMMENT: ! number of simulation steps before turning on interactions in Quinn's wlc_p scheduler
! TYPE: INTEGER

#define WLC_P__N_KAP_ON 10
! VARIABLE COMMENT: ! when to turn KAP energy on
! DEFAULTS COMMENT: ! turn on compression energy immediately
! TYPE: INTEGER

#define WLC_P__N_CHI_ON 10
! VARIABLE COMMENT: ! when to turn CHI energy on
! DEFAULTS COMMENT: ! turn on chi energy immediately
! TYPE: INTEGER

#define WLC_P__N_CHI_L2_ON 1000000
! VARIABLE COMMENT: ! when to turn CHI energy on
! DEFAULTS COMMENT: ! turn on chi energy immediately
! TYPE: INTEGER

#define WLC_P__N_EXTERNAL_ON 10
! VARIABLE COMMENT: ! when to turn external potential
! DEFAULTS COMMENT: ! turn on immediately
! TYPE: INTEGER

#define WLC_P__N_FIELD_ON 10
! VARIABLE COMMENT: ! when to turn applied field
! DEFAULTS COMMENT: ! turn on immediately
! TYPE: INTEGER

#define WLC_P__N_UMBRELLA_ON 10
! VARIABLE COMMENT: ! when to turn applied field
! DEFAULTS COMMENT: ! turn on immediately
! TYPE: INTEGER

#define WLC_P__NINITMCSTEPS 4000
! VARIABLE COMMENT: ! number of mc steps before starting BD
! DEFAULTS COMMENT: ! number of initilizing mc steps. 1000s x num polymers is good
! TYPE: INTEGER


#define WLC_P__MOVESPERSTEP_CRANK_SHAFT 30
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! crank shaft <default 30>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_SLIDE_MOVE 60
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! slide <default 60>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_PIVOT_MOVE 1
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! pivot <default 30>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_ROTATE_MOVE 60
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! rotate <default 60>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_FULL_CHAIN_ROTATION 5
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! full chain rotation <default 5>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_FULL_CHAIN_SLIDE 6
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! full chain slide <default 6>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_CHANGE_BINDING_STATE 20
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! bind < default 10>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_CHAIN_FLIP 0
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! filp
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_CHAIN_EXCHANGE 5
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! full chain swap < default 5>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_REPTATION 10
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! reptation <default 10>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_SUPER_REPTATION 57
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! super-reptation <default 57>
! TYPE: INTEGER

#define WLC_P__MOVESPERSTEP_SPIDER 15
! VARIABLE COMMENT: ! how many times each move is done per step
! DEFAULTS COMMENT: ! super-reptation <default 57>
! TYPE: INTEGER

#define WLC_P__PROBSINGLESWAP 0.25_dp
! VARIABLE COMMENT: ! What fraction of the time to try to change only one tail
! DEFAULTS COMMENT: ! 0< x  <1
! TYPE: LOGICAL



! --------------------------
!
!   Parallel Tempering settings
!
! --------------------------

#define WLC_P__PTON .FALSE.
! VARIABLE COMMENT: ! whether or not to parallel temper
! DEFAULTS COMMENT: ! use parallel if applicable
! TYPE: LOGICAL

# define WLC_P__ENSEMBLE_BIND .FALSE.
! VARIABLE COMMENT: ! set but not parrallel temered
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

# define WLC_P__ENSEMBLE_METH .FALSE.
! VARIABLE COMMENT: ! set but not parrallel temered
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__PT_TWIST .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper linking number (twist) by default
! TYPE: LOGICAL

#define WLC_P__PT_CHI .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper chi by default
! TYPE: LOGICAL

#define WLC_P__PT_H .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper h by default
! TYPE: LOGICAL

#define WLC_P__PT_KAP .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper kap by default
! TYPE: LOGICAL

#define WLC_P__PT_MU .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper mu by default
! TYPE: LOGICAL

#define WLC_P__PT_COUPLE .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper HP1 binding by default
! TYPE: LOGICAL

#define WLC_P__PT_MAIERSAUPE .FALSE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: ! don't parallel temper maier Saupe by default
! TYPE: LOGICAL

#define WLC_P__PT_AEF .FALSE.
! VARIABLE COMMENT: ! parallel temper over external applied field
! DEFAULTS COMMENT: ! don't parallel temper h by default
! TYPE: LOGICAL

#define WLC_P__PT_A2B .FALSE.
! VARIABLE COMMENT: ! parallel temper two body interaction
! DEFAULTS COMMENT: !
! TYPE: LOGICAL

#define WLC_P__NREPADAPT 1000
! VARIABLE COMMENT: ! number of exchange attemts between adapt
! DEFAULTS COMMENT: ! 1000 exchange attempts between adaptations
! TYPE: INTEGER

#define WLC_P__LOWERREPEXE 0.09_DP
! VARIABLE COMMENT: ! when to decrese cof spacing
! DEFAULTS COMMENT: ! TOdo: enter justification for these defaults, if any.
! TYPE: REAL(DP)

#define WLC_P__UPPERREPEXE 0.18_DP
! VARIABLE COMMENT: ! when to increase cof spacing
! DEFAULTS COMMENT: ! TOdo: fine if the only justification is "these just work"
! TYPE: REAL(DP)

#define WLC_P__LOWERCOFRAIL 0.005_DP
! VARIABLE COMMENT: ! minumum acceptable Cof
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__UPPERCOFRAIL 0.1_DP
! VARIABLE COMMENT: ! maximum acceptable Cof
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__INDSTARTREPADAPT 100000000
! VARIABLE COMMENT: Allow time for the chains to equilibrate without interaction
! DEFAULTS COMMENT: None
! TYPE: INTEGER

#define WLC_P__INDENDREPADAPT 100000000
! VARIABLE COMMENT: Stop changing values to allow for data collection
! DEFAULTS COMMENT: None
! TYPE: INTEGER

#define WLC_P__REPANNEALSPEED 0.00_DP
! VARIABLE COMMENT: ! for annealing
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__REPLICABOUNDS .TRUE.
! VARIABLE COMMENT: None
! DEFAULTS COMMENT: None
! TYPE: LOGICAL

#define WLC_P__INITIAL_MAX_S 1.4_DP
! VARIABLE COMMENT: ! The upper end of the initial values you which to PT
! DEFAULTS COMMENT:
! TYPE: REAL(DP)

! --------------------------
!
!   Available MC Moves
!
! --------------------------

#define WLC_P__MOVEON_CRANK_SHAFT 1
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! crank-shaft move
! TYPE: INTEGER

#define WLC_P__MOVEON_SLIDE_MOVE 1
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! slide move
! TYPE: INTEGER

#define WLC_P__MOVEON_PIVOT_MOVE 1
! VARIABLE COMMENT: ! pivot move
! DEFAULTS COMMENT: ! need to be able to move end of chain
! TYPE: INTEGER

#define WLC_P__MOVEON_ROTATE_MOVE 1
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! rotate move
! TYPE: INTEGER

#define WLC_P__MOVEON_FULL_CHAIN_ROTATION 0
! VARIABLE COMMENT: ! full chain rotation
! DEFAULTS COMMENT: ! DNA too long to bother
! TYPE: INTEGER

#define WLC_P__MOVEON_FULL_CHAIN_SLIDE 0
! VARIABLE COMMENT: ! full chain slide
! DEFAULTS COMMENT: ! DNA too long to bother
! TYPE: INTEGER

#define WLC_P__MOVEON_CHANGE_BINDING_STATE 1
! VARIABLE COMMENT: ! Changes A/B type
! DEFAULTS COMMENT: ! HP1 binding state
! TYPE: INTEGER

#define WLC_P__MOVEON_CHAIN_FLIP 0
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! Chain flip ! TOdo not working
! TYPE: INTEGER

#define WLC_P__MOVEON_CHAIN_EXCHANGE 0
! VARIABLE COMMENT: ! Chain exchange
! DEFAULTS COMMENT: ! DNA too long / single chr
! TYPE: INTEGER

#define WLC_P__MOVEON_REPTATION 0
! VARIABLE COMMENT: ! Reptation
! DEFAULTS COMMENT: ! Chain too long to bother
! TYPE: INTEGER

#define WLC_P__MOVEON_SUPER_REPTATION 0
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! Super Reptation
! TYPE: INTEGER

#define WLC_P__MOVEON_SPIDER 1
! VARIABLE COMMENT: ! Is the move active
! DEFAULTS COMMENT: ! Super Reptation
! TYPE: INTEGER


! ----------------------------
!
!   MC Optimization
!
! ---------------------------

#define WLC_P__PDESIRE_CRANK_SHAFT 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_SLIDE_MOVE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_PIVOT_MOVE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_ROTATE_MOVE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_FULL_CHAIN_ROTATION 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_FULL_CHAIN_SLIDE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_CHANGE_BINDING_STATE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_CHAIN_FLIP 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_CHAIN_EXCHANGE 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_REPTATION 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_SUPER_REPTATION 0.5_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__PDESIRE_SPIDER 0.25_DP
! VARIABLE COMMENT: ! desired hit rate
! DEFAULTS COMMENT: ! Target
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_CRANK_SHAFT DBLE(MIN(150,WLC_P__NB))
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_SLIDE_MOVE DBLE(MIN(150,WLC_P__NB))
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_PIVOT_MOVE DBLE(MIN(150,INT(WLC_P__NB/2.0_DP)))
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_ROTATE_MOVE NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_FULL_CHAIN_ROTATION NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_FULL_CHAIN_SLIDE NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_CHANGE_BINDING_STATE DBLE(MIN(4,WLC_P__NB))
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_CHAIN_FLIP NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_CHAIN_EXCHANGE NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_REPTATION NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXWINDOW_SUPER_REPTATION NAN
! VARIABLE COMMENT: ! Max Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_CRANK_SHAFT 30_DP
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_SLIDE_MOVE 10_DP
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: ! If this is too small equllibration will be very slow
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_PIVOT_MOVE 50_DP
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_ROTATE_MOVE NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: ! If this is too small equllibration will be very slow
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_FULL_CHAIN_ROTATION NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_FULL_CHAIN_SLIDE NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_CHANGE_BINDING_STATE 1_DP
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_CHAIN_FLIP NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_CHAIN_EXCHANGE NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_REPTATION NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINWINDOW_SUPER_REPTATION NAN
! VARIABLE COMMENT: ! Min Size of window for bead selection
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_CRANK_SHAFT 1.0_DP*PI
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_SLIDE_MOVE 0.2_DP*WLC_P__L0
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_PIVOT_MOVE 0.2_DP*PI
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_ROTATE_MOVE 0.2_DP*PI
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_FULL_CHAIN_ROTATION 0.05_DP*PI
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_FULL_CHAIN_SLIDE 0.2_DP*WLC_P__L0
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_CHANGE_BINDING_STATE NAN
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_CHAIN_FLIP NAN
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_CHAIN_EXCHANGE NAN
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_REPTATION NAN
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_SUPER_REPTATION NAN
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MINAMP_SPIDER 1.0_dp*WLC_P__L0
! VARIABLE COMMENT: ! minium amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_CRANK_SHAFT 2.0_DP*PI
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_SLIDE_MOVE 1.0_DP*WLC_P__L0
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_PIVOT_MOVE 1.0_DP*PI
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_ROTATE_MOVE 1.0_DP*PI
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_FULL_CHAIN_ROTATION 1.0_DP*PI
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_FULL_CHAIN_SLIDE 0.1_dp*WLC_P__LBOX_X
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_CHANGE_BINDING_STATE NAN
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_CHAIN_FLIP NAN
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_CHAIN_EXCHANGE NAN
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_REPTATION NAN
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_SUPER_REPTATION NAN
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__MAXAMP_SPIDER 5.0_dp*WLC_P__L0
! VARIABLE COMMENT: ! maximum amplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_CRANK_SHAFT 8.0_DP
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_SLIDE_MOVE 8.0_DP
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_PIVOT_MOVE 8.0_DP
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: None
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_ROTATE_MOVE NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! window of 1
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_FULL_CHAIN_ROTATION NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! No window
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_FULL_CHAIN_SLIDE NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! No window
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_CHANGE_BINDING_STATE NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! no amplitude
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_CHAIN_FLIP NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! no window or amplitude
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_CHAIN_EXCHANGE NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! No window or amplitude
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_REPTATION NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! window or amplitiuge
! TYPE: REAL(DP)

#define WLC_P__WINTARGET_SUPER_REPTATION NAN
! VARIABLE COMMENT: ! target for ratio of window to anmplitude
! DEFAULTS COMMENT: ! no window
! TYPE: REAL(DP)

#define WLC_P__NADAPT_CRANK_SHAFT 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_SLIDE_MOVE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_PIVOT_MOVE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_ROTATE_MOVE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_FULL_CHAIN_ROTATION 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_FULL_CHAIN_SLIDE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_CHANGE_BINDING_STATE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_CHAIN_FLIP 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_CHAIN_EXCHANGE 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_REPTATION 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_SUPER_REPTATION 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__NADAPT_SPIDER 1000
! VARIABLE COMMENT: ! Nunber of steps between adapt
! DEFAULTS COMMENT: ! adapt after at most 1000 steps
! TYPE: INTEGER

#define WLC_P__MIN_ACCEPT 0.05_DP
! VARIABLE COMMENT: ! threshold for deciding to usually not use a move
! DEFAULTS COMMENT: ! if a move succeeds < 5% of the time, start using it only every reduce_move cycles
! TYPE: REAL(DP)

#define WLC_P__REDUCE_MOVE 1
! VARIABLE COMMENT: ! whether or not to stop usuing a move when it goes below min_accept success
! DEFAULTS COMMENT: ! use moves that fall below the min_accept threshold only once every ~ times they would otherwise be used, set to one for no effect
! TYPE: INTEGER

#define WLC_P__WINTYPE 1
! VARIABLE COMMENT: ! distributionof segment size in crankshaft move (unif = 0, exp = 1)
! DEFAULTS COMMENT: ! exponential fragment sizes mix better
! TYPE: INTEGER

#define WLC_P__PROB_BIND_RESPECTING_MOVE 1.01_DP
! VARIABLE COMMENT: ! probability that we make sure move doesnt break loop
! DEFAULTS COMMENT: ! about half, only used if explicit binding turned on
! TYPE: REAL(DP)

#define WLC_P__SPIDER_LEG_LENGTH 5
! VARIABLE COMMENT: ! number of beads from hip-knee (and knee to toe)
! DEFAULTS COMMENT: ! several but not too many
! TYPE: Integer

#define WLC_P__MAX_SPIDER_LEG_LENGTH 25
! VARIABLE COMMENT: ! max number of beads from knee-toe
! DEFAULTS COMMENT:
! TYPE: Integer

#define WLC_P__SPIDER_WINDOW 30.0_DP
! VARIABLE COMMENT: ! mean of segment size distibution
! DEFAULTS COMMENT:
! TYPE: REAL(DP)

#define WLC_P__PROBABILITY_PRECALC_SPIDER 1.0_DP
! VARIABLE COMMENT: ! probability that we use precalculated spider
! DEFAULTS COMMENT: !
! TYPE: REAL(DP)