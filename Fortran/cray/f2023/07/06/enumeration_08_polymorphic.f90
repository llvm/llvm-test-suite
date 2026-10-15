! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of values of enumeration type held by unlimited
! polymorphic entities and selected by the SELECT TYPE construct.
!
! Standard references exercised by this test:
!   7.6.2 p4            two data entities of enumeration type have the same
!                       type only if declared with reference to the same
!                       enumeration type definition, so distinct enumeration
!                       types and INTEGER are distinct dynamic types
!   7.3.2.3             CLASS(*) is unlimited polymorphic and may have any
!                       dynamic type
!   7.3.2.1 C708/p3     CLASSOF (data-ref) of an enumeration entity declares a
!                       polymorphic dummy argument or allocatable variable
!   9.7.1.1             ALLOCATE with SOURCE= or MOLD= establishes the
!                       dynamic type of an unlimited polymorphic object
!   10.2.1.3            intrinsic assignment to an allocatable polymorphic
!                       variable
!   11.1.11             SELECT TYPE; a TYPE IS type-guard-stmt may name an
!                       enumeration type, and the associate name has that
!                       declared type within the block
!   15.5.2.5            an actual argument of enumeration type associated
!                       with a CLASS(*) dummy argument
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enumeration_poly_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  enumeration type :: w_value
    enumerator :: w1, w2, w3, w4, w5, wendsentinel
  end enumeration type w_value

  integer :: nfail = 0
  integer :: nchecks = 0

contains

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    nchecks = nchecks + 1
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enumeration_08: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    nchecks = nchecks + 1
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enumeration_08: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  ! Classify the dynamic type of a CLASS(*) dummy argument; the ordinal or
  ! integer value is returned through VAL.
  !   1 = v_value, 2 = w_value, 3 = integer, 4 = anything else
  integer function classify(x, val)
    class(*), intent(in) :: x
    integer, intent(out) :: val
    val = -1
    select type (x)
    type is (v_value)
      classify = 1
      val = int(x)
    type is (w_value)
      classify = 2
      val = int(x)
    type is (integer)
      classify = 3
      val = x
    class default
      classify = 4
    end select
  end function classify

  ! A CLASSOF entity is polymorphic, so it may be a SELECT TYPE selector.
  integer function classof_ordinal(x)
    classof(v_one), intent(in) :: x
    classof_ordinal = -1
    select type (x)
    type is (v_value)
      classof_ordinal = int(x)
    end select
  end function classof_ordinal

  ! Advance an enumeration value held by a CLASS(*) dummy argument.
  subroutine advance_any(x)
    class(*), intent(inout) :: x
    select type (x)
    type is (v_value)
      x = next(x)
    type is (w_value)
      x = next(x)
    end select
  end subroutine advance_any

end module enumeration_poly_mod

program enumeration_08_polymorphic
  use enumeration_poly_mod
  implicit none

  class(*), allocatable :: u, ua(:)
  class(*), pointer :: p
  type(v_value), target :: tv
  classof(tv), allocatable :: cv
  type(w_value) :: wv
  type(v_value) :: arr(4) = [v_one, v_two, v_three, v_four]
  integer :: val, i

  ! --- Actual arguments of enumeration type and of integer type associated
  ! with a CLASS(*) dummy argument keep distinct dynamic types (7.6.2 p4).
  call check_int(classify(v_three, val), 1, 'v_value actual selects v_value')
  call check_int(val, 3, 'v_value actual ordinal')
  call check_int(classify(w5, val), 2, 'w_value actual selects w_value')
  call check_int(val, 5, 'w_value actual ordinal')
  call check_int(classify(3, val), 3, 'integer actual selects integer')
  call check_int(val, 3, 'integer actual value')
  call check_int(classify(3.0, val), 4, 'real actual selects CLASS DEFAULT')

  ! --- ALLOCATE with SOURCE= of enumeration type.
  allocate (u, source=v_two)
  call check_int(classify(u, val), 1, 'SOURCE= v_value dynamic type')
  call check_int(val, 2, 'SOURCE= v_value ordinal')
  select type (u)
  type is (v_value)
    call check_true(u == v_two, 'associate name compares with an enumerator')
    call check_true(u < huge(u), 'associate name with a relational operator')
  class default
    call check_true(.false., 'SOURCE= v_value not selected by TYPE IS')
  end select
  deallocate (u)

  ! The same ordinal as an integer is a different dynamic type.
  allocate (u, source=2)
  call check_int(classify(u, val), 3, 'SOURCE= integer dynamic type')
  deallocate (u)

  allocate (u, source=w2)
  call check_int(classify(u, val), 2, 'SOURCE= w_value dynamic type')
  call check_int(val, 2, 'SOURCE= w_value ordinal')
  deallocate (u)

  ! --- ALLOCATE with MOLD= establishes only the dynamic type; the value is
  ! undefined (9.2 p2), so it is referenced only after it is defined.
  allocate (u, mold=w1)
  select type (u)
  type is (w_value)
    u = w4
    call check_int(classify(u, val), 2, 'MOLD= w_value after definition')
    call check_int(val, 4, 'MOLD= w_value value defined in SELECT TYPE')
  class default
    call check_true(.false., 'MOLD= w_value not selected by TYPE IS')
  end select
  deallocate (u)

  ! --- Intrinsic assignment to an allocatable CLASS(*) variable sets, and
  ! can change, its dynamic type (10.2.1.3).
  u = v_four
  call check_int(classify(u, val), 1, 'assignment gives v_value dynamic type')
  call check_int(val, 4, 'assignment v_value ordinal')
  u = 7
  call check_int(classify(u, val), 3, 'reassignment gives integer dynamic type')
  call check_int(val, 7, 'reassignment integer value')
  u = w3
  call check_int(classify(u, val), 2, 'reassignment gives w_value dynamic type')
  call check_int(val, 3, 'reassignment w_value ordinal')

  ! --- The associate name is definable and updates the selector.
  call advance_any(u)
  call check_int(classify(u, val), 2, 'advanced w_value dynamic type')
  call check_int(val, 4, 'advanced w_value ordinal')
  deallocate (u)

  ! --- A CLASS(*) pointer associated with a target of enumeration type.
  tv = v_one
  p => tv
  call check_int(classify(p, val), 1, 'pointer target dynamic type')
  call check_int(val, 1, 'pointer target ordinal')
  call advance_any(p)
  call check_true(tv == v_two, 'update through CLASS(*) pointer reaches target')

  ! --- A rank-one CLASS(*) array of enumeration type.
  allocate (ua, source=arr)
  call check_int(size(ua), 4, 'CLASS(*) array size')
  select type (ua)
  type is (v_value)
    call check_true(all(int(ua) == [1, 2, 3, 4]), 'CLASS(*) array ordinals')
    call check_true(all(ua == arr), 'CLASS(*) array compares with source')
    do i = 1, size(ua) - 1
      ua(i) = next(ua(i))
    end do
    call check_true(all(int(ua) == [2, 3, 4, 4]), 'CLASS(*) array updated')
  class default
    call check_true(.false., 'CLASS(*) array not selected by TYPE IS')
  end select
  deallocate (ua)

  ! --- A scalar of the other enumeration type is not selected as v_value.
  wv = wendsentinel
  call check_int(classify(wv, val), 2, 'sentinel selects w_value')
  call check_int(val, 6, 'sentinel ordinal')

  ! --- CLASSOF dummy argument and allocatable variable (7.3.2.1 p3).
  call check_int(classof_ordinal(v_two), 2, 'CLASSOF dummy, enumerator actual')
  allocate (cv, source=v_three)
  call check_int(classof_ordinal(cv), 3, 'CLASSOF dummy, CLASSOF actual')
  call check_int(classify(cv, val), 1, 'CLASSOF variable dynamic type')
  call check_int(val, 3, 'CLASSOF variable ordinal')
  select type (cv)
  type is (v_value)
    call check_true(cv == v_three, 'CLASSOF variable selected by TYPE IS')
  class default
    call check_true(.false., 'CLASSOF variable not selected by TYPE IS')
  end select
  deallocate (cv)

  if (nfail == 0) then
    print '(A,I0,A)', 'PASS enumeration_08_polymorphic: ', nchecks, ' checks'
  else
    write (error_unit, '(A,I0,A)') 'enumeration_08: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enumeration_08_polymorphic
