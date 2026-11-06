! SPEC: F2008 R1001, R1002, R1005, C1002

program main
  implicit none
  integer :: a, b, c, d, e, f, g

  open(10, file='data.txt')
  read(10, '(*(I2 /, /, I2))') a, b, c, d, e, f, g

  print *, "a =", a
  print *, "b =", b
  print *, "c =", c
  print *, "d =", d
  print *, "e =", e
  print *, "f =", f
  print *, "g =", g

  close(10)
end program main
