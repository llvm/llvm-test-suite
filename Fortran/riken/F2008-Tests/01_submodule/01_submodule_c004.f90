! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:11.2.3 Submodules


module alpha
  interface
     module integer function second()
     end function second
     module integer function third()
     end function third
  end interface

contains

  integer function first()
    first = 1
  end function first

end module alpha



submodule(alpha) beta
  integer :: x,f
100 format(A,I3)
  entry beta2
  f(x) = third()
contains
  integer function second()
    second = 2
    write(*,100) "What's wrong?", 3
  end function second
end submodule beta


submodule(alpha:beta) gamma 
contains
  integer function third()
    third = 3
  end function third
end submodule gamma


program main
  use alpha

  print *, first(), second(), third()
end program main
  

! FLANG: 01_submodule_c004.f90:27:
! FLANG-SAME: error:
! FLANG: 01_submodule_c004.f90:28:
! FLANG-SAME: error:
! FLANG: 01_submodule_c004.f90:29:
! FLANG-SAME: error:


! GFORT:      01_submodule_c004.f90:27:
! GFORT-NOT:  .f90
! GFORT:      Error
! GFORT:      01_submodule_c004.f90:28:
! GFORT-NOT:  .f90
! GFORT:      Error
! GFORT:      01_submodule_c004.f90:29:
! GFORT-NOT:  .f90
! GFORT:      Error


