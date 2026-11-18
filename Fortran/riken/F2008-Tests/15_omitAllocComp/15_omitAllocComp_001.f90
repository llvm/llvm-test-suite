! SPEC: F2008 R455,C492

program main
    implicit none
    type my_type
        real,allocatable :: a
        integer i
    end type my_type
    type(my_type) :: t1, t2
    t1 = my_type(i=1)
    print *, 't1%i = ', t1%i
    print *, 'allocated = ', allocated(t1%a)
    t2 = my_type(i=2, a=null())
    print *, 't2%i = ', t2%i
    print *, 'allocated = ', allocated(t2%a)
end program
