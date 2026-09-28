! SPEC: F2008 R830

program main
  implicit none
  integer, volatile :: a(5) = [1,2,3,4,5]
  integer :: b(5) = [1,2,3,4,5]
  integer :: c(5) = [1,2,3,4,5]
  real :: d(5) = [1.11,2.22,3.33,4.44,5.66]
  real :: e(5) = [1.11,2.22,3.33,4.44,5.66]

  call volatile_t(a)
  call cycle_t(b)
  call goto_t(c)
  call pure_func(d)
  call ieee_func(e)

  write(*,'(5(I4,1X))') a
  write(*,'(5(I4,1X))') b
  write(*,'(5(I4,1X))') c
  write(*,'(5(F6.2,1X))') d
  write(*,'(5(F6.2,1X))') e

contains

  ! pure user func
  pure function square(x) result(r)
    real, intent(in) :: x
    real :: r
    r = x * x
  end function square

  ! volatile
  subroutine volatile_t(arr)
    integer, intent(inout), volatile :: arr(5)
    integer :: i
    do concurrent (i = 1:5)
      arr(i) = arr(i) + 1
    end do
  end subroutine

  ! cycle within do concurrent
  subroutine cycle_t(arr)
    integer, intent(inout) :: arr(5)
    integer :: i
    do concurrent (i = 1:5)
      if (mod(i,2) == 0) cycle
      arr(i) = arr(i) * 2
    end do
  end subroutine

  ! goto within do concurrent
  subroutine goto_t(arr)
    integer, intent(inout) :: arr(5)
    integer :: i
    do concurrent (i = 1:5)
      if (mod(i,2) == 0) goto 200
      arr(i) = arr(i) + 10
200 continue
    end do
  end subroutine

  ! pure user func
  subroutine pure_func(arr)
    real, intent(inout) :: arr(5)
    integer :: i
    do concurrent (i = 1:5)
      arr(i) = square(arr(i))    ! << pure user-defined function
    end do
  end subroutine

  ! pure ieee func
  subroutine ieee_func(arr)
    real, intent(inout) :: arr(5)
    integer :: i
    do concurrent (i = 1:5)
      arr(i) = abs(arr(i) - 3.1)
    end do
  end subroutine

end program main
