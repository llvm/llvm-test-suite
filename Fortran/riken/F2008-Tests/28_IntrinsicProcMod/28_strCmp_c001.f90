! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.95 LGE

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')
  integer, parameter :: ucs4 = selected_char_kind('ISO_10646')

  character(kind=ucs4, len=3)  :: a = 'ONE'
  character(kind=ascii, len=3) :: b = 'TWO'

  !====================
  ! A-1 LGE
  ! B-2 ucs4
  ! C-1 ascii
  ! different character set
  !====================
  print *, "LGE('ONE','TWO') =", lge(a, b)

end program

! GFORT: 28_strCmp_c001.f90:21:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_strCmp_c001.f90:21:
! FLANG-SAME: error:
