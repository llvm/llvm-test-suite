! Child submodule: separate module procedure bodies.  `module procedure`
! bodies inherit the interface's dummies by copying them from
! m_bounds_provider.mod, so every bound that names another dummy (or an
! interface-local array) must still name the body's own copy.  g is instead
! redeclared in full, so its characteristics are compared against the ones
! read back from the module file.  This file's own module file,
! m_bounds_provider-child.mod, is read by the grandchild.
submodule(m_bounds_provider) child
  implicit none
contains

  module procedure sep
    z = 2.0
    b = 1.0
  end procedure

  module function g(n, m, c, z) result(r)
    integer, intent(in) :: n(2), m(2)
    logical, intent(in) :: c(2)
    real, intent(in) :: z(merge(n, m, c))
    real :: r(ubound(z, 2))
    r = 3.0
  end function

  module procedure reverse
    d = 5.0
  end procedure

end submodule child
