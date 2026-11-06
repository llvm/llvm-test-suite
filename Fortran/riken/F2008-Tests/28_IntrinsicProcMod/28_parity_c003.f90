! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.128 PARITY

program main
  implicit none
  logical :: b(3,3,3)
  integer :: i

  ! b =
  ! T   T   T
  ! T   F   T
  ! T   T   F
  b = .true.
  do i = 1, 3
    b(2,2,i) = .false.
    b(3,3,i) = .false.
  end do

  ! ====================
  ! A-1 logical array
  ! B-3 dim = 0
  ! ====================
  write (*,*) "parity =", parity(b, dim=0)
   
end program

! GFORT: 28_parity_c003.f90:25:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_parity_c003.f90:25:
! FLANG-SAME: error:
