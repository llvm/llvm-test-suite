! Check that a saved local variable is not assumed unchanged across a call
! that invokes its procedure again: all the instances of a procedure share its
! saved local variables.

module save_reentry_m
  implicit none
contains
  ! The loop reads the saved scalar after each call, and each call increments
  ! it through another instance of count_calls.
  recursive subroutine count_calls(nested, total)
    logical, intent(in) :: nested
    integer, intent(out) :: total
    integer, save :: counter
    integer :: i
    total = 0
    if (nested) then
      counter = counter + 1
      return
    end if
    counter = 0
    do i = 1, 4
      call nest_count_calls()
      total = total + counter
    end do
  end subroutine

  subroutine nest_count_calls()
    integer :: unused
    call count_calls(.true., unused)
  end subroutine

  ! new_values defines its result before it reads the saved allocatable
  ! through another instance of replace_values, so the result must not be
  ! evaluated into the storage of the allocatable.
  recursive subroutine replace_values(nested, checksum)
    logical, intent(in) :: nested
    integer, intent(out) :: checksum
    integer, allocatable, save :: values(:)
    if (nested) then
      checksum = sum(values)
      return
    end if
    values = [2, 4, 6]
    values = new_values(3)
    checksum = sum(values)
  end subroutine

  function new_values(n) result(r)
    integer, intent(in) :: n
    integer :: r(n), old_sum, i
    do i = 1, n
      r(i) = 10 * i
    end do
    call replace_values(.true., old_sum)
    r = r + old_sum
  end function
end module

program save_reentry
  use save_reentry_m
  implicit none
  integer :: result

  ! counter is 1, 2, 3 and 4 after the calls.
  call count_calls(.false., result)
  if (result /= 10) error stop 1

  ! values is [2, 4, 6] when new_values reads it, so the new values are
  ! [22, 32, 42].
  call replace_values(.false., result)
  if (result /= 96) error stop 2

  print '(A)', 'PASS'
end program
