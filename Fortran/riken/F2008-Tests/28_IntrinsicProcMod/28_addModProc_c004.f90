! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:15.2.3.7 C SIZEOF

program main
  use iso_c_binding
  implicit none
  integer(c_short),dimension(10) :: b

  call sub(b)
  
contains

  subroutine sub(b)
    use iso_c_binding
    implicit none
    integer(c_short),dimension(*) :: b

    !========================
    ! A-3 c_sizeof(x)
    ! B-1 use module
    ! C-2 assumed-size array 
    ! D-1 interoperable data
    !========================
    print*,  c_sizeof(b)

  end subroutine

end program

! GFORT: 28_addModProc_c004.f90:26:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_addModProc_c004.f90:26:
! FLANG-SAME: error:
