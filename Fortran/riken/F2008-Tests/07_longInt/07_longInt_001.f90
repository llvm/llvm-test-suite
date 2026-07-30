! SPEC: F2008 R404 

program main
  implicit none
  integer, parameter :: long = selected_int_kind(18)

  call decl_nokind()
  call decl_kind()
  call literal_nokind()
  call intrinsic_int_nokind()

contains

  ! Decl without KIND=
  subroutine decl_nokind()
    integer(long) :: a
    a = 10
    print *, kind(a), ",", range(a), ",", a
  end subroutine
  
  ! Decl with KIND=
  subroutine decl_kind()
    integer(kind=long) :: b
    b = 20
    print *, kind(b), ",", range(b), ",", b
  end subroutine
  
  ! literal without KIND
  subroutine literal_nokind()
    print *, kind(30_long), ",", range(30_long), ",", 30_long
  end subroutine

  ! intrinsic func INT(A, KIND)
  subroutine intrinsic_int_nokind()
    real :: x = 40.7
    print *, kind(int(x, selected_int_kind(18))), ",", &
             range(int(x, selected_int_kind(18))),",", &
             int(x, selected_int_kind(18))
  end subroutine

end program
