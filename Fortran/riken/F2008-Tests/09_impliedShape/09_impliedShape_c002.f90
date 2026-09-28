! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s
! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s

! SPEC: F2008 R522 implied-shape-spec


program err_R522_2
  integer, parameter :: arr3(:, :) = &               !  '(:,:)' --> '(*,*)' or '(1:*,1:*)'
       reshape([1, 2, 3, 4, 5, 6, 7, 8], [2, 4])
end program err_R522_2


! GFORT: 09_impliedShape_c002.f90:8:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 09_impliedShape_c002.f90:8:
! FLANG-SAME: error:

