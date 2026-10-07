! SPEC: F2008 R448 R449

module m
  implicit none

  type :: t
    integer :: v = 0
  contains
    procedure :: p1, p2
    procedure, pass :: p3, p4
    procedure :: a => p5, b => p6
    procedure, pass :: c => p7, d => p8
  end type

contains

  subroutine p1(this)
    class(t) :: this
    this%v = this%v + 1
  end

  subroutine p2(this)
    class(t) :: this
    this%v = this%v + 2
  end

  subroutine p3(this)
    class(t) :: this
    this%v = this%v + 3
  end

  subroutine p4(this)
    class(t) :: this
    this%v = this%v + 4
  end

  subroutine p5(this)
    class(t) :: this
    this%v = this%v + 5
  end

  subroutine p6(this)
    class(t) :: this
    this%v = this%v + 6
  end

  subroutine p7(this)
    class(t) :: this
    this%v = this%v + 7
  end

  subroutine p8(this)
    class(t) :: this
    this%v = this%v + 8
  end

end module

program main
  use m
  implicit none

  type(t) :: obj

  call obj%p1()
  call obj%p2()
  call obj%p3()
  call obj%p4()
  call obj%a()
  call obj%b()
  call obj%c()
  call obj%d()

  print *, obj%v

end program
