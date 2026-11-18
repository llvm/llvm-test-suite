! SPEC: F2008:13.7.128 PARITY

program main
  implicit none
  logical :: a(4) = [.true., .true., .true., .false.]
  logical :: b(3,3,3)
  logical :: r
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
  ! B-1 no dim
  ! Check if result matches .NEQV.
  ! ====================
  r = a(1)
  do i = 2, 4
    r = r .neqv. a(i)
  end do
  write (*,*) "neqv =", r
  write (*,*) "parity =", parity(a)
   
  ! ====================
  ! A-1 logical array
  ! B-2 1 <= dim <= rank
  ! ====================
  write (*,*) parity(b, dim=1)
  write (*,*) parity(b, dim=2)
  write (*,*) parity(b, dim=3)

end program
