program rank_dummy_select_intrinsic
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

contains

  subroutine print_rank(a)
    integer a(..)
    character(len=*), parameter :: format_='(a,i2)'

    select rank(a)
      rank(0)
        print format_,"rank(a) = ",rank(a)
      rank(1)
        print format_,"rank(a) = ",rank(a)
      rank(2)
        print format_,"rank(a) = ",rank(a)
      rank(3)
        print format_,"rank(a) = ",rank(a)
      rank(4)
        print format_,"rank(a) = ",rank(a)
      rank(5)
        print format_,"rank(a) = ",rank(a)
      rank(6)
        print format_,"rank(a) = ",rank(a)
      rank(7)
        print format_,"rank(a) = ",rank(a)
      rank(8)
        print format_,"rank(a) = ",rank(a)
      rank(9)
        print format_,"rank(a) = ",rank(a)
      rank(10)
        print format_,"rank(a) = ",rank(a)
      rank(11)
        print format_,"rank(a) = ",rank(a)
      rank(12)
        print format_,"rank(a) = ",rank(a)
      rank(13)
        print format_,"rank(a) = ",rank(a)
      rank(14)
        print format_,"rank(a) = ",rank(a)
      rank(15)
        print format_,"rank(a) = ",rank(a)
      rank default
        error stop "unrecognized rank"
    end select
  end subroutine

end program rank_dummy_select_intrinsic
