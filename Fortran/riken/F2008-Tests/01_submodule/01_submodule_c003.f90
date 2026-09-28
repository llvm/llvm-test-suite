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
contains
  integer function second()
    second = 2
  end function second
end


submodule(alpha:beta) gamma 
contains
  integer function third()
    third = 3
  end function third
end submodule beta             ! C-3


program main
  use alpha

  print *, first(), second(), third()
end program main
  

! FLANG: 01_submodule_c003.f90:38
! FLANG-SAME: error:

! GFORT:      01_submodule_c003.f90:38
! GFORT-NOT:  .f90
! GFORT:      Error

