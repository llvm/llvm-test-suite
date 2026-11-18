! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R455,C492

program main
    implicit none
    type my_type
        real :: a
        integer i
    end type my_type
    type(my_type) :: t1
    t1 = my_type(i=1, a=null())
    print *, 't1%i = ', t1%i
    print *, 'allocated = ', allocated(t1%a)
end program

! FLANG: 15_omitAllocComp_c002.f90:13:
! FLANG-SAME: error:

! GFORT: 15_omitAllocComp_c002.f90:13:
! GFORT-NOT: .f90
! GFORT: Error: