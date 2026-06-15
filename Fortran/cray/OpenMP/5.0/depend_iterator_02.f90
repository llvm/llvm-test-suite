! This test case tests an "empty" depend iterator.  The test expresses
! an apparent dependence between two tasks, but at runtime the
! iterators are empty so there is no actual dependence.  The test
! ensures the tasks are actually allowed to run concurrently, and it
! will deadlock otherwise. This test is not guaranteed to pass for all
! OpenMP implementations, but it is expected to pass for CCE and flang.

program main
  implicit none
  external :: omp_set_dynamic, omp_set_num_threads
  integer :: lll,uuu,sss,aaa(2)

  lll = 1
  uuu = 0
  sss = 1

  ! Need at least 3 threads to avoid deadlock
  call omp_set_dynamic(.false.)
  call omp_set_num_threads(3)
  !$omp parallel
  !$omp single

  call CHECKPOINT(0)

  !$omp task depend( iterator(iv1=lll:uuu:sss), out:aaa(iv1) )
  call CHECKPOINT(1)
  call CHECKPOINT(4)
  !$omp end task

  !$omp task depend( iterator(iv1=lll:uuu:sss), in:aaa(iv1) )
  call CHECKPOINT(2)
  call CHECKPOINT(5)
  !$omp end task

  call CHECKPOINT(3) ! Make sure both tasks are picked up by other threads 

  !$omp end single
  !$omp end parallel

  print *, "PASS"

contains
  subroutine CHECKPOINT(i)
    integer :: i, previous
    integer, save :: counter = 0
    if ( i .gt. 0 ) then
       previous = 0
       do while (previous .ne. i-1)
          !$omp atomic read seq_cst
          previous = counter
          !$omp end atomic
       end do
    end if
    !$omp atomic write seq_cst
    counter = i
    !$omp end atomic
  end subroutine CHECKPOINT
end program main
