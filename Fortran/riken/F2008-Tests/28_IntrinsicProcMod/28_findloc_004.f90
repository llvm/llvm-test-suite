! SPEC: F2008 13.7.61

program main
  implicit none
  integer :: a(3) = [1,2,3]

  print *, findloc(a, 2, mask=.true.)

end program
