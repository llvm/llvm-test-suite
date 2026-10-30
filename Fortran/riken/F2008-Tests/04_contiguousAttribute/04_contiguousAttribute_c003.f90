! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:5.3.7 CONTIGUOUS attribute
! SPEC: F2008 R533, R502

program main
  use iso_fortran_env
  implicit none

  integer :: i, j

  real(real32), target :: t(7) = [(real(i,real32),i=1,7)]
  real(real64), target :: u(0:3,0:4) = &
       reshape( [((real(i+10*j,real64), i=0,3), j=0,4)], [4,5] )

  real(real32), pointer, contiguous :: p1(:), p2(:)
  real(real64), pointer, contiguous :: q1(:,:), q2(:,:)

  !--- OK
  q1 => u(:,:)
  write(*, '(A,*(F4.0))')  'u(:,:)    =', u(:,:)
  write(*, '(A,*(F4.0))')  'q1        =', q1

  !--- test A-2, C-2  (non-contiguous for compile time check)
  q2 => u(1:3,2:3)
  write(*, '(A,*(F4.0))')  'u(1:3,2:3)=', u(1:3,2:3)
  write(*, '(A,*(F4.0))')  'q2        =', q2

end program main


! FLANG: 04_contiguousAttribute_c003.f90:26
! FLANG-SAME: error:

! GFORT: 04_contiguousAttribute_c003.f90:26
! GFORT-NOT: .f90
! GFORT: Error:

