! SPEC: F2008:13.8.2.17 LOGICAL KINDS
  
program main
  use iso_fortran_env
  implicit none

  integer :: i
  integer :: x(1), y(1)
  logical :: flg = .true.

  ! ====================
  ! C-4
  ! E-1
  ! ====================

  do i = 1, size(logical_kinds)
    if (logical_kinds(i) <= 0) then
      flg = .false.
    else
      x = findloc(logical_kinds, logical_kinds(i))
      y = findloc(logical_kinds, logical_kinds(i), back=.true.)
      if (x(1) /= y(1)) then
        ! Multiple definitions
        flg = .false.
      end if
    end if
  end do

  if (flg) then
      print *, "logical_kinds: OK"
  else
      print *, "logical_kinds: NG"
  end if

end program main
