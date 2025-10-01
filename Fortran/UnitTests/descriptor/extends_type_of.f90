module extends_type_of_mod

  type p1
    integer :: a
  end type

  type, extends(p1) :: p2
    integer :: b
  end type
 
  type k1(a)
    integer, kind :: a
  end type

contains
  subroutine check_extended_type(a, b, expect, label)
    class(*) :: a
    class(*) :: b
    character(len=20) :: label
    character(len=6) :: check_result
    logical :: expect
    if (extends_type_of(a, b) .eqv. expect) then
      check_result = "passed"
    else
      check_result = "FAILED"
    end if
    print *, check_result, ": ", trim(label)
  end subroutine
  subroutine check_extended_type_pointer(a, b, expect, label)
    class(*), pointer :: a
    class(*), pointer :: b
    character(len=20) :: label
    character(len=6) :: check_result
    logical :: expect
    if (extends_type_of(a, b) .eqv. expect) then
      check_result = "passed"
    else
      check_result = "FAILED"
    end if
    print *, check_result, ": ", trim(label)
  end subroutine
  subroutine check_extended_type_allocatable(a, b, expect, label)
    class(*), allocatable :: a
    class(*), allocatable :: b
    character(len=20) :: label
    character(len=6) :: check_result
    logical :: expect
    if (extends_type_of(a, b) .eqv. expect) then
      check_result = "passed"
    else
      check_result = "FAILED"
    end if
    print *, check_result, ": ", trim(label)
  end subroutine
end module

program test
  use extends_type_of_mod
  type(p1), target :: p, r
  type(p2), target :: q
  type(k1(10)), target :: k10
  type(k1(20)), target :: k20
  integer, target :: i1, i2
  integer(kind=8), target :: i3
  real, target :: f
  
  class(*), pointer :: null_cp => null()
  class(*), pointer :: pp => p, qp => q, rp => r
  class(*), pointer :: k10p => k10, k20p => k20
  class(*), pointer :: i1p => i1, i2p => i2, i3p => i3, fp => f

  class(*), allocatable :: unalloc
  class(*), allocatable :: pa, qa, ra
  class(*), allocatable :: k10a, k20a
  class(*), allocatable :: i1a, i2a, i3a, fa

  allocate(pa, source=p)
  allocate(qa, source=q)
  allocate(ra, source=r)
  allocate(k10a, source=k10)
  allocate(k20a, source=k20)
  allocate(i1a, source=i1)
  allocate(i2a, source=i2)
  allocate(i3a, source=i3)
  allocate(fa, source=f)

  call check_extended_type(p, p, .true., "p <: p")
  call check_extended_type(p, q, .false., "p <: q")
  call check_extended_type(q, p, .true., "q <: p")
  call check_extended_type(p, r, .true., "p <: r")
  call check_extended_type(k10, k20, .false., "k10 <: k20")
  call check_extended_type(k20, k10, .false., "k20 <: k10")
  call check_extended_type(k10, k10, .true., "k10 <: k10")
  call check_extended_type(k20, k20, .true., "k20 <: k10")
  call check_extended_type(i1, i2, .true., "i1 <: i2")
  call check_extended_type(i2, i1, .true., "i1 <: i2")
  call check_extended_type(f, f, .true., "f <: f")
  call check_extended_type(i1, i3, .false., "i1 <: i3")
  call check_extended_type(i3, i1, .false., "i3 <: i1")
  call check_extended_type(i1, f, .false., "i1 <: f")
  call check_extended_type(f, i1, .false., "f <: i1")
  
  ! Repeating above tests with pointers
  call check_extended_type_pointer(pp, pp, .true., "pp <: pp")
  call check_extended_type_pointer(pp, qp, .false., "pp <: qp")
  call check_extended_type_pointer(qp, pp, .true., "qp <: pp")
  call check_extended_type_pointer(qp, rp, .true., "qp <: rp")
  call check_extended_type_pointer(k10p, k20p, .false., "k10p <: k20p")
  call check_extended_type_pointer(k20p, k10p, .false., "k20p <: k10p")
  call check_extended_type_pointer(k10p, k10p, .true., "k10p <: k10p")
  call check_extended_type_pointer(k20p, k20p, .true., "k20p <: k20p")
  call check_extended_type_pointer(i1p, i2p, .true., "i1p <: i2p")
  call check_extended_type_pointer(i2p, i1p, .true., "i2p <: i1p")
  call check_extended_type_pointer(fp, fp, .true., "fp <: fp")
  call check_extended_type_pointer(i1p, i3p, .false., "i1p <: i3p")
  call check_extended_type_pointer(i3p, i1p, .false., "i3p <: i1p")
  call check_extended_type_pointer(i1p, fp, .false., "i1p <: fp")
  call check_extended_type_pointer(fp, i1p, .false., "fp <: i1p")
  ! Checking rules with null pointers  
  call check_extended_type_pointer(null_cp, pp, .false., "null_cp <: pp")
  call check_extended_type_pointer(pp, null_cp, .true., "pp <: null_cp")
  call check_extended_type_pointer(null_cp, k10p, .false., "null_cp <: k10p")
  call check_extended_type_pointer(k10p, null_cp, .true., "k10p <: null_cp")
  call check_extended_type_pointer(fp, null_cp, .true., "fp <: null_cp")
  call check_extended_type_pointer(null_cp, fp, .false., "null_cp <: fp")
  call check_extended_type_pointer(null_cp, null_cp, .true., "null_cp <: null_cp")
  
  ! Repeating above tests with allocatables
  call check_extended_type_allocatable(pa, pa, .true., "pa <: pa")
  call check_extended_type_allocatable(pa, qa, .false., "pa <: qa")
  call check_extended_type_allocatable(qa, pa, .true., "qa <: pa")
  call check_extended_type_allocatable(qa, ra, .true., "qa <: ra")
  call check_extended_type_allocatable(k10a, k20a, .false., "k10a <: k20a")
  call check_extended_type_allocatable(k20a, k10a, .false., "k20a <: k10a")
  call check_extended_type_allocatable(k10a, k10a, .true., "k10a <: k10a")
  call check_extended_type_allocatable(k20a, k20a, .true., "k20a <: k20a")
  call check_extended_type_allocatable(i1a, i2a, .true., "i1a <: i2a")
  call check_extended_type_allocatable(i2a, i1a, .true., "i2a <: i1a")
  call check_extended_type_allocatable(fa, fa, .true., "fa <: fa")
  call check_extended_type_allocatable(i1a, i3a, .false., "i1a <: i3a")
  call check_extended_type_allocatable(i3a, i1a, .false., "i3a <: i1a")
  call check_extended_type_allocatable(i1a, fa, .false., "i1a <: fa")
  call check_extended_type_allocatable(fa, i1a, .false., "fa <: i1a")
  ! Checking rules with unallocated allocatables
  call check_extended_type_allocatable(unalloc, pa, .false., "unalloc <: pa")
  call check_extended_type_allocatable(pa, unalloc, .true., "pa <: unalloc")
  call check_extended_type_allocatable(unalloc, k10a, .false., "unalloc <: k10a")
  call check_extended_type_allocatable(k10a, unalloc, .true., "k10a <: unalloc")
  call check_extended_type_allocatable(fa, unalloc, .true., "fa <: unalloc")
  call check_extended_type_allocatable(unalloc, fa, .false., "unalloc <: fa")
  call check_extended_type_allocatable(unalloc, unalloc, .true., "unalloc <: unalloc")
end
