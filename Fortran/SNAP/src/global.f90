!-----------------------------------------------------------------------
!
! MODULE: global_module
!> @brief
!> Global variables for data types, file names and unit numbers, and
!> commonly used numbers
!
!-----------------------------------------------------------------------

MODULE global_module

  IMPLICIT NONE

  PUBLIC

  SAVE
!_______________________________________________________________________
!
! Numerical kinds.
!_______________________________________________________________________

  INTEGER, PARAMETER :: l_knd = KIND( .TRUE. )
  INTEGER, PARAMETER :: i_knd = SELECTED_INT_KIND( 8 )
  INTEGER, PARAMETER :: r_knd = SELECTED_REAL_KIND( 13 )
!_______________________________________________________________________
!
! File names and unit numbers.
!
! ifile       - input file name
! iunit       - input file unit number
! ofile       - output file name
! ounit       - output file unit number
!_______________________________________________________________________

  CHARACTER(LEN=64) :: ifile, ofile

  INTEGER(i_knd), PARAMETER :: iunit=10, ounit=11
!_______________________________________________________________________
!
! Commonly used numbers.
!_______________________________________________________________________

  REAL(r_knd), PARAMETER :: zero = 0.0_r_knd
  REAL(r_knd), PARAMETER :: half = 0.5_r_knd
  REAL(r_knd), PARAMETER :: one  = 1.0_r_knd
  REAL(r_knd), PARAMETER :: two  = 2.0_r_knd

  REAL(r_knd), PARAMETER :: pi = 3.14159265358979_r_knd
!_______________________________________________________________________
!_______________________________________________________________________


END MODULE global_module
