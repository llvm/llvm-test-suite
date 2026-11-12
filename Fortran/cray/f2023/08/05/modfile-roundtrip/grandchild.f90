! Grandchild submodule: calls sep through the interface read back from
! m_bounds_provider-child.mod.  The child's module file must declare z
! before the b that inquires it, or the call is rejected with a rank
! mismatch.
submodule(m_bounds_provider:child) grandchild
  implicit none
contains

  module procedure call_sep_from_grandchild
    real :: bb(5), zz(2, 5)
    call sep([2, 5], [7, 7], [.true., .true.], bb, zz)
    if (any(bb /= 1.0) .or. any(zz /= 2.0)) ok = .false.
    if (size(bb) /= 5 .or. any(shape(zz) /= [2, 5])) ok = .false.
  end procedure

end submodule grandchild
