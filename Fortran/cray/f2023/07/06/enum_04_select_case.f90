! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of the SELECT CASE construct with a case
! expression of enumeration type.
!
! Standard references exercised by this test:
!   11.1.9.1 C1150      case-expr may be of enumeration type
!   11.1.9.1 C1152      each case-value shall be of the same type as case-expr
!   11.1.9.1 R1148      a case-value-range is a single value, low : high,
!                       low :, or : high
!   11.1.9.1 R1149      a case-value is a scalar-constant-expr, so enumerators
!                       and enumeration constructors are both usable
!   11.1.9.2            matching uses c == v for a single value and
!                       low <= c .AND. c <= high for a range, which for an
!                       enumeration type is the ordinal ordering established
!                       by 10.1.5.5.1 p9
!   11.1.9.1 C1151      at most one DEFAULT selector
!   7.6.2 NOTE          the "wcheck" example of the standard
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_case_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: w_value
    enumerator :: w1, w2, w3, w4, w5, wendsentinel
  end enumeration type w_value

  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  ! A named constant of enumeration type is a scalar-constant-expr and so is
  ! usable as a case-value (R1149).
  type(w_value), parameter :: w_last = wendsentinel

  integer :: nfail = 0

contains

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_04: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_04: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  ! The classification of the 7.6.2 NOTE, returning a code instead of
  ! printing, so that every branch can be checked.
  !   1 = w1, 2 = one of w2...w4, 3 = wendsentinel, 4 = anything else
  integer function wcheck(w)
    type(w_value), intent(in) :: w
    select case (w)
    case (w1)
      wcheck = 1
    case (w2:w4)
      wcheck = 2
    case (wendsentinel)
      wcheck = 3
    case default
      wcheck = 4
    end select
  end function wcheck

  ! Open-ended ranges and a value list, with a construct name (C1149).
  integer function classify_open(w)
    type(w_value), intent(in) :: w
    outer: select case (w)
    case (:w2) outer
      classify_open = 10
    case (w3, w5) outer
      classify_open = 20
    case (w4) outer
      classify_open = 30
    case (wendsentinel:) outer
      classify_open = 40
    end select outer
  end function classify_open

  ! Every selector form expressed with enumeration constructors, which are
  ! constant expressions (10.1.12 (5)).
  integer function classify_ctor(w)
    type(w_value), intent(in) :: w
    select case (w)
    case (w_value(1))
      classify_ctor = 1
    case (w_value(2):w_value(3))
      classify_ctor = 2
    case (w_value(4), w_value(5))
      classify_ctor = 3
    case (w_last)
      classify_ctor = 4
    end select
  end function classify_ctor

end module enum_case_mod

program enum_04_select_case
  use enum_case_mod
  implicit none

  type(w_value) :: w
  type(v_value) :: v
  integer :: i, j, taken, code
  integer :: visits(6)

  ! --- The 7.6.2 NOTE classification over every value of the type.
  call check_int(wcheck(w1), 1, 'wcheck (w1)')
  call check_int(wcheck(w2), 2, 'wcheck (w2)')
  call check_int(wcheck(w3), 2, 'wcheck (w3)')
  call check_int(wcheck(w4), 2, 'wcheck (w4)')
  call check_int(wcheck(w5), 4, 'wcheck (w5)')
  call check_int(wcheck(wendsentinel), 3, 'wcheck (wendsentinel)')
  call check_int(wcheck(w_value(2)), 2, 'wcheck of a constructor value')

  ! --- Open-ended ranges and value lists.
  call check_int(classify_open(w1), 10, 'classify_open (w1)')
  call check_int(classify_open(w2), 10, 'classify_open (w2)')
  call check_int(classify_open(w3), 20, 'classify_open (w3)')
  call check_int(classify_open(w4), 30, 'classify_open (w4)')
  call check_int(classify_open(w5), 20, 'classify_open (w5)')
  call check_int(classify_open(wendsentinel), 40, 'classify_open (w6)')

  ! --- Selectors written as enumeration constructors and named constants.
  call check_int(classify_ctor(w1), 1, 'classify_ctor (w1)')
  call check_int(classify_ctor(w2), 2, 'classify_ctor (w2)')
  call check_int(classify_ctor(w3), 2, 'classify_ctor (w3)')
  call check_int(classify_ctor(w4), 3, 'classify_ctor (w4)')
  call check_int(classify_ctor(w5), 3, 'classify_ctor (w5)')
  call check_int(classify_ctor(wendsentinel), 4, 'classify_ctor (w6)')

  ! --- Exactly one branch is selected for each value of the type, and the
  ! selected branch is the one predicted by 11.1.9.2 from the ordinals.
  visits = 0
  do i = 1, 6
    w = w_value(i)
    taken = 0
    select case (w)
    case (w1)
      taken = 1
    case (w2)
      taken = 2
    case (w3)
      taken = 3
    case (w4)
      taken = 4
    case (w5)
      taken = 5
    case (wendsentinel)
      taken = 6
    end select
    call check_int(taken, i, 'one branch per enumerator')
    visits(taken) = visits(taken) + 1
  end do
  call check_true(all(visits == 1), 'each branch selected exactly once')

  ! --- A case expression that is an expression rather than a variable.
  select case (w_value(3))
  case (w3)
    call check_true(.true., 'case expression that is a constructor')
  case default
    call check_true(.false., 'case expression that is a constructor')
  end select

  select case (next(w1))
  case (w2)
    call check_true(.true., 'case expression that is a function reference')
  case default
    call check_true(.false., 'case expression that is a function reference')
  end select

  select case (huge(w1))
  case (wendsentinel)
    call check_true(.true., 'case expression that is HUGE')
  case default
    call check_true(.false., 'case expression that is HUGE')
  end select

  ! --- A DEFAULT selector catches the values not otherwise covered, and the
  ! DEFAULT statement need not be last (C1151 only limits it to one).
  do i = 1, 6
    w = w_value(i)
    code = 0
    select case (w)
    case default
      code = 99
    case (w2:w3)
      code = 23
    case (w5)
      code = 5
    end select
    select case (i)
    case (2, 3)
      call check_int(code, 23, 'DEFAULT not selected for a covered range')
    case (5)
      call check_int(code, 5, 'DEFAULT not selected for a covered value')
    case default
      call check_int(code, 99, 'DEFAULT selected for an uncovered value')
    end select
  end do

  ! --- A construct with a single range covering the whole type.
  do i = 1, 6
    w = w_value(i)
    taken = 0
    select case (w)
    case (w1:wendsentinel)
      taken = 1
    case default
      taken = 2
    end select
    call check_int(taken, 1, 'range spanning the whole type')
  end do

  ! --- Nested constructs over two different enumeration types (7.6.2 p4).
  do i = 1, 4
    v = v_value(i)
    do j = 1, 6
      w = w_value(j)
      code = 0
      vsel: select case (v)
      case (v_one, v_two) vsel
        wsel: select case (w)
        case (:w3) wsel
          code = 1
        case default wsel
          code = 2
        end select wsel
      case (v_three:) vsel
        select case (w)
        case (:w3)
          code = 3
        case default
          code = 4
        end select
      end select vsel
      if (i <= 2 .and. j <= 3) then
        call check_int(code, 1, 'nested SELECT CASE branch 1')
      else if (i <= 2) then
        call check_int(code, 2, 'nested SELECT CASE branch 2')
      else if (j <= 3) then
        call check_int(code, 3, 'nested SELECT CASE branch 3')
      else
        call check_int(code, 4, 'nested SELECT CASE branch 4')
      end if
    end do
  end do

  ! --- A SELECT CASE that drives a state machine using NEXT.
  w = w1
  taken = 0
  do
    select case (w)
    case (w1:w5)
      taken = taken + 1
      w = next(w)
    case (wendsentinel)
      exit
    end select
  end do
  call check_int(taken, 5, 'state machine visits w1 through w5')
  call check_true(w == wendsentinel, 'state machine stops at the sentinel')

  if (nfail == 0) then
    print '(A)', 'PASS enum_04_select_case'
  else
    write (error_unit, '(A,I0,A)') 'enum_04: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enum_04_select_case
