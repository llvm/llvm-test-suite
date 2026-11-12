! Executable tests for F2023 explicit-shape-bounds-spec (R818) in the cases
! where the rank-1 bounds array cannot be reduced to a per-dimension scalar at
! compile time, and in the cases that interact with it.  These complement
! declaration-explicit-array-bounds.f90, whose bounds are all reducible.
!
! An elemental MERGE with a LOGICAL array mask is the canonical irreducible
! base: the compiler cannot distribute the element extraction into it, so each
! dimension's bound is extracted from the array value at run time.
!
!   1. Irreducible upper bound; irreducible lower and upper bounds
!   2. Irreducible bound paired with a constant rank-1 bound, both orientations
!   3. Inquiries of an irreducible array as other arrays' bounds
!   4. Lower bound 0: SIZE(a,dim) stays a run-time inquiry; TRANSPOSE(a)
!   5. Two different irreducible bases in one declaration
!   6. Scalar bound alongside an inquiry of a rank-1-bounded array
!   7. Derived-type component as the bounds array
!   8. EQUIVALENCE with constant rank-1 bounds
!   9. Constant all-ones lower bound is a constant expression
!  10. MAX/MIN of a repeated operand is not collapsed unless constant
!  11. Empty dimension: LBOUND/UBOUND inquiries are 1/0, not the declared bounds
!  12. Polymorphic explicit-shape dummies (descriptor lowering path)

module irreducible_helpers
  implicit none
  type t
    integer :: c
  end type
contains
  ! Host dummy a and internal dummy b are both argument 1 of their procedure.
  ! The outer operand is the extremum in every declaration below, so dropping
  ! it (collapsing to the nested MAX/MIN) changes the declared size.
  subroutine check_extremum_host(a, ok)
    integer, intent(in) :: a
    logical, intent(inout) :: ok
    call check_extremum_inner(1)
  contains
    subroutine check_extremum_inner(b)
      integer, intent(in) :: b
      real :: w(max(a, max(b, 0)))    ! (7), not max(b, 0) = 1
      real :: w2(max(max(b, 0), a))   ! (7)
      real :: v(min(b, min(a, 9)))    ! (1), not min(a, 9) = 7
      real :: v2(min(min(a, 9), b))   ! (1)
      if (size(w) /= 7 .or. size(w2) /= 7) ok = .false.
      if (size(v) /= 1 .or. size(v2) /= 1) ok = .false.
    end subroutine
  end subroutine
end module irreducible_helpers

program declaration_explicit_array_bounds_irreducible
  use irreducible_helpers
  implicit none

  integer :: pass_count, fail_count
  logical :: ok
  pass_count = 0
  fail_count = 0

  call test_irreducible_bounds()
  call test_irreducible_with_constant()
  call test_inquiry_of_irreducible()
  call test_lb0_inquiry_and_transpose()
  call test_two_irreducible_bases()
  call test_scalar_and_inquiry()
  call test_component_base()
  call test_equivalence_constant_bounds()
  call test_constant_ones_lbound()
  call test_extremum_fold()
  call test_empty_dimension()
  call test_polymorphic_dummy()

  print *, ""
  print *, "RESULTS:", pass_count, "passed,", fail_count, "failed"
  if (fail_count > 0) stop 1

contains

  subroutine report(name)
    character(*), intent(in) :: name
    if (ok) then
      print *, "PASS: ", name
      pass_count = pass_count + 1
    else
      print *, "FAIL: ", name
      fail_count = fail_count + 1
    end if
  end subroutine

  ! 1. Irreducible upper bound; irreducible lower and upper bounds.
  subroutine test_irreducible_bounds()
    ok = .true.
    call check_irreducible_bounds([2, 9], [9, 3], [.true., .false.], &
                                  [1, 1], [0, 2], [.false., .true.])
    call report("irreducible_bounds")
  end subroutine

  subroutine check_irreducible_bounds(n, m, c, lo, lo2, c2)
    integer, intent(in) :: n(2), m(2), lo(2), lo2(2)
    logical, intent(in) :: c(2), c2(2)
    real :: a(merge(n, m, c))                      ! (2, 3)
    real :: b(merge(lo, lo2, c2) : merge(n, m, c)) ! (0:2, 1:3)
    if (any(shape(a) /= [2, 3])) ok = .false.
    if (any(lbound(a) /= [1, 1])) ok = .false.
    if (any(lbound(b) /= [0, 1])) ok = .false.
    if (any(ubound(b) /= [2, 3])) ok = .false.
    a = 1.0
    b = 2.0
    if (sum(a) /= 6.0) ok = .false.
    if (sum(b) /= 18.0) ok = .false.
  end subroutine

  ! 2. Irreducible bound paired with a constant rank-1 bound on the other side.
  !    The constant array is folded into per-dimension bounds at declaration;
  !    the declared rank must survive in both orientations.
  subroutine test_irreducible_with_constant()
    ok = .true.
    call check_irreducible_with_constant([2, 3], [9, 9], [.true., .true.])
    call report("irreducible_with_constant")
  end subroutine

  subroutine check_irreducible_with_constant(n, m, c)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: c(2)
    real :: a([0, 3] : merge(n, m, c))   ! (0:2, 3:3)
    real :: d(merge(n, m, c) : [5, 5])   ! (2:5, 3:5)
    if (rank(a) /= 2 .or. rank(d) /= 2) ok = .false.
    if (any(lbound(a) /= [0, 3])) ok = .false.
    if (any(ubound(a) /= [2, 3])) ok = .false.
    if (any(lbound(d) /= [2, 3])) ok = .false.
    if (any(ubound(d) /= [5, 5])) ok = .false.
    d = 1.0
    if (size(d) /= 12 .or. sum(d) /= 12.0) ok = .false.
  end subroutine

  ! 3. Inquiries of an irreducible array used as other arrays' bounds.
  !    UBOUND(a,dim) and SIZE(a,dim) with the default lower bound of 1;
  !    the rank-1 UBOUND(a) as a bounds array in its own right; and
  !    LBOUND(a):UBOUND(a).
  subroutine test_inquiry_of_irreducible()
    ok = .true.
    call check_inquiry_of_irreducible([2, 5], [7, 7], [.true., .true.])
    call report("inquiry_of_irreducible")
  end subroutine

  subroutine check_inquiry_of_irreducible(n, m, c)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: c(2)
    real :: a(merge(n, m, c))          ! (2, 5)
    real :: b(ubound(a, 2))            ! (5)
    real :: e(size(a, 1))              ! (2)
    real :: f(ubound(a))               ! (2, 5)
    real :: g(lbound(a) : ubound(a))   ! (1:2, 1:5)
    real :: h(size(a))                 ! (10)
    if (size(b) /= 5 .or. size(e) /= 2 .or. size(h) /= 10) ok = .false.
    if (rank(f) /= 2 .or. any(shape(f) /= [2, 5])) ok = .false.
    if (any(lbound(g) /= [1, 1]) .or. any(ubound(g) /= [2, 5])) ok = .false.
    f = 3.0
    g = 4.0
    if (sum(f) /= 30.0 .or. sum(g) /= 40.0) ok = .false.
  end subroutine

  ! 4. With a lower bound of 0 neither UBOUND nor LBOUND equals the extent, so
  !    SIZE(a,dim) must remain a run-time inquiry rather than fold; and an
  !    inquiry of TRANSPOSE(a) must not trip the compiler.
  subroutine test_lb0_inquiry_and_transpose()
    real :: actual(15)
    ok = .true.
    call check_lb0_inquiry_and_transpose([2, 4], [8, 8], [.true., .true.], actual)
    call report("lb0_inquiry_and_transpose")
  end subroutine

  subroutine check_lb0_inquiry_and_transpose(n, m, c, a)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: c(2)
    real, intent(inout) :: a(0 : merge(n, m, c))   ! (0:2, 0:4)
    real :: g(size(a, 2))                          ! (5)
    real :: w(ubound(transpose(a), 1))             ! (5)
    if (size(a) /= 15) ok = .false.
    if (size(g) /= 5 .or. size(w) /= 5) ok = .false.
    a = 1.0
    g = 1.0
    if (sum(a) /= 15.0 .or. sum(g) /= 5.0) ok = .false.
  end subroutine

  ! 5. Two different irreducible bases supplying bounds of one array.  Each
  !    base must be evaluated for its own dimension; collapsing them onto one
  !    would give the wrong shape and write past the declared extent.
  subroutine test_two_irreducible_bases()
    ok = .true.
    call check_two_irreducible_bases([3, 7], [5, 9], [.true., .false.])
    call report("two_irreducible_bases")
  end subroutine

  subroutine check_two_irreducible_bases(n, k, c)
    integer, intent(in) :: n(2), k(2)
    logical, intent(in) :: c(2)
    real :: b(merge(n, k, c))                  ! (3, 9)
    real :: d(merge(k, n, c))                  ! (5, 7)
    real :: out(ubound(b, 2), ubound(d, 2))    ! (9, 7)
    if (any(shape(out) /= [9, 7])) ok = .false.
    out = 1.0
    if (size(out) /= 63 .or. sum(out) /= 63.0) ok = .false.
  end subroutine

  ! 6. A scalar bound in one dimension and an inquiry of a rank-1-bounded
  !    array in the other; the scalar must not be broadcast.  The bounds
  !    array m is itself reducible (each bound is m(dim)); what is exercised
  !    is mixing a scalar bound with an inquiry of such an array.
  subroutine test_scalar_and_inquiry()
    ok = .true.
    call check_scalar_and_inquiry(4, [2, 7])
    call report("scalar_and_inquiry")
  end subroutine

  subroutine check_scalar_and_inquiry(n, m)
    integer, intent(in) :: n, m(2)
    real :: b(m)                        ! (2, 7)
    real :: out(n, ubound(b, 2))        ! (4, 7)
    if (any(shape(out) /= [4, 7])) ok = .false.
    out = 1.0
    if (sum(out) /= 28.0) ok = .false.
  end subroutine

  ! 7. A derived-type component array as the bounds array: x%c is rank 1, so
  !    the extracted element must be x(dim)%c, keeping each bound scalar.
  subroutine test_component_base()
    ok = .true.
    call check_component_base()
    call report("component_base")
  end subroutine

  subroutine check_component_base()
    type(t) :: x(2)
    x = [t(3), t(6)]
    call check_component_base_inner(x)
  end subroutine

  subroutine check_component_base_inner(x)
    type(t), intent(in) :: x(2)
    real :: a(x%c)               ! (3, 6)
    real :: b(ubound(a, 2))      ! (6)
    if (rank(a) /= 2 .or. any(shape(a) /= [3, 6])) ok = .false.
    if (rank(b) /= 1 .or. size(b) /= 6) ok = .false.
  end subroutine

  ! 8. EQUIVALENCE uses the declared bounds to compute storage offsets; a
  !    constant rank-1 bounds array must place elements exactly as the
  !    equivalent explicit-shape-spec-list would.
  subroutine test_equivalence_constant_bounds()
    real :: a([3, 4]), b(12)
    real :: p([0, 0] : [2, 3]), q(12)
    equivalence (a(2, 3), b(1))    ! a(2,3) is element 8 of a
    equivalence (p(1, 2), q(1))    ! p(1,2) is element 8 of p
    ok = .true.
    a = 0.0
    a(2, 3) = 5.0
    a(3, 4) = 7.0
    if (b(1) /= 5.0 .or. b(5) /= 7.0) ok = .false.
    p = 0.0
    p(1, 2) = 5.0
    p(2, 3) = 7.0
    if (q(1) /= 5.0 .or. q(5) /= 7.0) ok = .false.
    call report("equivalence_constant_bounds")
  end subroutine

  ! 9. A constant all-ones rank-1 lower bound makes LBOUND a constant
  !    expression, exactly as a(1:n) does.
  subroutine test_constant_ones_lbound()
    ok = .true.
    call check_constant_ones_lbound([4, 5])
    call report("constant_ones_lbound")
  end subroutine

  subroutine check_constant_ones_lbound(n)
    integer, intent(in) :: n(2)
    integer, parameter :: ones(2) = 1
    real :: a(ones : n)
    real :: b([1, 1] : n)
    integer, parameter :: la = lbound(a, 1), lb2 = lbound(b, 2)
    if (la /= 1 .or. lb2 /= 1) ok = .false.
    if (any(lbound(a) /= 1) .or. any(ubound(b) /= [4, 5])) ok = .false.
  end subroutine

  ! 10. max(c, max(c, x)) is simplified only for a repeated constant c.  A
  !     host dummy and an internal procedure's dummy at the same argument
  !     position are different variables, so a bound nesting them must keep
  !     both operands.
  subroutine test_extremum_fold()
    ok = .true.
    call check_extremum_host(7, ok)
    call report("extremum_fold")
  end subroutine

  ! 11. An empty dimension of an irreducible array.  LBOUND is 1 and UBOUND
  !     is 0 there regardless of the declared 4:2, so an array bounded by
  !     those inquiries is empty, while the nonempty dimension keeps its
  !     declared bounds.  The rank-1 LBOUND(a) as a bounds array must see
  !     the same 1 for the empty dimension.
  subroutine test_empty_dimension()
    ok = .true.
    call check_empty_dimension([3, 4], [9, 9], [.true., .true.], [5, 2], [7, 7])
    call report("empty_dimension")
  end subroutine

  subroutine check_empty_dimension(lo, lo2, c, hi, hi2)
    integer, intent(in) :: lo(2), lo2(2), hi(2), hi2(2)
    logical, intent(in) :: c(2)
    real :: a(merge(lo, lo2, c) : merge(hi, hi2, c))   ! (3:5, 4:2)
    real :: b(lbound(a, 2) : ubound(a, 2))              ! (1:0)
    real :: d(lbound(a, 1) : ubound(a, 1))              ! (3:5)
    real :: e(lbound(a))                                ! (3, 1)
    if (any(shape(a) /= [3, 0]) .or. size(a) /= 0) ok = .false.
    if (any(lbound(a) /= [3, 1]) .or. any(ubound(a) /= [5, 0])) ok = .false.
    if (rank(e) /= 2 .or. any(shape(e) /= [3, 1])) ok = .false.
    if (size(b) /= 0 .or. size(d) /= 3) ok = .false.
    if (lbound(d, 1) /= 3 .or. ubound(d, 1) /= 5) ok = .false.
  end subroutine

  ! 12. Polymorphic explicit-shape dummies are tracked through a descriptor,
  !     so their rank-1 bounds take the descriptor lowering path; with upper
  !     bounds only and with both bounds irreducible.
  subroutine test_polymorphic_dummy()
    type(t) :: x(6), y(15)
    ok = .true.
    x%c = 0
    y%c = 0
    call check_polymorphic_dummy(x, y, [2, 3], [7, 7], [.true., .true.], &
                                 [0, -1], [5, 5])
    if (any(x%c /= 9) .or. any(y%c /= 4)) ok = .false.
    call report("polymorphic_dummy")
  end subroutine

  subroutine check_polymorphic_dummy(x, y, n, m, c, lo, lo2)
    integer, intent(in) :: n(2), m(2), lo(2), lo2(2)
    logical, intent(in) :: c(2)
    class(t), intent(inout) :: x(merge(n, m, c))                      ! (2, 3)
    class(t), intent(inout) :: y(merge(lo, lo2, c) : merge(n, m, c))  ! (0:2, -1:3)
    if (any(shape(x) /= [2, 3])) ok = .false.
    if (any(lbound(y) /= [0, -1]) .or. any(ubound(y) /= [2, 3])) ok = .false.
    if (size(y) /= 15) ok = .false.
    x%c = 9
    y%c = 4
  end subroutine

end program declaration_explicit_array_bounds_irreducible
