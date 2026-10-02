! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of the accessibility of an enumeration type and
! of its enumerators, and of their use association.
!
! Standard references exercised by this test:
!   7.6.2 R767          ENUMERATION TYPE [ [ , access-spec ] :: ] name
!   7.6.2 C7114         an access-spec on an enumeration-type-stmt shall only
!                       appear in the specification part of a module
!   7.6.2 p2            the access-spec specifies the accessibility of the
!                       enumeration-type-name and the default accessibility of
!                       its enumerators; the accessibility of an enumerator
!                       may be confirmed or overridden by an access-stmt
!   8.6.1 R830/C874     an access-stmt names a nonintrinsic type or a named
!                       constant, so both an enumeration type name and an
!                       individual enumerator may appear in one
!   14.2.2              use association, including ONLY and renaming
!   19.5.1.4            host association of enumerators in contained and
!                       internal procedures
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_public_mod
  implicit none

  ! An explicit PUBLIC access-spec on the enumeration-type-stmt.  The
  ! enumerators default to public accessibility (7.6.2 p2).
  enumeration type, public :: colour
    enumerator :: red, green, blue
  end enumeration type colour

  ! No access-spec: the type and its enumerators take the default
  ! accessibility of the module, which is public (8.6.1 p1).
  enumeration type :: shade
    enumerator :: light, dark
  end enumeration type shade

  ! A PUBLIC type whose enumerators are public by default; the accessibility
  ! of one of them is confirmed and of another is overridden by an access-stmt
  ! (7.6.2 p2).
  enumeration type, public :: channel
    enumerator :: ch_left, ch_centre, ch_right
  end enumeration type channel
  public :: ch_left
  private :: ch_centre

  ! A PRIVATE enumeration type.  Neither the type name nor its enumerators
  ! are accessible outside the module, so the module exports procedures that
  ! operate on values of the type instead.
  enumeration type, private :: secret
    enumerator :: hidden_first, hidden_second, hidden_third
  end enumeration type secret

contains

  ! The private enumerator ch_centre remains accessible by host association
  ! inside the module (19.5.1.4).
  subroutine get_centre(c)
    type(channel), intent(out) :: c
    c = ch_centre
  end subroutine get_centre

  integer function centre_ordinal()
    centre_ordinal = int(ch_centre)
  end function centre_ordinal

  ! Operations on the private type, reported as ordinal positions.
  integer function secret_count()
    secret_count = int(huge(hidden_first))
  end function secret_count

  integer function secret_walk() result(total)
    type(secret) :: s
    integer :: stat
    total = 0
    s = secret(1)
    do
      total = total + int(s)
      if (s == huge(s)) exit
      s = next(s, stat)
    end do
  end function secret_walk

end module enum_public_mod

module enum_private_mod
  implicit none
  ! The module default is private accessibility; individual identifiers are
  ! exported by an access-stmt (8.6.1 R830).
  private

  enumeration type :: weekday
    enumerator :: mon, tue, wed, thu, fri
  end enumeration type weekday

  public :: weekday
  public :: mon, wed, fri
  public :: weekday_ordinal, is_midweek

contains

  integer function weekday_ordinal(d)
    type(weekday), intent(in) :: d
    weekday_ordinal = int(d)
  end function weekday_ordinal

  ! tue and thu are not accessible outside this module but are available here
  ! by host association.
  logical function is_midweek(d)
    type(weekday), intent(in) :: d
    is_midweek = d >= tue .and. d <= thu
  end function is_midweek

end module enum_private_mod

program enum_06_accessibility_and_use
  ! 14.2.2 p6/p7: several USE statements for one module are cumulative, and a
  ! rename gives an accessible entity an additional local identifier.
  use enum_public_mod, only: colour, red, green, blue
  use enum_public_mod, only: shade, light, dark
  use enum_public_mod, only: channel, ch_left, ch_right
  use enum_public_mod, only: get_centre, centre_ordinal, secret_count, secret_walk
  use enum_public_mod, only: hue => colour, crimson => red, azure => blue
  use enum_private_mod
  use iso_fortran_env, only: error_unit
  implicit none

  type(colour) :: c
  type(shade) :: s
  type(channel) :: ch
  type(hue) :: h
  type(weekday) :: d
  integer :: nfail
  integer :: i

  nfail = 0

  ! --- A public type and its default-public enumerators.
  c = red
  call check_int(int(c), 1, 'use associated enumerator red')
  c = blue
  call check_int(int(c), 3, 'use associated enumerator blue')
  call check_int(int(green), 2, 'use associated enumerator green')
  call check_int(int(colour(2)), 2, 'constructor of a use associated type')
  call check_int(int(huge(c)), 3, 'HUGE of a use associated type')

  ! --- A type with no access-spec takes the module default accessibility.
  s = dark
  call check_int(int(s), 2, 'enumerator of a default-accessibility type')
  call check_int(int(light), 1, 'first enumerator of that type')
  call check_int(int(huge(s)), 2, 'HUGE of that type')

  ! --- An enumerator whose accessibility was confirmed by an access-stmt.
  ch = ch_left
  call check_int(int(ch), 1, 'enumerator confirmed PUBLIC')
  ch = ch_right
  call check_int(int(ch), 3, 'enumerator of the same type')

  ! The overridden (private) enumerator is still a value of the type; it is
  ! obtained here through the module procedures that can name it.
  call get_centre(ch)
  call check_int(int(ch), 2, 'value of a PRIVATE enumerator')
  call check_int(centre_ordinal(), 2, 'ordinal of a PRIVATE enumerator')
  call check_int(int(next(ch_left)), 2, 'NEXT reaches the private enumerator')
  call check_int(int(previous(ch_right)), 2, 'PREVIOUS reaches it as well')

  ! --- A private enumeration type, used through the module interface only.
  call check_int(secret_count(), 3, 'size of a PRIVATE enumeration type')
  call check_int(secret_walk(), 6, 'walk over a PRIVATE enumeration type')

  ! --- Local names introduced by renaming on the USE statement.
  h = crimson
  call check_int(int(h), 1, 'renamed enumerator crimson')
  h = azure
  call check_int(int(h), 3, 'renamed enumerator azure')
  h = hue(2)
  call check_int(int(h), 2, 'constructor with the renamed type name')
  call check_int(int(huge(h)), 3, 'HUGE with the renamed type name')

  ! A renamed name and the original name denote the same entity, so values
  ! declared either way have the same type (7.6.2 p4).
  c = crimson
  h = red
  call check_true(c == h, 'renamed and original names are the same type')
  call check_true(c == red .and. h == crimson, 'both spellings compare equal')

  ! --- A module whose default accessibility is private, exporting selected
  ! enumerators only.
  d = mon
  call check_int(int(d), 1, 'exported enumerator mon')
  d = wed
  call check_int(int(d), 3, 'exported enumerator wed')
  d = fri
  call check_int(int(d), 5, 'exported enumerator fri')
  call check_int(weekday_ordinal(fri), 5, 'ordinal through a module procedure')
  call check_int(int(huge(d)), 5, 'HUGE of the selectively exported type')

  ! The unexported enumerators are reachable as values of the type.
  call check_true(is_midweek(weekday(2)), 'unexported value tue is midweek')
  call check_true(is_midweek(wed), 'exported value wed is midweek')
  call check_true(is_midweek(weekday(4)), 'unexported value thu is midweek')
  call check_true(.not. is_midweek(mon), 'mon is not midweek')
  call check_true(.not. is_midweek(fri), 'fri is not midweek')

  do i = 1, 5
    d = weekday(i)
    call check_true(is_midweek(d) .eqv. (i >= 2 .and. i <= 4), &
        'midweek classification')
  end do

  ! --- Host association of use associated enumerators in an internal
  ! procedure (19.5.1.4).
  call check_int(internal_ordinal(), 3, 'host associated enumerator')

  if (nfail == 0) then
    print '(A)', 'PASS enum_06_accessibility_and_use'
  else
    write (error_unit, '(A,I0,A)') 'enum_06: ', nfail, ' check(s) failed'
    error stop 1
  end if

contains

  integer function internal_ordinal()
    type(colour) :: local
    local = blue
    internal_ordinal = int(local)
  end function internal_ordinal

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_06: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_06: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

end program enum_06_accessibility_and_use
