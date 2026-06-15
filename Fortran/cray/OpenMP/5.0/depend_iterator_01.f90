! This test tests a variety of use cases of depend support for
! iterators; there are some deliberate "pauses" that should help try
! to catch issues if the dependences are not honored, but due to the
! dynamic nature of task scheduling it is possible for this test to
! pass spuriously when there is an underlying issue.  But, the test
! should not fail spuriously.

program main
  implicit none
  interface
     subroutine usleep(usec) bind(C)
       integer, value :: usec
     end subroutine usleep
  end interface
  integer, parameter :: m = 4
  integer, parameter :: n = m*m
  integer :: aaa(n), bbb(n), ccc(n), i, mmm, nnn

  mmm = m
  nnn = n

  !$omp parallel
  !$omp single

  do i=1,nnn
     !$omp task depend(out:aaa(i))
     call usleep(10000) ! pause here to ensure we catch issues if the subsequent dependent task is scheduled early
     aaa(i) = 1
     !$omp end task
  end do
  !$omp task depend(iterator(iv1=2:nnn/2:2, iv2=3:nnn/2:2, iv3=nnn:nnn/2+1:-1), &
  !$omp&                     in: aaa(1), aaa(iv1), aaa(iv2), aaa(iv3)) &
  !$omp&     depend(iterator(iv4=1:mmm-1, iv5=1:mmm), &
  !$omp&                     out:bbb((iv4-1)*mmm+iv5), bbb(mmm*(mmm-1)+iv4), bbb(nnn))
  do i=1,nnn
     bbb(i) = aaa(i) + 1
  end do
  call usleep(10000) ! pause here to ensure we catch issues if the subsequent dependent task is scheduled early
  do i=1,nnn
     bbb(i) = bbb(i) + 1
  end do
  !$omp end task

  do i=1,nnn
     !$omp task depend(in:bbb(i)) depend(out:ccc(i))
     ccc(i) = bbb(i) + 1
     call usleep(10000) ! pause here to ensure we catch issues if the subsequent dependent task is scheduled early
     ccc(i) = ccc(i) + 1
     !$omp end task
  end do

  !!$omp taskwait depend(iterator(iv6=1:nnn), inout:ccc(iv6))
  !$omp task depend(iterator(iv6=1:nnn), in: ccc(iv6))

  if ( sum(abs(aaa - 1)) .ne. 0 .or. &
       sum(abs(bbb - 3)) .ne. 0 .or. &
       sum(abs(ccc - 5)) .ne. 0 ) then
     print *, "FAIL"
     call exit(1)
  end if
  print *, "PASS"
  !$omp end task
  !$omp end single
  !$omp end parallel

end program main
