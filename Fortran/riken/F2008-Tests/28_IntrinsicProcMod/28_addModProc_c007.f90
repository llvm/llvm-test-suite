! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:15.2.3.7 C SIZEOF

program main
  use iso_c_binding
  implicit none
  character(len=10) :: a(10)   ! non-interoperable

  !========================
  ! A-3 c_sizeof(x)
  ! B-1 use module
  ! C-1 not assumed-size array
  ! D-2 non-interoperable data
  !========================
  print *, c_sizeof(a)

end program

! GFORT: 28_addModProc_c007.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_addModProc_c007.f90:17:
! FLANG-SAME: error:
