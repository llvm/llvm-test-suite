! Test for conditional arguments (Fortran 2023)

module M_condexpr_nil_05
contains
  subroutine test1(idx, A)
    implicit none
    integer :: idx, i, A(10), B(10)

    B = [(10*i, i=1,10)]

    call test2( A, (idx  == 1 ? (idx == 2 ? err() : 23) + f(B) : .nil. ) )

  contains
     subroutine test2(A, X)
       integer           :: A(:)
       integer, optional :: X(:)
       if ( present(X) ) then
          A = X
       else
          A = 99
       endif
     end subroutine test2

     elemental function f(ival) result(ans)
       integer, intent(IN) :: ival
       integer             :: ans
       ans = ival**2
     end function f
  end subroutine test1

  function err() result(ans)
    integer ans
    ans = 0
    print *, 'ERROR: err should not have been called.'
  end function err

end module M_condexpr_nil_05

program main
  use M_condexpr_nil_05
  implicit none
  integer :: AA(10), i
  do i = 1, 2
     call test1(i, AA)
     print '(I2," AA: ",(I6))', i, AA
  enddo
end program main
