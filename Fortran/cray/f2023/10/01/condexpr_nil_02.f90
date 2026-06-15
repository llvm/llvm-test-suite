! Test for conditional arguments (Fortran 2023)

module M_condexpr_nil_02
contains
  subroutine test1(idx, A, B, C)
    implicit none
    integer :: idx
    real    :: A(:), B(:), C(:)

    call test2( (idx == 1 ? A : idx == 2 ? B : idx == 3 ? C : .nil.) )

  contains
    subroutine test2(W)
      implicit none
      real, optional :: W(:)
      if ( present(W) ) W = 1.0
    end subroutine test2
  end subroutine test1
end module M_condexpr_nil_02

program main
  use M_condexpr_nil_02
  real :: X(5), Y(5), Z(5)

  do i = 1, 4
     X = 0.0; Y = 0.0; Z = 0.0
     call test1( i, X, Y, Z )
     print '(I2,": ",3F6.2)', i, X(1), Y(3), Z(5)
  enddo
end program main
