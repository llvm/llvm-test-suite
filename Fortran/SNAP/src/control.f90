!-----------------------------------------------------------------------
!
! MODULE: control_module
!> @brief
!> This module contains the variables that control SNAP's solver
!> routines. This includes the time-dependent variables. It also
!> includes some KBA scheduling variables.
!
!-----------------------------------------------------------------------

MODULE control_module

  USE global_module, ONLY: i_knd, r_knd, l_knd, zero, one

  IMPLICIT NONE

  PUBLIC

  SAVE
!_______________________________________________________________________
!
! Module Input Variables
!
! epsi     - convergence criterion
! iitm     - max inner iterations
! oitm     - max outer iterations
! timedep  - 0/1=no/yes perform a time-dependent calculation
! tf       - final time
! nsteps   - number of time steps to cover the ts -> tf range
!
! swp_typ  - 0/1=standard order/mini-KBA sweep
! multiswp - 0/1=no/yes concurrent octant mesh sweeps (corner starts)
!
! angcpy   - 1/2 copies of the time-edge angular flux
!
! it_det   - 0/1=no/yes full iteration details
! soloutp  - 0/1=no/yes print single k-plane solution to output file
! kplane   - 0/1+=default mid-plane/k-plane index to print with soloutp
! popout   - 0/1/2=no/final only/every cycle print population data to
!            output file
! fluxp    - 0/1/2=print none/scalar flux/all flux moments to file
!
! fixup    - 0/1=no/yes perform flux fixup
!_______________________________________________________________________

  INTEGER(i_knd) :: iitm=5, oitm=100, timedep=0, nsteps=1, swp_typ=0,  &
    multiswp=1, angcpy=1, it_det=0, soloutp=0, kplane=0, popout=0,     &
    fluxp=0, fixup=1

  REAL(r_knd) :: epsi=1.0E-4_r_knd, tf=zero
!_______________________________________________________________________
!
! Run-time variables
!
! dt       - time-step size
!
! tolr      - parameter, small number used for determining how to
!             compute flux error
! dfmxi(ng) - max error of inner iteration
! dfmxo     - max error of outer iteration
!
! inrdone(ng)  - logical for inners being complete
! otrdone      - logical for outers being complete
! update_ptr   - true/false update the ptr_out array
!
! ncor             - number of corners from which sweeps begin
! nops             - number of chunks a process performs per sweep
! last_oct         - last octant to be swept
! corner_sch(2,4)  - corner scheduling control array
! yzstg(4)         - KBA stage in yz plane per starting corner
! corner_loop_order(4) - multisweep corner loop priortized order
!_______________________________________________________________________

  LOGICAL(l_knd) :: otrdone, update_ptr

  LOGICAL(l_knd), ALLOCATABLE, DIMENSION(:) :: inrdone

  INTEGER(i_knd) :: ncor, nops, last_oct, corner_sch(2,4), yzstg(4),   &
    corner_loop_order(4)

  REAL(r_knd) :: dt, dfmxo

  REAL(r_knd), PARAMETER :: tolr=1.0E-12_r_knd

  REAL(r_knd), ALLOCATABLE, DIMENSION(:) :: dfmxi


  CONTAINS


  SUBROUTINE control_allocate ( ng, ndpwds, ierr )

!-----------------------------------------------------------------------
!
! Allocate control module variables.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: ng

    INTEGER(i_knd), INTENT(INOUT) :: ndpwds

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________

    ierr = 0
    ALLOCATE( dfmxi(ng), inrdone(ng), STAT=ierr )
    IF ( ierr /= 0 ) RETURN

    dfmxi = -one
    inrdone = .FALSE.
    dfmxo = -one
    otrdone = .FALSE.
    update_ptr = .FALSE.

    ndpwds = ndpwds + SIZE( dfmxi ) + SIZE( inrdone )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE control_allocate


  SUBROUTINE control_deallocate

!-----------------------------------------------------------------------
!
! Deallocate control module arrays.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________

    DEALLOCATE( dfmxi, inrdone )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE control_deallocate


END MODULE control_module
