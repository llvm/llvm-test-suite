! SPEC: F2008 R404 

program main
  implicit none
  integer, parameter :: long = selected_int_kind(18)

  call forall_nokind()

contains

  ! FORALL index variable
  subroutine forall_nokind()
    integer(long) :: x(3)
    integer :: e(3)
    integer :: f(3)
    forall (integer(selected_int_kind(18)) :: i = 1:3)
      x(i) = 50_long
      e(i) = kind(i)
      f(i) = range(i)
    end forall
    print *, e, ",", f, ",", x
  end subroutine

end program
