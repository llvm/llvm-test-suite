! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of enumeration type definitions, the ordinal
! position of each enumerator, and the enumeration constructor.
!
! Standard references exercised by this test:
!   7.6.2 R766-R769     enumeration-type-def, including its optional syntax
!   7.6.2 C7115         the name may be repeated on END ENUMERATION TYPE
!   7.6.2 p3            every enumerator is a scalar named constant of the
!                       type; the order of the enumerator names defines the
!                       ordinal position of each enumerator
!   7.6.2 R770/C7116    enumeration-type-spec names a previously defined type
!   7.6.2 p4            two entities have the same type if they are declared
!                       with reference to the same enumeration type definition
!   7.6.2 R771/p5       an enumeration constructor produces the value whose
!                       ordinal position is the value of the scalar-int-expr
!   7.3.2.2 p2          TYPE (enumeration-type-spec) in a declaration
!   7.6.2 NOTE          an enumeration type can be used to declare components
!   8.4 R848/C887/C888  enumeration-constructor as a data-stmt-constant
!   10.1.12 (4)(5)      enumeration constructor in a constant expression
!   10.2.1.2 Table 10.8 intrinsic assignment from the same enumeration type
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! INT is the portable way of observing an ordinal position, so it is used as
! the primitive that the checks below are written in terms of.
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_def_mod
  use iso_fortran_env, only: error_unit
  implicit none

  ! R767 with the optional "::", R768 with and then without the optional
  ! "::", and R769 repeating enumeration-type-name (C7115).
  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  ! R767 without the optional "::" and R769 without the type name.
  enumeration type w_value
    enumerator :: w1, w2, w3, w4, w5, wendsentinel
  end enumeration type

  ! R766 permits a definition with a single enumerator.
  enumeration type :: solo
    enumerator :: only_value
  end enumeration type solo

  ! 7.6.2 NOTE: an enumeration type can be used to declare components.  The
  ! default initialization values are constant expressions (10.1.12 (1), (5)).
  type :: vw
    type(v_value) :: v = v_value(1)
    type(w_value) :: w = w1
  end type

  ! Non-default kinds, so that an ignored KIND= argument is detectable.
  integer, parameter :: ik = selected_int_kind(18)
  integer, parameter :: sk = selected_int_kind(2)

  integer :: nfail = 0

contains

  subroutine check_ordinal(actual, expected, label)
    type(v_value), intent(in) :: actual
    integer, intent(in) :: expected
    character(len=*), intent(in) :: label
    call check_int(int(actual), expected, label)
  end subroutine check_ordinal

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_01: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_01: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

end module enum_def_mod

program enum_01_definition_and_constructors
  use enum_def_mod
  implicit none

  ! 7.3.2.2 p2: declarations that reference a previously defined enumeration
  ! type.  Initialization uses an enumerator and an enumeration constructor.
  type(v_value) :: x = v_one
  type(v_value) :: y = v_value(2)
  type(v_value) :: z
  type(w_value) :: w
  type(solo) :: s

  ! 10.1.12 (5): an enumeration constructor whose expr is a constant
  ! expression is itself a constant expression, so it can define a named
  ! constant and can initialize an array.
  type(v_value), parameter :: p_two = v_value(2)
  type(v_value), parameter :: p_list(3) = [v_value(3), v_two, v_value(1)]

  type(v_value) :: ascending(4) = [v_one, v_two, v_three, v_four]
  type(v_value) :: typed_ctor(2) = [v_value :: v_four, v_three]
  type(v_value) :: assigned(4)

  ! 8.4 R848/C887/C888: data-stmt-constants that are an enumerator (a scalar
  ! constant) and an enumeration constructor.
  type(v_value) :: d1, d2, d3(2)
  data d1/v_three/
  data d2/v_value(4)/
  data d3/v_value(1), v_two/

  type(vw) :: pair_default
  type(vw) :: pair_positional
  type(vw) :: pair_keyword

  type(v_value), allocatable :: alloc_scalar
  type(v_value), allocatable :: alloc_array(:)

  integer :: i, k

  ! --- 7.6.2 p3: ordinal positions follow the order of the enumerator names.
  call check_ordinal(v_one, 1, 'ordinal of v_one')
  call check_ordinal(v_two, 2, 'ordinal of v_two')
  call check_ordinal(v_three, 3, 'ordinal of v_three')
  call check_ordinal(v_four, 4, 'ordinal of v_four')

  ! Ordinal positions continue across a second ENUMERATOR statement and are
  ! independent for each enumeration type definition (7.6.2 p3, p4).
  call check_int(int(w1), 1, 'ordinal of w1')
  call check_int(int(w2), 2, 'ordinal of w2')
  call check_int(int(w3), 3, 'ordinal of w3')
  call check_int(int(w4), 4, 'ordinal of w4')
  call check_int(int(w5), 5, 'ordinal of w5')
  call check_int(int(wendsentinel), 6, 'ordinal of wendsentinel')
  call check_int(int(only_value), 1, 'ordinal of only_value')

  ! 16.9.110: INT accepts a KIND argument; the ordinal position is unchanged.
  call check_int(int(int(v_three, kind=ik)), 3, 'INT with KIND= value')
  call check_int(kind(int(v_three, kind=ik)), ik, 'INT with KIND= result kind')
  call check_int(int(int(v_four, kind=sk)), 4, 'INT with small KIND= value')
  call check_int(kind(int(v_four, kind=sk)), sk, &
      'INT with small KIND= result kind')

  ! --- 7.6.2 p3: an enumerator is a scalar named constant of the type, so it
  ! may be assigned to a variable of that type (10.2.1.2 Table 10.8).
  z = v_three
  call check_ordinal(z, 3, 'assignment of an enumerator')

  z = y
  call check_ordinal(z, 2, 'assignment from a variable of the same type')

  call check_ordinal(x, 1, 'initialization with an enumerator')
  call check_ordinal(y, 2, 'initialization with a constructor')

  w = wendsentinel
  call check_int(int(w), 6, 'assignment for the second type')

  s = only_value
  call check_int(int(s), 1, 'assignment for a single-enumerator type')

  ! --- 7.6.2 R771/p5: the enumeration constructor.
  call check_ordinal(v_value(1), 1, 'constructor with a literal 1')
  call check_ordinal(v_value(4), 4, 'constructor with a literal 4')

  ! The scalar-int-expr need not be a constant expression.
  i = 3
  call check_ordinal(v_value(i), 3, 'constructor with a variable')
  call check_ordinal(v_value(i - 1), 2, 'constructor with an expression')
  call check_ordinal(v_value(i/3), 1, 'constructor with a quotient')
  call check_ordinal(v_value(int(v_four)), 4, 'constructor of INT of a value')

  ! The constructor is the inverse of INT for every ordinal position.
  do k = 1, 4
    call check_int(int(v_value(k)), k, 'INT (T (k)) == k')
  end do

  ! A constructor value compares equal to the corresponding enumerator
  ! (10.1.5.5.1 p9); the enumerators are recovered in ordinal order.
  call check_true(v_value(1) == v_one, 'constructor 1 is v_one')
  call check_true(v_value(2) == v_two, 'constructor 2 is v_two')
  call check_true(v_value(3) == v_three, 'constructor 3 is v_three')
  call check_true(v_value(4) == v_four, 'constructor 4 is v_four')
  call check_true(w_value(6) == wendsentinel, 'constructor 6 is wendsentinel')

  ! --- Named constants and constant expressions.
  call check_ordinal(p_two, 2, 'PARAMETER of enumeration type')
  call check_int(int(p_list(1)), 3, 'PARAMETER array element 1')
  call check_int(int(p_list(2)), 2, 'PARAMETER array element 2')
  call check_int(int(p_list(3)), 1, 'PARAMETER array element 3')

  ! --- DATA statement initialization (8.4 R848).
  call check_ordinal(d1, 3, 'DATA with an enumerator')
  call check_ordinal(d2, 4, 'DATA with a constructor')
  call check_int(int(d3(1)), 1, 'DATA array element 1')
  call check_int(int(d3(2)), 2, 'DATA array element 2')

  ! --- Arrays of enumeration type.
  do k = 1, 4
    call check_int(int(ascending(k)), k, 'array constructor element')
  end do
  call check_int(int(typed_ctor(1)), 4, 'typed array constructor element 1')
  call check_int(int(typed_ctor(2)), 3, 'typed array constructor element 2')

  ! Whole-array assignment and array sections (10.2.1.2 Table 10.8).
  assigned = ascending
  call check_true(all(int(assigned) == [1, 2, 3, 4]), 'whole array assignment')

  assigned(2:3) = [v_four, v_one]
  call check_true(all(int(assigned) == [1, 4, 1, 4]), 'array section assignment')

  assigned = v_two
  call check_true(all(int(assigned) == 2), 'scalar broadcast to an array')

  assigned = ascending(4:1:-1)
  call check_true(all(int(assigned) == [4, 3, 2, 1]), 'reversed array section')

  ! --- Components of enumeration type (7.6.2 NOTE).
  call check_int(int(pair_default%v), 1, 'default initialization of component v')
  call check_int(int(pair_default%w), 1, 'default initialization of component w')

  pair_positional = vw(v_two, w3)
  call check_int(int(pair_positional%v), 2, 'structure constructor component v')
  call check_int(int(pair_positional%w), 3, 'structure constructor component w')

  pair_keyword = vw(w=w5, v=v_value(4))
  call check_int(int(pair_keyword%v), 4, 'keyword structure constructor v')
  call check_int(int(pair_keyword%w), 5, 'keyword structure constructor w')

  pair_keyword%v = v_one
  call check_int(int(pair_keyword%v), 1, 'assignment to a component')

  ! --- ALLOCATE with an enumeration type-spec (7.3.1 R702) and with SOURCE=.
  allocate (v_value :: alloc_scalar)
  alloc_scalar = v_three
  call check_ordinal(alloc_scalar, 3, 'ALLOCATE with an enumeration type-spec')
  deallocate (alloc_scalar)

  allocate (alloc_scalar, source=v_two)
  call check_ordinal(alloc_scalar, 2, 'ALLOCATE with SOURCE=')
  deallocate (alloc_scalar)

  allocate (v_value :: alloc_array(4))
  alloc_array = ascending
  call check_true(all(int(alloc_array) == [1, 2, 3, 4]), 'allocatable array')
  deallocate (alloc_array)

  ! --- ASSOCIATE with an enumeration selector.
  associate (sel => ascending(3))
    call check_int(int(sel), 3, 'ASSOCIATE with a variable selector')
  end associate

  associate (sel => v_value(2))
    call check_int(int(sel), 2, 'ASSOCIATE with an expression selector')
  end associate

  ! --- BLOCK construct with a local entity of enumeration type.
  block
    type(v_value) :: local = v_four
    call check_ordinal(local, 4, 'BLOCK local of enumeration type')
  end block

  if (nfail == 0) then
    print '(A)', 'PASS enum_01_definition_and_constructors'
  else
    write (error_unit, '(A,I0,A)') 'enum_01: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enum_01_definition_and_constructors
