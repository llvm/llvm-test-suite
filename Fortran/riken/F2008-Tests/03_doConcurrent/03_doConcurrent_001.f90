! SPEC: F2008 R830

program main
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains
  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i

    do concurrent (i = 1:5)
      arr(i) = i * i
    end do
  end subroutine sub
end program main
