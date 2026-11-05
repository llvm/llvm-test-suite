! Provider module for the module-file round-trip test.  Every declaration
! here is written to m_bounds_provider.mod and read back by the submodules
! and the consumer program, each compiled separately, so the bounds below
! must serialize to Fortran the module-file reader can re-analyze to the
! same shape.
!
! An elemental MERGE with a LOGICAL mask is irreducible: each dimension's
! bound is extracted at run time, and an inquiry of such an array that
! becomes another array's bound is written through its UBOUND()/LBOUND()
! provenance as the real intrinsic.
module m_bounds_provider
  implicit none

  ! A module variable with the same name as the local array inside
  ! make_result.  The result bound names the local, not this; the module
  ! file must declare the local ahead of the result that inquires it.
  real :: local_shape(2, 9)

  interface
    ! Separate module procedure whose dummy b depends on dummy z; the
    ! `module procedure` body in the child submodule inherits these
    ! declarations by copying them, and the grandchild calls it through
    ! the child's module file.
    module subroutine sep(n, m, c, b, z)
      integer, intent(in) :: n(2), m(2)
      logical, intent(in) :: c(2)
      real, intent(out) :: z(merge(n, m, c))
      real, intent(out) :: b(size(z, 2))
    end subroutine

    ! Separate module function whose result bound inquires a dummy.  The
    ! child submodule redeclares this function in full, so the result read
    ! back from the module file must compare equal to the body's own
    ! declaration: the extent max(0,ubound(z,2)) has to be a fixed point of
    ! the write/re-analyze cycle.
    module function g(n, m, c, z) result(r)
      integer, intent(in) :: n(2), m(2)
      logical, intent(in) :: c(2)
      real, intent(in) :: z(merge(n, m, c))
      real :: r(ubound(z, 2))
    end function

    ! Irreducible lower bound with a constant rank-1 upper bound.  The
    ! constant is folded into per-dimension bounds at declaration and must
    ! be written back as a rank-1 array so d reads back with rank 2.
    module subroutine reverse(n, m, c, d)
      integer, intent(in) :: n(2), m(2)
      logical, intent(in) :: c(2)
      real, intent(out) :: d(merge(n, m, c) : [5, 5])
    end subroutine

    ! Exercised from the grandchild submodule.
    module subroutine call_sep_from_grandchild(ok)
      logical, intent(inout) :: ok
    end subroutine
  end interface

contains

  function make_result(n, m, mask) result(r)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: mask(2)
    real :: local_shape(merge(n, m, mask))
    real :: r(ubound(local_shape, 2))
    r = 7.0
  end function

end module m_bounds_provider
