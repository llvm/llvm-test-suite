!   1. Upper bound only (rank-1 ub, scalar lb=1)
!   2. Both lb:ub as rank-1
!   3. Scalar lb with rank-1 ub (broadcast)
!   4. Rank-1 lb with scalar ub (broadcast)
!   5. SHAPE of assumed-shape (runtime, can't fold)
!   6. 3D bounds
!   7. Function result shaped by rank-1
!   8. Loop re-evaluation (no stale state)
!   9. Element write/read correctness
!  10. Implied-do + array slices + arithmetic in bounds
!  11. Vector subscripts in bounds expressions
!  12. Block construct re-evaluation — bounds from enclosing scope
!  13. Zero-size bounds array — rank 0 (scalar)

module helpers
  implicit none
contains
  pure function make_bounds(n) result(r)
    integer, intent(in) :: n
    integer :: r(2)
    r = [n, n + 1]
  end function

  function shaped_result(src) result(r)
    integer, intent(in) :: src(:, :)
    integer :: r(shape(src))
    r = src + 1
  end function
end module helpers

program declaration_explicit_array_bounds
  use helpers
  implicit none

  integer :: pass_count, fail_count
  logical :: ok
  pass_count = 0
  fail_count = 0

  call test_ub_only()
  call test_both_lb_ub()
  call test_scalar_lb_rank1_ub()
  call test_rank1_lb_scalar_ub()
  call test_shape_of_assumed()
  call test_3d()
  call test_func_result()
  call test_loop_reeval()
  call test_element_access()
  call test_implied_do_slice_arith()
  call test_vector_subscript()
  call test_block_reeval()
  call test_zero_size_scalar()

  print *, ""
  print *, "RESULTS:", pass_count, "passed,", fail_count, "failed"
  if (fail_count > 0) stop 1
  ! stop 2

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

  ! 1. Upper bound only from rank-1 dummy arg (lb defaults to 1)
  subroutine test_ub_only()
    ok = .true.
    call check_ub_only([4, 6])
    call report("ub_only")
  end subroutine

  subroutine check_ub_only(ub)
    integer, intent(in) :: ub(2)
    integer :: a(ub)
    if (any(lbound(a) /= [1,1])) ok = .false.
    if (any(ubound(a) /= [4,6])) ok = .false.
  end subroutine

  ! 2. Both lower and upper bounds as rank-1
  subroutine test_both_lb_ub()
    ok = .true.
    call check_both_lb_ub([2, 3], [5, 8])
    call report("both_lb_ub")
  end subroutine

  subroutine check_both_lb_ub(lb, ub)
    integer, intent(in) :: lb(2), ub(2)
    integer :: a(lb:ub)
    if (any(lbound(a) /= [2, 3])) ok = .false.
    if (any(ubound(a) /= [5, 8])) ok = .false.
  end subroutine

  ! 3. Scalar lower bound, rank-1 upper bound (broadcast scalar lb)
  subroutine test_scalar_lb_rank1_ub()
    ok = .true.
    call check_scalar_lb_rank1_ub(3, [7, 10])
    call report("scalar_lb_rank1_ub")
  end subroutine

  subroutine check_scalar_lb_rank1_ub(lb, ub)
    integer, intent(in) :: lb
    integer, intent(in) :: ub(2)
    integer :: a(lb:ub)
    if (any(lbound(a) /= [3, 3])) ok = .false.
    if (any(ubound(a) /= [7, 10])) ok = .false.
  end subroutine

  ! 4. Rank-1 lower bound, scalar upper bound (broadcast scalar ub)
  subroutine test_rank1_lb_scalar_ub()
    ok = .true.
    call check_rank1_lb_scalar_ub([2, 5], 10)
    call report("rank1_lb_scalar_ub")
  end subroutine

  subroutine check_rank1_lb_scalar_ub(lb, ub)
    integer, intent(in) :: lb(2)
    integer, intent(in) :: ub
    integer :: a(lb:ub)
    if (any(lbound(a) /= [2, 5])) ok = .false.
    if (any(ubound(a) /= [10, 10])) ok = .false.
  end subroutine

  ! 5. SHAPE of assumed-shape dummy (runtime, unfoldable)
  subroutine test_shape_of_assumed()
    integer :: src(3, 5)
    ok = .true.
    call check_shape_of_assumed(src)
    call report("shape_of_assumed")
  end subroutine

  subroutine check_shape_of_assumed(src)
    integer, intent(in) :: src(:, :)
    integer :: a(shape(src))
    if (any(lbound(a) /= [1, 1])) ok = .false.
    if (any(ubound(a) /= [3, 5])) ok = .false.
  end subroutine

  ! 6. 3D — verifies element extraction works beyond rank 2
  subroutine test_3d()
    integer :: src(2, 3, 4)
    ok = .true.
    call check_3d(src)
    call report("3d")
  end subroutine

  subroutine check_3d(src)
    integer, intent(in) :: src(:, :, :)
    integer :: a(shape(src))
    if (size(a, 1) /= 2) ok = .false.
    if (size(a, 2) /= 3) ok = .false.
    if (size(a, 3) /= 4) ok = .false.
    if (size(a) /= 24) ok = .false.
  end subroutine

  ! 7. Function result variable shaped by rank-1 bounds
  subroutine test_func_result()
    integer :: src(3, 4), res(3, 4)
    ok = .true.
    src = 10
    res = shaped_result(src)
    if (any(res /= 11)) ok = .false.
    if (size(res, 1) /= 3) ok = .false.
    if (size(res, 2) /= 4) ok = .false.
    call report("func_result")
  end subroutine

  ! 8. Loop re-evaluation — different bounds each iteration
  subroutine test_loop_reeval()
    integer :: i
    ok = .true.
    do i = 1, 5
      call check_loop_reeval(i)
    end do
    call report("loop_reeval")
  end subroutine

  subroutine check_loop_reeval(n)
    integer, intent(in) :: n
    integer :: a(make_bounds(n))
    if (size(a, 1) /= n) ok = .false.
    if (size(a, 2) /= n + 1) ok = .false.
  end subroutine

  ! 9. Element write/read with custom lb:ub — proves memory layout is correct
  subroutine test_element_access()
    ok = .true.
    call check_element_access([2, 3], [5, 7])
    call report("element_access")
  end subroutine

  subroutine check_element_access(lb, ub)
    integer, intent(in) :: lb(2), ub(2)
    integer :: a(lb:ub)
    integer :: i, j
    do j = lb(2), ub(2)
      do i = lb(1), ub(1)
        a(i, j) = i * 100 + j
      end do
    end do
    if (a(2, 3) /= 203) ok = .false.
    if (a(5, 7) /= 507) ok = .false.
    if (a(3, 5) /= 305) ok = .false.
  end subroutine

  ! 10. Implied-do, array slices, and arithmetic combined in bounds
  subroutine test_implied_do_slice_arith()
    integer :: i
    ok = .true.
    call check_implied_do_slice_arith([(i*2, i=1,5)])  ! [2,4,6,8,10]
    call report("implied_do_slice_arith")
  end subroutine

  subroutine check_implied_do_slice_arith(raw)
    integer, intent(in) :: raw(5)
    integer :: i
    ! lb = raw(1:3) - [(i, i=1,3)]   = [2-1, 4-2, 6-3] = [1, 2, 3]
    ! ub = raw(3:5) + [(i-1, i=1,3)] = [6+0, 8+1, 10+2] = [6, 9, 12]
    integer :: a(raw(1:3) - [(i, i=1,3)] : raw(3:5) + [(i-1, i=1,3)])
    if (any(lbound(a) /= [1, 2, 3]))  ok = .false.
    if (any(ubound(a) /= [6, 9, 12]))  ok = .false.
    ! corner element access
    a = 0
    a(1, 2, 3) = 123
    a(6, 9, 12) = 6912
    if (a(1, 2, 3) /= 123)   ok = .false.
    if (a(6, 9, 12) /= 6912) ok = .false.
  end subroutine

  ! 11. Vector subscripts in bounds expressions
  subroutine test_vector_subscript()
    integer :: pool(6), idx(3)
    pool = [10, 3, 7, 1, 5, 12]
    idx = [4, 2, 5]
    ok = .true.
    call check_vector_subscript(pool, idx)
    call report("vector_subscript")
  end subroutine

  subroutine check_vector_subscript(pool, idx)
    integer, intent(in) :: pool(6), idx(3)
    ! pool(idx) = [pool(4), pool(2), pool(5)] = [1, 3, 5]
    integer :: a(pool(idx) : pool(idx) * 2 + 1)
    ! lb = pool(idx)         = [1, 3, 5]
    ! ub = pool(idx) * 2 + 1 = [1, 3, 5] * 2 + 1 = [3, 7, 11]
    if (any(lbound(a) /= [1, 3, 5]))  ok = .false.
    if (any(ubound(a) /= [3, 7, 11]))  ok = .false.
    ! corner access
    a = 0
    a(1, 3, 5) = 135
    a(3, 7, 11) = 3711
    if (a(1, 3, 5) /= 135)   ok = .false.
    if (a(3, 7, 11) /= 3711) ok = .false.
  end subroutine

  ! 12. Block construct re-evaluation — bounds from enclosing scope
  subroutine test_block_reeval()
    integer :: i, n
    ok = .true.
    do i = 1, 4
      n = i + 1
      block
        integer :: a(make_bounds(n))
        if (size(a, 1) /= n) ok = .false.
        if (size(a, 2) /= n + 1) ok = .false.
      end block
    end do
    call report("block_reeval")
  end subroutine

  ! 13. Zero-size bounds array declares a scalar (rank 0), not an array
  subroutine test_zero_size_scalar()
    ok = .true.
    call check_zero_size_scalar()
    call report("zero_size_scalar")
  end subroutine

  subroutine check_zero_size_scalar()
    integer, parameter :: nobounds(0) = [integer ::]
    ! rank of the entity = size of the bounds array = 0 -> scalar
    integer :: a(nobounds)
    integer :: b([integer::] : nobounds)
    integer :: c(999 : [integer::])
    integer :: d(nobounds : 999)
    if ((rank(a) /= 0) .or. &
        (rank(b) /= 0) .or. &
        (rank(c) /= 0) .or. &
        (rank(d) /= 0)) then
      ok = .false.
    endif
    a = 42            ! must behave as a scalar
    b = 43
    c = 44
    d = 45
    if ((a /= 42) .or. &
        (b /= 43) .or. &
        (c /= 44) .or. &
        (d /= 45)) then
      ok = .false.
    endif
  end subroutine

end program declaration_explicit_array_bounds
