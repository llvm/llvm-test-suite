! Check that a saved local variable is not assumed unchanged across a call
! that invokes its procedure again: all the instances of a procedure share its
! saved local variables.

module save_reentry_m
  implicit none
contains
  ! Each call increments the saved scalar through another instance of
  ! count_calls, so the loop must read it again after every call. The values
  ! are printed after the loop: a call to the I/O runtime in the loop would
  ! keep the reads in the loop by itself.
  recursive subroutine count_calls(nested)
    logical, intent(in) :: nested
    integer, save :: counter
    integer :: i, seen(4)
    if (nested) then
      counter = counter + 1
    else
      counter = 0
      do i = 1, 4
        call nest_count_calls()
        seen(i) = counter
      end do
      print '(*(I0,:,1X))', seen
    end if
  end subroutine

  subroutine nest_count_calls()
    call count_calls(.true.)
  end subroutine

  ! new_values defines its result before it reads the saved allocatable
  ! through another instance of replace_values, so the result must not be
  ! evaluated into the storage of the allocatable.
  recursive subroutine replace_values(nested)
    logical, intent(in) :: nested
    integer, allocatable, save :: values(:)
    if (nested) then
      print '(*(I0,:,1X))', values
    else
      values = [2, 4, 6]
      values = new_values(3)
      print '(*(I0,:,1X))', values
    end if
  end subroutine

  function new_values(n) result(r)
    integer, intent(in) :: n
    integer :: r(n), i
    do i = 1, n
      r(i) = 10 * i
    end do
    call replace_values(.true.)
  end function
end module

program save_reentry
  use save_reentry_m
  implicit none
  call count_calls(.false.)
  call replace_values(.false.)
end program
