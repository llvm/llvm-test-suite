!-----------------------------------------------------------------------
!
! MODULE: version_module
!> @brief
!> This module handles version information.
!
!-----------------------------------------------------------------------

MODULE version_module

  USE global_module, ONLY: i_knd, ounit

  IMPLICIT NONE

  PUBLIC

  SAVE
!_______________________________________________________________________
!
! SNAP release number and release date.
!_______________________________________________________________________

  INTEGER(i_knd) :: version = 112

  CHARACTER(LEN=8) :: cvers = '1.12'

  CHARACTER(LEN=10) :: vdate = '09-07-2021'
!_______________________________________________________________________
!_______________________________________________________________________


  CONTAINS


  SUBROUTINE version_print

!-----------------------------------------------------------------------
!
! Print version information.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables.
!_______________________________________________________________________

    CHARACTER(LEN=12) :: rc(3)

    INTEGER(i_knd), DIMENSION(8) :: dttm
!_______________________________________________________________________
!
!   Call intrinsics to get current date and time. Print to output file
!   information about the code.
!_______________________________________________________________________

    CALL DATE_AND_TIME (rc(1), rc(2), rc(3), dttm)

    WRITE( ounit, 111 )
    WRITE( ounit, 112 ) cvers
    WRITE( ounit, 113 ) vdate
    WRITE( ounit, FMT=114, ADVANCE='NO' ) dttm(2), dttm(3), dttm(1)
    WRITE( ounit, 115 ) dttm(5), dttm(6), dttm(7)
!_______________________________________________________________________

    111 FORMAT( 1X, 'SNAP: SN (Discrete Ordinates) Application Proxy' )
    112 FORMAT( 1X, 'Version Number..  ', A5 )
    113 FORMAT( 1X, 'Version Date..  ', A10 )
    114 FORMAT( 1X, 'Ran on ', I2, '-', I2, '-', I4 )
    115 FORMAT( ' at time ', I2, ':', I2, ':', I2 )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE version_print


END MODULE version_module
