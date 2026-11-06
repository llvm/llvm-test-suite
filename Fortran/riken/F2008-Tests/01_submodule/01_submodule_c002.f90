! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:11.2.3 Submodules


module foreign
  interface
     module integer function second()
     end function second
     module integer function third()
     end function third
  end interface

contains

  integer function first()
    first = 999
  end function first

end module foreign


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


submodule(foreign:beta) gamma 
contains
  integer function third()
    third = 3
  end function third
end submodule gamma


program main
  use alpha

  print *, first(), second(), third()
end program main
  

! FLANG: 01_submodule_c002.f90:49
! FLANG-SAME: error:

! GFORT:      Fatal Error:
! GFORT-NEXT: compilation terminated.

