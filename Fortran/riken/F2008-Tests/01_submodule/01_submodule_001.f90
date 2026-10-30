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
  module integer function second()
    second = 2
  end function second
end


submodule(alpha:beta) gamma
contains
  module integer function third()
    third = 3
  end function third
end submodule gamma


program main
  use alpha

  print *, first(), second(), third()
end program main
