! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 12.4.3.4.5, R1207, C1214

! ====================
! A-4
! B-2
! ====================
module chain_core
  use, intrinsic :: iso_fortran_env, only: int32
  implicit none

  type chain32
     integer(int32) :: data
     type(chain32), pointer :: next
  end type chain32

end module chain_core

module chain_write
  use chain_core
  implicit none
  
  interface write(formatted)
     procedure write_chain_a, write_chain_b
  end interface write(formatted)

contains

  subroutine write_chain_a(ch, unit, iotype, vlist, iostat, iomsg)
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

  end subroutine write_chain_a

  subroutine write_chain_b(ch, unit, iotype, vlist, iostat, iomsg)
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

  end subroutine write_chain_b

end module chain_write

program main
  use chain_write
  type(chain32), pointer :: a

  ! initialize
  call chain32_init(a)

  ! write
  write(*, "(DT)") a

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

end program main

! FLANG: 35_genericResolution_c004.f90:25:
! FLANG-SAME: error:

! GFORT: 35_genericResolution_c004.f90:31:
! GFORT-NOT: .f90
! GFORT: Error: