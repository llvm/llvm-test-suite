! Grandchild submodule: calls sep through the interface read back from
! m_bounds_provider-child.mod.  The child's module file must declare z
! before the b that inquires it, or the call is rejected with a rank
! mismatch.  sep stores each element's subscripts in it, so the values
! show whether z and b read back with the bounds they were declared with.
submodule(m_bounds_provider:child) grandchild
  implicit none
contains

  module procedure call_sep_from_grandchild
    real :: bb(5), zz(2, 5)
    integer :: i, j
    bb = 0.0
    zz = 0.0
    call sep([2, 5], [7, 7], [.true., .true.], bb, zz)
    if (any(bb /= [1.0, 2.0, 3.0, 4.0, 5.0])) ok = .false.
    if (any(zz /= reshape([((real(10*i + j), i = 1, 2), j = 1, 5)], &
                          [2, 5]))) ok = .false.
  end procedure

end submodule grandchild
