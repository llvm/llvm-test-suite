!-----------------------------------------------------------------------
!
! MODULE: time_module
!> @brief
!> This module contains the variables that measure SNAP execution
!> times for different pieces of code and the subroutine used to get the
!> time. It also has the timing summary print.
!
!-----------------------------------------------------------------------

MODULE time_module

  USE global_module, ONLY: r_knd, i_knd, zero, ounit

#ifdef MPI
  USE mpi
#endif

  IMPLICIT NONE

  PUBLIC

  SAVE
!_______________________________________________________________________
!
! Run-time variables
!
! tsnap    - total SNAP run time
! tparset  - parallel environment setup time
! tinp     - input run time
! tset     - setup run time
! tslv     - total solution run time
! tparam   - time for setting up solve parameters
! totrsrc  - time for outer source computations
! tinners  - total time spent on inner iterations
! tinrsrc  - time for inner source computations
! tsweeps  - time for transport sweeps, including angular sourc compute
! tinrmisc - time for miscellaneous inner ops
! tslvmisc - time for miscellaneous solution ops
! tout     - output run time
! tgrind   - transport grind time
!_______________________________________________________________________

  REAL(r_knd) :: tsnap=zero, tparset=zero, tinp=zero, tset=zero,       &
    tslv=zero, tparam=zero, totrsrc=zero, tinners=zero, tinrsrc=zero,  &
    tsweeps=zero, tinrmisc=zero, tslvmisc=zero, tout=zero, tgrind=zero


  CONTAINS


  SUBROUTINE wtime ( time )

!-----------------------------------------------------------------------
!
! Get the current time
!
!-----------------------------------------------------------------------

    REAL(r_knd), INTENT(OUT) :: time
!_______________________________________________________________________

#ifdef MPI
    time = MPI_WTIME()
#else
    CALL CPU_TIME ( time )
#endif
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE wtime


  SUBROUTINE time_summ

!-----------------------------------------------------------------------
!
! Print the timing summary to the output file.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!  Local variables
!_______________________________________________________________________

    CHARACTER(LEN=1) :: star='*'

    INTEGER(i_knd) :: i
!_______________________________________________________________________

    tinrmisc = tinners - ( tinrsrc + tsweeps )
    tslvmisc = tslv - ( tparam + totrsrc + tinners )

    WRITE( ounit, 401 ) ( star, i = 1, 80 )
    WRITE( ounit, 402 )
    WRITE( ounit, 403 ) tparset
    WRITE( ounit, 404 ) tinp
    WRITE( ounit, 405 ) tset
    WRITE( ounit, 406 ) tslv
    WRITE( ounit, 407 ) tparam
    WRITE( ounit, 408 ) totrsrc
    WRITE( ounit, 409 ) tinners
    WRITE( ounit, 410 ) tinrsrc
    WRITE( ounit, 411 ) tsweeps
    WRITE( ounit, 412 ) tinrmisc
    WRITE( ounit, 413 ) tslvmisc
    WRITE( ounit, 414 ) tout
!_______________________________________________________________________

    401 FORMAT( 10X, 'keyword Timing Summary', /, 80A, / )
    402 FORMAT( 2X, 'Code Section', T41, 'Time (seconds)', /,          &
                1X, '**************', T40, '****************' )
    403 FORMAT( 4X, 'Parallel Setup', T41, ES11.4 )
    404 FORMAT( 4X, 'Input', T41, ES11.4 )
    405 FORMAT( 4X, 'Setup', T41, ES11.4 )
    406 FORMAT( 4X, 'Solve', T41, ES11.4 )
    407 FORMAT( 7X, 'Parameter Setup', T41, ES11.4 )
    408 FORMAT( 7X, 'Outer Source', T41, ES11.4 )
    409 FORMAT( 7X, 'Inner Iterations', T41, ES11.4 )
    410 FORMAT( 10X, 'Inner Source', T41, ES11.4 )
    411 FORMAT( 10X, 'Transport Sweeps', T41, ES11.4 )
    412 FORMAT( 10X, 'Inner Misc Ops', T41, ES11.4 )
    413 FORMAT( 7X, 'Solution Misc Ops', T41, ES11.4 )
    414 FORMAT( 4X, 'Output', T41, ES11.4 )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE time_summ


END MODULE time_module
