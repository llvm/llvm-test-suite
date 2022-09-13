!-----------------------------------------------------------------------
!
! MODULE: dealloc_module
!> @brief
!> This module controls the deallocation process of run-time arrays.
!
!-----------------------------------------------------------------------

MODULE dealloc_module

  USE global_module, ONLY: i_knd

  USE sn_module, ONLY: sn_deallocate

  USE data_module, ONLY: data_deallocate

  USE mms_module, ONLY: mms_deallocate

  USE geom_module, ONLY: geom_deallocate

  USE solvar_module, ONLY: solvar_deallocate

  USE control_module, ONLY: control_deallocate

  IMPLICIT NONE

  PUBLIC


  CONTAINS


  SUBROUTINE dealloc_input ( flg )

!-----------------------------------------------------------------------
!
! Call for the data deallocation from individual deallocation
! subroutines. Covers the allocations from input.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: flg
!_______________________________________________________________________

    CALL sn_deallocate

    IF ( flg > 1 ) CALL data_deallocate

    IF ( flg > 2 ) CALL control_deallocate

    IF ( flg > 3 ) CALL mms_deallocate
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE dealloc_input


  SUBROUTINE dealloc_solve ( swp_typ, flg )

!-----------------------------------------------------------------------
!
! Call for the data deallocation from individual deallocation
! subroutines. Covers the allocations from input.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: swp_typ, flg
!_______________________________________________________________________

    CALL geom_deallocate ( swp_typ )

    IF ( flg > 1 ) CALL solvar_deallocate
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE dealloc_solve


END MODULE dealloc_module
