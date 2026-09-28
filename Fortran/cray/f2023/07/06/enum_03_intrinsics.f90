! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of the intrinsic functions that are defined for
! arguments of enumeration type.
!
! Standard references exercised by this test:
!   16.9.96  HUGE (X)          if X is of enumeration type, the result has the
!                              value of the last enumerator in the type
!                              definition; HUGE is an inquiry function, so the
!                              argument may be a scalar or an array and its
!                              value need not be defined
!   16.9.151 NEXT (A [,STAT])  elemental; if A is the last enumerator the
!                              result is A and STAT is assigned a processor
!                              dependent positive value, otherwise the result
!                              is the next enumerator and STAT is assigned
!                              zero
!   16.9.164 PREVIOUS (A[,STAT]) elemental; if A is the first enumerator the
!                              result is A and STAT is assigned a processor
!                              dependent positive value, otherwise the result
!                              is the preceding enumerator and STAT is
!                              assigned zero
!   16.9.110 Case (v)          INT (A) is the ordinal position of A
!   16.9.139 MERGE             any type, used here to guard a NEXT/PREVIOUS
!
! NOTE on STAT: 16.9.151 and 16.9.164 state that if STAT would have been
! assigned a nonzero value but is not present, error termination is initiated.
! This test therefore supplies STAT whenever the argument can be the last
! (NEXT) or first (PREVIOUS) enumerator, and omits STAT only where the
! argument is known not to be at that end of the type.
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_intrin_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  enumeration type :: pair_type
    enumerator :: first_of_two, second_of_two
  end enumeration type pair_type

  enumeration type :: solo
    enumerator :: only_value
  end enumeration type solo

  integer :: nfail = 0

contains

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_03: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_03: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  ! 16.9.96: HUGE is an inquiry function, so a dummy argument whose value is
  ! undefined, and an assumed-shape array, are both valid arguments.
  function last_of(dummy) result(res)
    type(v_value), intent(in) :: dummy
    type(v_value) :: res
    res = huge(dummy)
  end function last_of

  function last_of_array(dummy) result(res)
    type(v_value), intent(in) :: dummy(:)
    type(v_value) :: res
    res = huge(dummy)
  end function last_of_array

end module enum_intrin_mod

program enum_03_intrinsics
  use enum_intrin_mod
  implicit none

  type(v_value) :: x, y, z, nz
  type(v_value) :: undefined_value
  type(v_value) :: arr(4) = [v_one, v_two, v_three, v_four]
  type(v_value) :: res(4)
  type(pair_type) :: p
  type(solo) :: s
  integer :: stat, stats(4)
  integer :: i, ordinals(4), count_visited

  ! 10.1.12 (7): HUGE of an enumeration type is a constant expression.
  type(v_value), parameter :: last_v = huge(v_one)

  ! --- 16.9.96 HUGE: the last enumerator of the type.
  call check_int(int(huge(v_one)), 4, 'HUGE of an enumerator')
  call check_true(huge(v_one) == v_four, 'HUGE is v_four')
  call check_true(huge(v_four) == v_four, 'HUGE of the last enumerator')
  call check_true(huge(v_value(2)) == v_four, 'HUGE of a constructor value')
  call check_int(int(last_v), 4, 'HUGE in a constant expression')

  x = v_two
  call check_true(huge(x) == v_four, 'HUGE of a variable')

  ! HUGE is an inquiry function; the argument value is not required.
  call check_true(huge(undefined_value) == v_four, 'HUGE of an undefined value')

  ! The result is scalar even when the argument is an array.
  call check_true(huge(arr) == v_four, 'HUGE of an array is scalar')
  call check_true(last_of(x) == v_four, 'HUGE of a dummy argument')
  call check_true(last_of_array(arr) == v_four, 'HUGE of an assumed-shape array')

  ! HUGE applies to every enumeration type independently.
  call check_int(int(huge(first_of_two)), 2, 'HUGE of a two-value type')
  call check_int(int(huge(only_value)), 1, 'HUGE of a one-value type')

  ! --- 16.9.151 NEXT: the following enumerator.
  call check_true(next(v_one) == v_two, 'NEXT (v_one)')
  call check_true(next(v_two) == v_three, 'NEXT (v_two)')
  call check_true(next(v_three) == v_four, 'NEXT (v_three)')
  call check_int(int(next(v_one)), 2, 'ordinal of NEXT (v_one)')

  ! With STAT present and the argument not the last enumerator, STAT is zero.
  stat = -1
  y = next(v_one, stat)
  call check_true(y == v_two, 'NEXT with STAT result')
  call check_int(stat, 0, 'NEXT STAT for a non-final value')

  ! With the last enumerator the result is the argument and STAT is positive.
  stat = -1
  y = next(v_four, stat)
  call check_true(y == v_four, 'NEXT of the last enumerator is itself')
  call check_true(stat > 0, 'NEXT STAT for the last enumerator is positive')

  stat = -1
  y = next(huge(v_one), stat)
  call check_true(y == huge(v_one), 'NEXT of HUGE is HUGE')
  call check_true(stat > 0, 'NEXT STAT for HUGE is positive')

  ! A one-value type is both the first and the last enumerator.
  stat = -1
  s = next(only_value, stat)
  call check_int(int(s), 1, 'NEXT of the only enumerator')
  call check_true(stat > 0, 'NEXT STAT for the only enumerator')

  ! --- 16.9.164 PREVIOUS: the preceding enumerator.
  call check_true(previous(v_four) == v_three, 'PREVIOUS (v_four)')
  call check_true(previous(v_three) == v_two, 'PREVIOUS (v_three)')
  call check_true(previous(v_two) == v_one, 'PREVIOUS (v_two)')
  call check_int(int(previous(v_four)), 3, 'ordinal of PREVIOUS (v_four)')

  stat = -1
  y = previous(v_three, stat)
  call check_true(y == v_two, 'PREVIOUS with STAT result')
  call check_int(stat, 0, 'PREVIOUS STAT for a non-initial value')

  stat = -1
  y = previous(v_one, stat)
  call check_true(y == v_one, 'PREVIOUS of the first enumerator is itself')
  call check_true(stat > 0, 'PREVIOUS STAT for the first enumerator is positive')

  stat = -1
  p = previous(first_of_two, stat)
  call check_int(int(p), 1, 'PREVIOUS of the first of two')
  call check_true(stat > 0, 'PREVIOUS STAT for the first of two')

  ! --- NEXT and PREVIOUS are inverses away from the ends of the type.
  do i = 2, 3
    x = v_value(i)
    call check_true(previous(next(x)) == x, 'PREVIOUS (NEXT (x)) == x')
    call check_true(next(previous(x)) == x, 'NEXT (PREVIOUS (x)) == x')
  end do

  ! Repeated application walks the ordinal positions one at a time.
  x = v_one
  do i = 2, 4
    x = next(x)
    call check_int(int(x), i, 'NEXT advances one ordinal position')
  end do
  do i = 3, 1, -1
    x = previous(x)
    call check_int(int(x), i, 'PREVIOUS retreats one ordinal position')
  end do

  ! --- The enumeration walk of the 7.6.2 NOTE, with STAT supplied so that the
  ! final NEXT does not initiate error termination (16.9.151).
  count_visited = 0
  z = v_value(1)
  do
    count_visited = count_visited + 1
    ordinals(count_visited) = int(z)
    if (z == huge(z)) then
      call check_int(count_visited, 4, 'HUGE reached on the last iteration')
    end if
    nz = next(z, stat)
    if (z == nz) then
      call check_true(stat > 0, 'walk terminates with a positive STAT')
      exit
    end if
    call check_int(stat, 0, 'walk STAT is zero before the end')
    z = nz
  end do
  call check_int(count_visited, 4, 'every enumerator visited once')
  call check_true(all(ordinals == [1, 2, 3, 4]), 'walk visits ordinals in order')

  ! --- NEXT and PREVIOUS are elemental (16.9.151 p2, 16.9.164 p2).
  res = next(arr, stats)
  call check_true(all(int(res) == [2, 3, 4, 4]), 'elemental NEXT results')
  call check_true(all(stats(1:3) == 0), 'elemental NEXT STAT zeros')
  call check_true(stats(4) > 0, 'elemental NEXT STAT for the last value')

  res = previous(arr, stats)
  call check_true(all(int(res) == [1, 1, 2, 3]), 'elemental PREVIOUS results')
  call check_true(stats(1) > 0, 'elemental PREVIOUS STAT for the first value')
  call check_true(all(stats(2:4) == 0), 'elemental PREVIOUS STAT zeros')

  ! An array section is an equally valid elemental argument.
  res(1:3) = next(arr(1:3))
  call check_true(all(int(res(1:3)) == [2, 3, 4]), 'elemental NEXT of a section')

  ! --- 16.9.110 Case (v) INT is elemental over an array of enumeration type.
  call check_true(all(int(arr) == [1, 2, 3, 4]), 'elemental INT')
  call check_int(sum(int(arr)), 10, 'INT results used arithmetically')

  ! --- The intrinsics compose with MERGE and with the relational operators.
  x = v_four
  y = merge(x, next(x, stat), x == huge(x))
  call check_true(y == v_four, 'MERGE guarding NEXT at the end of the type')

  x = v_one
  y = merge(x, previous(x, stat), x == v_value(1))
  call check_true(y == v_one, 'MERGE guarding PREVIOUS at the start')

  if (nfail == 0) then
    print '(A)', 'PASS enum_03_intrinsics'
  else
    write (error_unit, '(A,I0,A)') 'enum_03: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enum_03_intrinsics
