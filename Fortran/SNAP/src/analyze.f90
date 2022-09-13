!-----------------------------------------------------------------------
!
! MODULE: analyze_module
!> @brief
!> This module contains subroutines for analyzing data.
!
!-----------------------------------------------------------------------

MODULE analyze_module

  USE global_module, ONLY: i_knd, r_knd, ounit

  USE control_module, ONLY: timedep

  USE geom_module, ONLY: dx, dy, dz, nx, ny, nz, ndimen

  USE data_module, ONLY: v, ng

  USE solvar_module, ONLY: flux0, pop

  USE plib_module, ONLY: iproc, root, comm_snap, rtsum

  IMPLICIT NONE

  PUBLIC

  SAVE


  CONTAINS


  SUBROUTINE analyze_pop_calc ( cy, time )

!-----------------------------------------------------------------------
!
! Compute the neutron spectrum: the population per group integrated over
! volume.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: cy

    REAL(r_knd), INTENT(IN) :: time
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: g

    REAL(r_knd) :: vol

    REAL(r_knd), DIMENSION(nx,ny,nz,ng) :: tmp
!_______________________________________________________________________
!
!   Integrate flux over volume of local spatial sub-domain
!_______________________________________________________________________

    vol = dx
    IF ( ndimen > 1 ) THEN
      vol = vol*dy
      IF ( ndimen > 2 ) vol = vol*dz
    END IF
    tmp = vol*flux0

    DO g = 1, ng
      pop(g) = SUM( tmp(:,:,:,g) )
    END DO
!_______________________________________________________________________
!
!   Integrate over global volume with MPI reduction (to root only, not
!   all_reduce)
!_______________________________________________________________________

    CALL rtsum ( pop, ng, comm_snap, root )
!_______________________________________________________________________
!
!   Divide volume integrated flux by velocity to get particle density
!   per unit energy. Print out results. Note, only root process has
!   correct value because the reduction is not global. Can easily
!   change this though.
!_______________________________________________________________________

    IF ( iproc == root ) THEN

      IF ( timedep == 1 ) THEN
        pop = pop/v
      ELSE
        WRITE( ounit, 352 )
      END IF

      WRITE( ounit, 350 ) cy, time
      DO g = 1, ng
        WRITE( ounit, 351 ) g, pop(g)
      END DO
      WRITE( ounit, * )

    END IF
!_______________________________________________________________________

    350 FORMAT( 2X, 'Particle spectrum, cycle (time)', I4, ' ( ',      &
                ES11.4, ' )' )
    351 FORMAT( 8X, I4, ES13.6 )
    352 FORMAT( 2X, 'Static calc: v(g) not set. Use dummy value of 1.' )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE analyze_pop_calc


END MODULE analyze_module
