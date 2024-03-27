module check_rank_utilities

  private
  public :: print_rank

contains

  subroutine print_rank(a)
    integer a(..)

    select rank(a)
      rank(0)
        call check_rank(0,rank(a))
      rank(1)
        call check_rank(1,rank(a))
      rank(2)
        call check_rank(2,rank(a))
      rank(3)
        call check_rank(3,rank(a))
      rank(4)
        call check_rank(4,rank(a))
      rank(5)
        call check_rank(5,rank(a))
      rank(6)
        call check_rank(6,rank(a))
      rank(7)
        call check_rank(7,rank(a))
      rank(8)
        call check_rank(8,rank(a))
      rank(9)
        call check_rank(9,rank(a))
      rank(10)
        call check_rank(10,rank(a))
      rank(11)
        call check_rank(11,rank(a))
      rank(12)
        call check_rank(12,rank(a))
      rank(13)
        call check_rank(13,rank(a))
      rank(14)
        call check_rank(14,rank(a))
      rank(15)
        call check_rank(15,rank(a))
      rank default
        error stop "unrecognized rank"
    end select
  end subroutine

  subroutine check_rank(select_val, intrinsic_val)
    integer, intent(in) :: select_val, intrinsic_val

    if (select_val.eq.intrinsic_val) then
      print '(a,i2)', "rank(a) = ", intrinsic_val
    else
      print *, "select rank value ", select_val, "doesn't match rank reported from `rank` intrinsic ", intrinsic_val
    end if
  end subroutine

end module

program rank_dummy_select_intrinsic
  use check_rank_utilities, only: print_rank
  implicit none
  integer a,     a1(1),   a2(1,1), a3(1,1,1), a4(1,1,1, 1), a5(1,1,1, 1,1), a6(1,1,1, 1,1,1), a7(1,1,1, 1,1,1, 1)
  integer a8(1,1,1, 1,1,1, 1,1), a9(1,1,1, 1,1,1, 1,1,1), a10(1,1,1, 1,1,1, 1,1,1, 1), a11(1,1,1, 1,1,1, 1,1,1, 1,1)
  integer a12(1,1,1, 1,1,1, 1,1,1, 1,1,1), a13(1,1,1, 1,1,1, 1,1,1, 1,1,1, 1), a14(1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1)
  integer a15(1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1)

  call print_rank(a)
  call print_rank(a1)
  call print_rank(a2)
  call print_rank(a3)
  call print_rank(a4)
  call print_rank(a5)
  call print_rank(a6)
  call print_rank(a7)
  call print_rank(a8)
  call print_rank(a9)
  call print_rank(a10)
  call print_rank(a11)
  call print_rank(a12)
  call print_rank(a13)
  call print_rank(a14)
  call print_rank(a15)

end program rank_dummy_select_intrinsic
