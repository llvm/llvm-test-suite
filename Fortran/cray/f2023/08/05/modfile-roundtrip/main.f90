! Consumer: uses m_bounds_provider from its module file and checks that
! every procedure's rank-1-derived bounds read back with the shapes they
! were declared with.
!
!   1. Result bound inquiring a local array that shadows a module variable
!   2. Separate module procedure called from a descendant submodule
!   3. Separate module function result bound inquiring a dummy, with the
!      body redeclared in full
!   4. Irreducible lower bound with a constant rank-1 upper bound
!   5. Bounds from a reference to a pure module function
program declaration_explicit_array_bounds_modfile
  use m_bounds_provider
  implicit none

  integer :: pass_count, fail_count
  logical :: ok
  pass_count = 0
  fail_count = 0

  call test_make_result()
  call test_grandchild_call()
  call test_module_function()
  call test_reverse()
  call test_function_bounds()

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

  ! 1. r(ubound(local_shape, 2)) where local_shape is the function's local
  !    array of shape merge(n, m, mask), not the module variable.
  subroutine test_make_result()
    real, allocatable :: x(:)
    ok = .true.
    x = make_result([2, 3], [4, 5], [.true., .true.])
    if (size(x) /= 3 .or. any(x /= 7.0)) ok = .false.
    x = make_result([2, 3], [4, 5], [.false., .false.])
    if (size(x) /= 5) ok = .false.
    call report("make_result_local_shadow")
  end subroutine

  ! 2. The grandchild submodule calls sep via the child's module file.
  subroutine test_grandchild_call()
    ok = .true.
    call call_sep_from_grandchild(ok)
    call report("grandchild_calls_sep")
  end subroutine

  ! 3. g's result r(ubound(z, 2)) with z(merge(n, m, c)), through a body
  !    that redeclares the interface in full.
  subroutine test_module_function()
    real :: z(2, 5)
    real, allocatable :: r(:)
    ok = .true.
    z = 0.0
    r = g([2, 5], [7, 7], [.true., .true.], z)
    if (size(r) /= 5 .or. any(r /= 3.0)) ok = .false.
    call report("module_function_result")
  end subroutine

  ! 4. reverse's d(merge(n, m, c) : [5, 5]) must be rank 2 with the
  !    irreducible lower bounds and the constant upper bounds.  reverse
  !    stores each element's subscripts in it, so the values show which
  !    lower bounds its body received.
  subroutine test_reverse()
    real :: d(2:5, 3:5)
    integer :: i, j
    ok = .true.
    d = 0.0
    call reverse([2, 3], [9, 9], [.true., .true.], d)
    if (any(d /= reshape([((real(10*i + j), i = 2, 5), j = 3, 5)], &
                         [4, 3]))) ok = .false.
    call report("reverse_orientation")
  end subroutine

  ! 5. sep_by_function's z(make_bounds(k)) and the b(size(z, 2)) that
  !    inquires it: a bounds array that is irreducible by construction.
  subroutine test_function_bounds()
    real :: b(6), z(3, 6)
    integer :: i, j
    ok = .true.
    b = 0.0
    z = 0.0
    call sep_by_function(3, b, z)
    if (any(b /= [1.0, 2.0, 3.0, 4.0, 5.0, 6.0])) ok = .false.
    if (any(z /= reshape([((real(10*i + j), i = 1, 3), j = 1, 6)], &
                         [3, 6]))) ok = .false.
    call report("function_bounds")
  end subroutine

end program declaration_explicit_array_bounds_modfile
