! Test for conditional arguments (Fortran 2023)

module M_condexpr_nil_04
contains
  subroutine test1(idx, A)
    implicit none
    integer :: idx, i, A(10), B(10)

    B = [(10*i, i=1,10)]

    ! bad non-contiguous sections to contiguous actual.
    ! requires copy/restore in conjuction with cond-argument.

    call test2( (idx == 1 ? B(1:10:2) : B(2:10:2)) )

    A = B

  contains
    subroutine test2( X )
      implicit none
      integer, optional :: X(5)
      X = [(13*i, i = 1,5)]
    end subroutine test2
  end subroutine test1

  function f(ival) result(ans)
    integer :: ival, ans(5)
    do i = 1, 5
       ans(i) = ival * i**2
    enddo
  end function f

end module M_condexpr_nil_04

program main
  use M_condexpr_nil_04
  implicit none
  integer :: AA(10), i
  do i = 1, 2
     call test1(i, AA)
     print '(I2," AA: ",5I6)', i, AA
  enddo
end program main
