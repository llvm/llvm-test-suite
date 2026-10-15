! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of procedures whose dummy arguments or results
! are of enumeration type.
!
! Standard references exercised by this test:
!   7.6.2 p4            two data entities of enumeration type have the same
!                       type if they are declared with reference to the same
!                       enumeration type definition; this is what makes the
!                       generic references below unambiguous and is what
!                       argument association requires (15.5.2.4)
!   7.3.2.2 p2          an enumeration-type-spec may specify the type of a
!                       function result
!   15.5.2.4            an actual argument and its dummy argument shall have
!                       the same declared type
!   15.8                elemental procedures with dummy arguments of
!                       enumeration type
!   10.2.1.2 Table 10.8 intrinsic assignment from the same enumeration type
!   16.9.96/151/164     HUGE, NEXT, and PREVIOUS applied to dummy arguments
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_proc_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  enumeration type :: w_value
    enumerator :: w1, w2, w3, w4, w5, wendsentinel
  end enumeration type w_value

  ! 7.6.2 p4: the two enumeration types are distinct types, so the specific
  ! procedures of this generic interface are distinguishable by their dummy
  ! argument types.
  interface ordinal_of
    module procedure ordinal_of_v
    module procedure ordinal_of_w
  end interface ordinal_of

  integer :: nfail = 0

contains

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_07: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_07: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  ! --- Specific procedures of the generic interface.
  integer function ordinal_of_v(a)
    type(v_value), intent(in) :: a
    ordinal_of_v = int(a)
  end function ordinal_of_v

  integer function ordinal_of_w(a)
    type(w_value), intent(in) :: a
    ordinal_of_w = 100 + int(a)
  end function ordinal_of_w

  ! --- INTENT (IN), INTENT (OUT), and INTENT (INOUT) dummy arguments.
  subroutine set_to(a, ordinal)
    type(v_value), intent(out) :: a
    integer, intent(in) :: ordinal
    a = v_value(ordinal)
  end subroutine set_to

  subroutine advance(a, stat)
    type(v_value), intent(inout) :: a
    integer, intent(out) :: stat
    a = next(a, stat)
  end subroutine advance

  subroutine copy_value(from, to)
    type(v_value), intent(in) :: from
    type(v_value), intent(out) :: to
    to = from
  end subroutine copy_value

  ! --- A function result of enumeration type (7.3.2.2 p2).
  function first_value() result(res)
    type(v_value) :: res
    res = v_value(1)
  end function first_value

  function last_value() result(res)
    type(v_value) :: res
    res = huge(res)
  end function last_value

  ! The result type may also be given on the FUNCTION statement.
  type(v_value) function clamp_to(a, limit)
    type(v_value), intent(in) :: a, limit
    if (a > limit) then
      clamp_to = limit
    else
      clamp_to = a
    end if
  end function clamp_to

  ! --- A PURE function with an enumeration dummy argument and result.
  pure function successor_or_self(a) result(res)
    type(v_value), intent(in) :: a
    type(v_value) :: res
    integer :: stat
    res = next(a, stat)
  end function successor_or_self

  ! --- An ELEMENTAL function (15.8).
  elemental function shifted(a, by) result(res)
    type(v_value), intent(in) :: a
    integer, intent(in) :: by
    type(v_value) :: res
    integer :: target_ordinal
    target_ordinal = int(a) + by
    if (target_ordinal < 1) target_ordinal = 1
    if (target_ordinal > int(huge(a))) target_ordinal = int(huge(a))
    res = v_value(target_ordinal)
  end function shifted

  ! --- An ELEMENTAL subroutine with an INTENT (OUT) enumeration argument.
  elemental subroutine to_ordinal(a, ordinal)
    type(v_value), intent(in) :: a
    integer, intent(out) :: ordinal
    ordinal = int(a)
  end subroutine to_ordinal

  ! --- Explicit-shape, assumed-shape, and assumed-size array arguments.
  integer function sum_explicit(a, n)
    integer, intent(in) :: n
    type(v_value), intent(in) :: a(n)
    integer :: i
    sum_explicit = 0
    do i = 1, n
      sum_explicit = sum_explicit + int(a(i))
    end do
  end function sum_explicit

  integer function sum_assumed_shape(a)
    type(v_value), intent(in) :: a(:)
    sum_assumed_shape = sum(int(a))
  end function sum_assumed_shape

  integer function sum_assumed_size(a, n)
    integer, intent(in) :: n
    type(v_value), intent(in) :: a(*)
    integer :: i
    sum_assumed_size = 0
    do i = 1, n
      sum_assumed_size = sum_assumed_size + int(a(i))
    end do
  end function sum_assumed_size

  subroutine fill_descending(a)
    type(v_value), intent(out) :: a(:)
    integer :: i
    do i = 1, size(a)
      a(i) = v_value(size(a) - i + 1)
    end do
  end subroutine fill_descending

  ! --- An OPTIONAL dummy argument of enumeration type.
  integer function ordinal_or_default(a)
    type(v_value), intent(in), optional :: a
    if (present(a)) then
      ordinal_or_default = int(a)
    else
      ordinal_or_default = 0
    end if
  end function ordinal_or_default

  ! --- An allocatable and a pointer dummy argument.
  subroutine make_array(a, n)
    type(v_value), allocatable, intent(out) :: a(:)
    integer, intent(in) :: n
    integer :: i
    allocate (a(n))
    do i = 1, n
      a(i) = v_value(i)
    end do
  end subroutine make_array

  subroutine bump_through_pointer(p)
    type(v_value), pointer, intent(in) :: p
    integer :: stat
    p = next(p, stat)
  end subroutine bump_through_pointer

  ! --- A recursive procedure carrying an enumeration value.
  recursive integer function count_down(a) result(res)
    type(v_value), intent(in) :: a
    integer :: stat
    type(v_value) :: prev
    prev = previous(a, stat)
    if (stat /= 0) then
      res = 1
    else
      res = 1 + count_down(prev)
    end if
  end function count_down

  ! --- A procedure with a dummy argument of a derived type that has
  ! components of enumeration type.
  subroutine swap_pair(v, w)
    type(v_value), intent(inout) :: v
    type(w_value), intent(inout) :: w
    type(v_value) :: tv
    type(w_value) :: tw
    tv = v
    tw = w
    v = v_value(int(tw) - 2)
    w = w_value(int(tv) + 2)
  end subroutine swap_pair

end module enum_proc_mod

program enum_07_procedures
  use enum_proc_mod
  implicit none

  type(v_value) :: a, b
  type(v_value) :: arr(4) = [v_one, v_two, v_three, v_four]
  type(v_value) :: out(4)
  type(v_value), target :: tgt
  type(v_value), pointer :: ptr
  type(v_value), allocatable :: alloc(:)
  type(w_value) :: w
  integer :: ordinals(4)
  integer :: stat, i

  ! --- Generic resolution by enumeration type (7.6.2 p4).
  call check_int(ordinal_of(v_three), 3, 'generic resolved to the v specific')
  call check_int(ordinal_of(w3), 103, 'generic resolved to the w specific')
  call check_int(ordinal_of(v_value(4)), 4, 'generic with a constructor actual')
  call check_int(ordinal_of(huge(w1)), 106, 'generic with HUGE as the actual')

  ! --- INTENT (OUT) and INTENT (INOUT).
  call set_to(a, 2)
  call check_int(int(a), 2, 'INTENT (OUT) dummy argument')

  call advance(a, stat)
  call check_int(int(a), 3, 'INTENT (INOUT) dummy argument')
  call check_int(stat, 0, 'STAT from the advancing procedure')

  a = v_four
  call advance(a, stat)
  call check_int(int(a), 4, 'INTENT (INOUT) at the last enumerator')
  call check_true(stat > 0, 'STAT at the last enumerator')

  call copy_value(v_two, b)
  call check_int(int(b), 2, 'expression actual to an INTENT (IN) dummy')

  ! --- Function results of enumeration type.
  call check_true(first_value() == v_one, 'function result is the first value')
  call check_true(last_value() == v_four, 'function result is the last value')
  call check_int(int(first_value()), 1, 'INT of a function result')
  call check_true(clamp_to(v_four, v_two) == v_two, 'clamped function result')
  call check_true(clamp_to(v_one, v_three) == v_one, 'unclamped function result')
  call check_true(successor_or_self(v_one) == v_two, 'PURE function result')
  call check_true(successor_or_self(v_four) == v_four, 'PURE function at the end')

  ! A function reference of enumeration type is usable as an actual argument,
  ! in a relational operation, and as a SELECT CASE expression.
  call check_int(ordinal_of(first_value()), 1, 'function result as an actual')
  call check_true(first_value() < last_value(), 'function results compared')
  select case (last_value())
  case (v_four)
    call check_true(.true., 'function result as a case expression')
  case default
    call check_true(.false., 'function result as a case expression')
  end select

  ! --- Elemental procedures (15.8).
  out = shifted(arr, 1)
  call check_true(all(int(out) == [2, 3, 4, 4]), 'elemental function on an array')

  out = shifted(arr, -2)
  call check_true(all(int(out) == [1, 1, 1, 2]), 'elemental function clamped low')

  out = shifted(v_two, [0, 1, 2, 3])
  call check_true(all(int(out) == [2, 3, 4, 4]), 'elemental with a scalar actual')

  call check_true(shifted(v_one, 2) == v_three, 'elemental called with scalars')

  call to_ordinal(arr, ordinals)
  call check_true(all(ordinals == [1, 2, 3, 4]), 'elemental subroutine')

  ! --- Array dummy arguments.
  call check_int(sum_explicit(arr, 4), 10, 'explicit-shape array argument')
  call check_int(sum_assumed_shape(arr), 10, 'assumed-shape array argument')
  call check_int(sum_assumed_shape(arr(2:3)), 5, 'array section actual')
  call check_int(sum_assumed_size(arr, 4), 10, 'assumed-size array argument')
  call check_int(sum_assumed_shape([v_four, v_four]), 8, &
      'array constructor actual')

  call fill_descending(out)
  call check_true(all(int(out) == [4, 3, 2, 1]), 'INTENT (OUT) array argument')

  ! --- OPTIONAL dummy arguments.
  call check_int(ordinal_or_default(v_three), 3, 'present optional argument')
  call check_int(ordinal_or_default(), 0, 'absent optional argument')

  ! --- Allocatable and pointer dummy arguments.
  call make_array(alloc, 4)
  call check_true(allocated(alloc), 'allocatable argument was allocated')
  call check_true(all(int(alloc) == [1, 2, 3, 4]), 'allocatable argument values')
  call check_int(sum_assumed_shape(alloc), 10, 'allocatable actual argument')
  deallocate (alloc)

  tgt = v_two
  ptr => tgt
  call bump_through_pointer(ptr)
  call check_int(int(tgt), 3, 'pointer dummy argument updates the target')
  call check_true(associated(ptr, tgt), 'pointer remains associated')

  ! --- Recursion carrying an enumeration value.
  call check_int(count_down(v_one), 1, 'recursion from the first enumerator')
  call check_int(count_down(v_four), 4, 'recursion from the last enumerator')
  do i = 1, 4
    call check_int(count_down(v_value(i)), i, 'recursion depth follows ordinal')
  end do

  ! --- Two enumeration types passed to one procedure.
  a = v_two
  w = w5
  call swap_pair(a, w)
  call check_int(int(a), 3, 'first argument of the mixed-type procedure')
  call check_int(int(w), 4, 'second argument of the mixed-type procedure')

  if (nfail == 0) then
    print '(A)', 'PASS enum_07_procedures'
  else
    write (error_unit, '(A,I0,A)') 'enum_07: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enum_07_procedures
