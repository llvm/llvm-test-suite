! Child submodule: separate module procedure bodies.  `module procedure`
! bodies inherit the interface's dummies by copying them from
! m_bounds_provider.mod, so every bound that names another dummy (or an
! interface-local array) must still name the body's own copy.  g is instead
! redeclared in full, so its characteristics are compared against the ones
! read back from the module file.  This file's own module file,
! m_bounds_provider-child.mod, is read by the grandchild.
!
! The dummies are explicit shape, so a caller passes storage by sequence
! association and cannot see the bounds a body received.  Each body
! therefore stores every element's own subscripts in it, over the dummy's
! own LBOUND/UBOUND, and the callers check the values: bounds that read
! back permuted or shifted leave different values in the caller's array.
submodule(m_bounds_provider) child
  implicit none
contains

  module procedure sep
    integer :: i, j
    do j = lbound(z, 2), ubound(z, 2)
      do i = lbound(z, 1), ubound(z, 1)
        z(i, j) = 10*i + j
      end do
    end do
    b = [(real(i), i = 1, size(b))]
  end procedure

  module function g(n, m, c, z) result(r)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: c(2)
    real, intent(in) :: z(merge(n, m, c))
    real :: r(ubound(z, 2))
    r = 3.0
  end function

  module procedure reverse
    integer :: i, j
    do j = lbound(d, 2), ubound(d, 2)
      do i = lbound(d, 1), ubound(d, 1)
        d(i, j) = 10*i + j
      end do
    end do
  end procedure

  module procedure sep_by_function
    integer :: i, j
    do j = lbound(z, 2), ubound(z, 2)
      do i = lbound(z, 1), ubound(z, 1)
        z(i, j) = 10*i + j
      end do
    end do
    b = [(real(i), i = 1, size(b))]
  end procedure

end submodule child
