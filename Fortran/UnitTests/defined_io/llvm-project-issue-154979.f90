! A verbatim copy of test case from https://github.com/llvm/llvm-project/issues/154979
module llvm_project_issue_154979_m
    type base
        real, allocatable :: data(:)
        complex, allocatable :: cx(:)

        contains

        procedure :: readBaseFmtd
        generic :: read(formatted) => readBaseFmtd
    end type

    contains

    !! read in the array size before allocating dtv's components
    subroutine readBaseFmtd (dtv, unit, iotype, v_list, iostat, iomsg)
        class(base), intent(inout) :: dtv
        integer, intent(in) :: unit
        character(*), intent(in) :: iotype
        integer, intent(in) :: v_list(:)
        integer, intent(out) :: iostat
        character(*), intent(inout) :: iomsg

        integer isize

        read (unit, *, iostat = iostat, iomsg=iomsg) isize
        
        if (allocated(dtv%data)) deallocate (dtv%data)

        allocate (dtv%data(isize))

        read (unit, *, iostat=iostat, iomsg=iomsg) dtv%data
        read (unit, *, iostat = iostat, iomsg=iomsg) isize
        if (allocated(dtv%cx)) deallocate (dtv%cx)

        allocate (dtv%cx(isize))

        read (unit, *, iostat=iostat, iomsg=iomsg) dtv%cx
    end subroutine
end module

program llvm_project_issue_154979
    use llvm_project_issue_154979_m
    integer currentPos, ss

    type(base) :: b1(2)


    open (1, file='dcmlChildRead003.data', access='stream', form='formatted', &
            decimal='Comma')

    write (1, '(i4, 10(g15.7))', pos=1, decimal='Point') 10, (i*1.0, i=1, 10)

    inquire (1, pos=currentPos)

    write(1, *, pos=currentPos, decimal='point') 12, (cmplx(i*1.0, i*2.0), i=-12, -1)

    write (1, *) 20, (i*1.22, i=1,20)
    write (1, *, sign='plus') 22, (cmplx(i*1.1, i*2.2), i=-10,11)

    allocate (b1(1)%cx(3), b1(2)%data(1000))
    read (1, '(dp, dt, dc, dt)', pos=1) b1

    print*, size(b1(1)%data)
    print*, size(b1(1)%cx)
end program
