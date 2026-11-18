! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.96 LGT

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')
  integer, parameter :: ucs4 = selected_char_kind('ISO_10646')

  character(kind=ascii, len=3)  :: a = 'ONE'
  character(kind=ucs4, len=3) :: b = 'TWO'

  !====================
  ! A-2 LGT
  ! B-1 ascii
  ! C-2 ucs4
  ! different character set
  !====================
  print *, "LGT('ONE','TWO') =", lgt(a, b)

end program

! GFORT: 28_strCmp_c006.f90:21:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_strCmp_c006.f90:21:
! FLANG-SAME: error:
