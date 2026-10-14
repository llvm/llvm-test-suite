! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s
! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s

! SPEC: F2008 R522 implied-shape-spec is [ lower-bound : ] *


program err_R522_1
  integer, parameter :: arr1(:*) = [1, 2, 3, 4, 5]    !  ':*' --> '*' or '1:*'

end program err_R522_1


! GFORT: 09_impliedShape_c001.f90:8:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 09_impliedShape_c001.f90:8:
! FLANG-SAME: error:

