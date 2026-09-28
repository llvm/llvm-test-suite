! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s
! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s

! SPEC: F2008 C535 An implied-shape array shall be a named constant.


program err_C535
  character  :: d(*,*) = reshape([ 'How', 'do ', 'you', 'do ' ], [2,2])   ! "parameter" is required.

end program err_C535


! GFORT: 09_impliedShape_c003.f90:8:
! GFORT-NOT: .f90
! GFORT: Error

! FLANG: 09_impliedShape_c003.f90:8:
! FLANG-SAME: error:
 
