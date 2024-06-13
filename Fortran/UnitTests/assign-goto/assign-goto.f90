subroutine s(x)
  integer :: x
  assign 222 to x
  goto x
222 continue
end subroutine s

program test
  integer :: a
  call s(a)
end program test
