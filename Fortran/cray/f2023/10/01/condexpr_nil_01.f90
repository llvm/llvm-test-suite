! Test for conditional arguments (Fortran 2023)

module M_condexpr_nil_01
contains
  subroutine SO(X, Y, Z)
    real           :: X
    real, optional :: Y, Z
    if ( present(Y) ) then
       X = X + Y
       Y = 13.0
    endif
    X = X + ( present(Z) ? Z/2.0 : 1000.0 )
    if ( present(Z) ) Z = 666.0
  end subroutine SO
end module M_condexpr_nil_01

module TM_condexpr_nil_01
contains
    subroutine test(cc)
      use M_condexpr_nil_01
      logical :: cc(:)
      real :: A, B, C
      A =   1.0
      B =  10.0
      C = 100.0
      call SO( A, B, C )
      print '("1: ", 3F10.4)', A, B, C

      A =   2.0
      B =  20.0
      C = 200.0
      call SO( A, (cc(1) ? B : .nil.), (cc(2) ? .nil. : C) )
      print '("2: ", 3F10.4)', A, B, C

      A =   3.0
      B =  30.0
      C = 300.0
      call SO( A, (cc(3) ? B : .nil.), (cc(4) ? .nil. : C) )
      print '("3: ", 3F10.4)', A, B, C

      A =   4.0
      B =  40.0
      C = 400.0
      call SO( A, (cc(5) ? B : .nil.), (cc(6) ? .nil. : C) )
      print '("4: ", 3F10.4)', A, B, C

      A =   5.0
      B =  50.0
      C = 500.0
      call SO( A, (cc(7) ? B : .nil.), (cc(8) ? .nil. : C) )
      print '("5: ", 3F10.4)', A, B, C
    end subroutine test
end module TM_condexpr_nil_01

program main
  use TM_condexpr_nil_01
  logical, parameter :: F = .false.
  logical, parameter :: T = .true.
  call test( [ F, F, F, T, T, F, T, T ] )
end program main
