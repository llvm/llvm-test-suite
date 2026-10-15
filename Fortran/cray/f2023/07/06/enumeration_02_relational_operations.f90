! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of relational intrinsic operations on values of
! an enumeration type.
!
! Standard references exercised by this test:
!   10.1.5.5.1 p6       an enumeration relational intrinsic operation is a
!                       relational intrinsic operation for which both operands
!                       are of the same enumeration type
!   10.1.5.5.1 p9       such an operation is true if and only if the ordinal
!                       values of the operands satisfy the relation specified
!                       by the operator
!   Table 10.2          E .EQ./.NE./==//= E, and E .GT./.GE./.LT./.LE. E
!                       (that is >, >=, <, <=), all yield type logical
!   10.1.4              the interpretation for arrays is obtained by applying
!                       the interpretation for scalars element by element
!   16.9.139            MERGE selects between values of any type
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_rel_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: level
    enumerator :: low, medium, high, critical
  end enumeration type level

  integer :: nfail = 0

contains

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_02: expected .TRUE. for ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  subroutine check_false(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (condition) then
      write (error_unit, '(2A)') 'FAIL: enum_02: expected .FALSE. for ', label
      nfail = nfail + 1
    end if
  end subroutine check_false

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_02: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

end module enum_rel_mod

program enum_02_relational_operations
  use enum_rel_mod
  implicit none

  type(level) :: a, b
  type(level) :: values(4) = [low, medium, high, critical]
  type(level) :: unsorted(5) = [high, low, critical, medium, low]
  type(level) :: work(5)
  logical :: mask(4)
  integer :: i, j, npass

  ! --- Every ordered pair of values is compared with every operator, using
  ! the ordinal positions as the reference semantics (10.1.5.5.1 p9).
  do i = 1, 4
    do j = 1, 4
      a = level(i)
      b = level(j)

      call check_eq_logical(a == b, i == j, 'a == b', i, j)
      call check_eq_logical(a /= b, i /= j, 'a /= b', i, j)
      call check_eq_logical(a < b, i < j, 'a < b', i, j)
      call check_eq_logical(a <= b, i <= j, 'a <= b', i, j)
      call check_eq_logical(a > b, i > j, 'a > b', i, j)
      call check_eq_logical(a >= b, i >= j, 'a >= b', i, j)

      ! The old-style operator forms have the same interpretation.
      call check_eq_logical(a .eq. b, i == j, 'a .EQ. b', i, j)
      call check_eq_logical(a .ne. b, i /= j, 'a .NE. b', i, j)
      call check_eq_logical(a .lt. b, i < j, 'a .LT. b', i, j)
      call check_eq_logical(a .le. b, i <= j, 'a .LE. b', i, j)
      call check_eq_logical(a .gt. b, i > j, 'a .GT. b', i, j)
      call check_eq_logical(a .ge. b, i >= j, 'a .GE. b', i, j)
    end do
  end do

  ! --- Named enumerators, constructors, and variables mix freely as operands.
  call check_true(low < critical, 'low < critical')
  call check_true(critical > low, 'critical > low')
  call check_true(medium <= high, 'medium <= high')
  call check_true(high >= high, 'high >= high')
  call check_true(low == level(1), 'low == level(1)')
  call check_true(level(2) /= level(3), 'level(2) /= level(3)')
  call check_false(critical < critical, 'critical < critical')
  call check_false(low /= low, 'low /= low')

  a = high
  call check_true(a == high, 'variable == enumerator')
  call check_true(medium < a, 'enumerator < variable')
  call check_true(a > level(1), 'variable > constructor')

  ! --- Relational results combine with the logical operators (Table 10.2).
  call check_true(low < medium .and. medium < high, 'conjunction')
  call check_true(critical < low .or. low < critical, 'disjunction')
  call check_true(.not. (critical <= high), 'negation')
  call check_true((low == low) .eqv. (high == high), 'equivalence')
  call check_true((low == high) .neqv. (high == high), 'nonequivalence')

  ! --- A relational operation controls IF, DO WHILE, and an IF construct.
  if (medium < critical) then
    call check_true(.true., 'IF with an enumeration relational')
  else
    call check_true(.false., 'IF with an enumeration relational')
  end if

  a = low
  npass = 0
  do while (a < critical)
    npass = npass + 1
    a = level(int(a) + 1)
  end do
  call check_int(npass, 3, 'DO WHILE trip count')
  call check_true(a == critical, 'DO WHILE terminal value')

  ! --- 10.1.4: elementwise application to arrays yields a logical array.
  mask = values > medium
  call check_true(all(mask .eqv. [.false., .false., .true., .true.]), &
      'array > scalar')

  mask = values == values
  call check_true(all(mask), 'array == itself')

  mask = values(4:1:-1) < values
  call check_true(all(mask .eqv. [.false., .false., .true., .true.]), &
      'array < reversed array')

  call check_int(count(values >= medium), 3, 'COUNT of array comparison')
  call check_true(any(values == critical), 'ANY of array comparison')
  call check_false(any(values > critical), 'ANY above the last value')
  call check_true(all(values <= critical), 'ALL at or below the last value')

  ! --- 16.9.139: MERGE selects between enumeration values.
  a = merge(high, low, 2 > 1)
  call check_int(int(a), 3, 'MERGE selecting TSOURCE')
  a = merge(high, low, 1 > 2)
  call check_int(int(a), 1, 'MERGE selecting FSOURCE')

  work(1:4) = merge(values, medium, values > medium)
  call check_true(all(int(work(1:4)) == [2, 2, 3, 4]), 'array MERGE clamp')

  ! --- A masked array assignment uses an enumeration relational as the mask.
  work = unsorted
  where (work < high) work = high
  call check_true(all(int(work) == [3, 3, 4, 3, 3]), 'WHERE raises low values')

  work = unsorted
  where (work == low)
    work = critical
  elsewhere
    work = low
  end where
  call check_true(all(int(work) == [1, 4, 1, 1, 4]), 'WHERE ... ELSEWHERE')

  ! --- The ordering is a usable total order: sort with the "<" operator.
  work = unsorted
  call sort_levels(work)
  call check_true(all(int(work) == [1, 1, 2, 3, 4]), 'ascending sort')
  do i = 1, size(work) - 1
    call check_true(work(i) <= work(i + 1), 'sorted neighbours are ordered')
  end do

  ! --- MINVAL/MAXVAL are not defined for enumeration types, so the extremes
  ! are located with the relational operators directly.
  a = unsorted(1)
  b = unsorted(1)
  do i = 2, size(unsorted)
    if (unsorted(i) < a) a = unsorted(i)
    if (unsorted(i) > b) b = unsorted(i)
  end do
  call check_int(int(a), 1, 'smallest value found')
  call check_int(int(b), 4, 'largest value found')

  if (nfail == 0) then
    print '(A)', 'PASS enum_02_relational_operations'
  else
    write (error_unit, '(A,I0,A)') 'enum_02: ', nfail, ' check(s) failed'
    error stop 1
  end if

contains

  subroutine check_eq_logical(actual, expected, op, i, j)
    logical, intent(in) :: actual, expected
    character(len=*), intent(in) :: op
    integer, intent(in) :: i, j
    if (actual .neqv. expected) then
      write (error_unit, '(3A,I0,A,I0,A,L1,A,L1)') 'FAIL: enum_02: ', op, &
          ' with ordinals ', i, ',', j, ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_eq_logical

  subroutine sort_levels(v)
    type(level), intent(inout) :: v(:)
    type(level) :: t
    integer :: m, n
    do m = 1, size(v) - 1
      do n = 1, size(v) - m
        if (v(n + 1) < v(n)) then
          t = v(n)
          v(n) = v(n + 1)
          v(n + 1) = t
        end if
      end do
    end do
  end subroutine sort_levels

end program enum_02_relational_operations
