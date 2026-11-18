! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.15 IOSTAT INQUIRE INTERNAL UNIT
  
program main
  implicit none

  ! ====================
  ! D-1
  ! E-2
  ! ====================
  print *, iostat_inquire_internal_unit

end program main

! FLANG: 28_constants_c009.f90:13:
! FLANG-SAME: error:

! GFORT: 28_constants_c009.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
