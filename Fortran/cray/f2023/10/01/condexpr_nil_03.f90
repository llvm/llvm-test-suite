! Test for conditional arguments (Fortran 2023)

module M_condexpr_nil_03
contains
  subroutine test1(idx, A)
    implicit none
    integer           :: idx, i
    integer, optional :: A(:)
    integer           :: B(10)

    B = [(10*i, i=1,10)]

    call test2( A, B, (idx == 1 ? [(i, i=1,5)] : &
                       idx == 2 ? B(1:10:2)    : &
                       idx == 3 ? .nil.        : &
                                  f(B(2))) )
    if ( present(A) ) then
       B = -B
    endif
    print '(I2,"  B: ",(I6))', B

  contains
    subroutine test2( X, Y, Z )
      implicit none
      integer, optional :: X(:), Z(5)
      integer           :: Y(5)
      if ( present(X) ) then
         X = 3 * Y
      endif
      if ( present(Z) ) then
         Y = Y + Z
      endif
    end subroutine test2
  end subroutine test1

  function f(ival) result(ans)
    integer :: ival, ans(5)
    do i = 1, 5
       ans(i) = ival * i**2
    enddo
  end function f

end module M_condexpr_nil_03

program main
  use M_condexpr_nil_03
  implicit none
  integer :: AA(5), i
  do i = 1, 4
     call test1(i)
  enddo
  do i = 1, 4
     call test1(i, AA)
     print '(I2," AA: ",5I6)', i, AA
  enddo
end program main
