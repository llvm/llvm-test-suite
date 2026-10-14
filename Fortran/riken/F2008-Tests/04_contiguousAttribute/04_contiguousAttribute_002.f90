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

  !--- test A-2, C-1
  p1 => t
  write(*, '(A,*(F4.0))')  't     =', t
  write(*, '(A,*(F4.0))')  'p1    =', p1

  p2 => t(3:6)
  write(*, '(A,*(F4.0))')  't(3:6)=', t(3:6)
  write(*, '(A,*(F4.0))')  'p2    =', p2

  q1 => u(:,:)
  write(*, '(A,*(F4.0))')  'u(:,:)    =', u(:,:)
  write(*, '(A,*(F4.0))')  'q1        =', q1

  q2 => u(0:3,2:3)
  write(*, '(A,*(F4.0))')  'u(0:3,2:3)=', u(0:3,2:3)
  write(*, '(A,*(F4.0))')  'q2        =', q2

end program main
