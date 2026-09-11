! Check that a BIND(C) derived type dummy argument with the VALUE attribute is
! passed correctly to a C function. A derived type that is larger than 16 bytes
! cannot be passed in registers on some targets, and is instead passed as a
! pointer to a copy made by the caller. This also checks that arguments
! following such a derived type are still passed correctly.

module m
  use iso_c_binding
  implicit none

  ! Small enough to be passed in registers.
  type, bind(c) :: t16
    character(c_char) :: a(16)
  end type

  ! The smallest size that is too large to be passed in registers.
  type, bind(c) :: t17
    character(c_char) :: a(17)
  end type

  type, bind(c) :: t128
    character(c_char) :: a(128)
  end type

  interface
    subroutine check_t16(x) bind(c, name="check_t16")
      import :: t16
      type(t16), value :: x
    end subroutine

    subroutine check_t17(x) bind(c, name="check_t17")
      import :: t17
      type(t17), value :: x
    end subroutine

    subroutine check_t128(x) bind(c, name="check_t128")
      import :: t128
      type(t128), value :: x
    end subroutine

    subroutine check_mixed(p, i, x, j) bind(c, name="check_mixed")
      import :: c_ptr, c_int, t128
      type(c_ptr), value :: p
      integer(c_int), value :: i
      type(t128), value :: x
      integer(c_int), value :: j
    end subroutine
  end interface

end module

program bind_c_value
  use iso_c_binding
  use m
  implicit none

  type(t16) :: x16
  type(t17) :: x17
  type(t128) :: x128
  integer :: i

  ! Use values in the range 1 to 127 so that they are positive whether or not
  ! the C compiler treats char as signed.
  do i = 1, 16
    x16%a(i) = char(mod(i - 1, 127) + 1)
  end do
  do i = 1, 17
    x17%a(i) = char(mod(i - 1, 127) + 1)
  end do
  do i = 1, 128
    x128%a(i) = char(mod(i - 1, 127) + 1)
  end do

  ! Each of these aborts if the argument did not arrive intact.
  call check_t16(x16)
  call check_t17(x17)
  call check_t128(x128)
  call check_mixed(c_null_ptr, 11, x128, 22)

  print *, 'All arguments passed correctly'

end program bind_c_value
