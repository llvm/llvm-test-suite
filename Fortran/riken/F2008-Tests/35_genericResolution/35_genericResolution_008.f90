! SPEC: F2008 12.4.3.4.5, R1207, C1214

! ====================
! A-4
! B-1
! ====================
module chain_core
  use, intrinsic :: iso_fortran_env, only: int32, int64
  implicit none

  type chain32
     integer(int32) :: data
     type(chain32), pointer :: next
  end type chain32

  type chain64
     integer(int64) :: data
     type(chain64), pointer :: next
  end type chain64

end module chain_core

module chain_write
  use chain_core
  implicit none
  
  interface write(formatted)
     procedure write_chain32, write_chain64
  end interface write(formatted)

contains

  subroutine write_chain32(ch, unit, iotype, vlist, iostat, iomsg)
    class(chain32), intent(in) :: ch
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: vlist(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg

    type(chain32) :: ch1
    integer :: w                ! w of 'DT(w)', or 0 for 'DT'
    character(10) :: fmt1
    
    select case (size(vlist))
    case (0)
       w = 0
    case (1)
       w = vlist(1)
    case default
       error stop "WRITE statement requires &
            &zero or one argument for DT in TYPE(chain32)."
    end select

    write(fmt1, "('(I',I0,',','A)')") w

    ch1 = ch
    do while (associated(ch1%next))
       write(unit, fmt=fmt1, advance='no') ch1%data, ' --> '
       ch1 = ch1%next
    end do
    write(unit, fmt=fmt1) ch1%data, ''

  end subroutine write_chain32

  subroutine write_chain64(ch, unit, iotype, vlist, iostat, iomsg)
    class(chain64), intent(in) :: ch
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: vlist(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg

    type(chain64) :: ch1
    integer :: w                ! w of 'DT(w)', or 0 for 'DT'
    character(10) :: fmt1
    
    select case (size(vlist))
    case (0)
       w = 0
    case (1)
       w = vlist(1)
    case default
       error stop "WRITE statement requires &
            &zero or one argument for DT in TYPE(chain64)."
    end select

    write(fmt1, "('(I',I0,',','A)')") w

    ch1 = ch
    do while (associated(ch1%next))
       write(unit, fmt=fmt1, advance='no') ch1%data, ' --> '
       ch1 = ch1%next
    end do
    write(unit, fmt=fmt1) ch1%data, ''

  end subroutine write_chain64

end module chain_write

program main
  use chain_write
  type(chain32), pointer :: a
  type(chain64), pointer :: b

  ! initialize
  call chain32_init(a)
  call chain64_init(b)

  ! write chain32
  write(*, "(DT(10))") a
  write(*, "(DT)") a

  ! write chain64
  write(*, "(DT(19))") b
  write(*, "(DT)") b

contains

  subroutine chain32_init(x)
    type(chain32), pointer, intent(out) :: x
    type(chain32), pointer :: c1, c2, c3, c4
    integer(int32), parameter :: max_int32 = huge(0_int32)
    
    allocate(c1, c2, c3, c4)

    c1%data = 123
    c2%data = 1234
    c3%data = 12
    c4%data = max_int32

    c1%next => c2
    c2%next => c3
    c3%next => c4
    c4%next => null()

    x => c1

  end subroutine chain32_init

  subroutine chain64_init(x)
    type(chain64), pointer, intent(out) :: x
    type(chain64), pointer :: c1, c2, c3, c4
    integer(int64), parameter :: max_int64 = huge(0_int64)
    
    allocate(c1, c2, c3, c4)

    c1%data = 123
    c2%data = 1234
    c3%data = 12
    c4%data = max_int64

    c1%next => c2
    c2%next => c3
    c3%next => c4
    c4%next => null()

    x => c1

  end subroutine chain64_init

end program main
