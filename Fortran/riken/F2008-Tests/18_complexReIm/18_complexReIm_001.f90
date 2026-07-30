! SPEC: F2008 R615

program main
  implicit none
  integer, parameter :: n = 3
  complex :: z_scalar
  complex :: z_array(n)
  complex :: w_array(n)
  real :: r
  integer :: i

  w_array = [( cmplx(1.375*i, -1.375*i), i=1,n )]

  call scalar_def(z_scalar)
  call array_def(z_array)
  call scalar_ref(z_scalar)
  call array_ref(z_array)
  call array_asg(z_array, w_array)

contains
  
  ! ====================
  ! A-1/2 %re,%im
  ! B-1 complex
  ! C-1 define
  ! D-1 scalar
  ! ====================
  subroutine scalar_def(z)
    complex, intent(out) :: z
    z%re = 3.75
    z%im = -6.25
    write(*,'(A," (",F0.3,",",F0.3,")")') "Scalar def:", real(z), aimag(z)
  end subroutine

  ! ====================
  ! A-1/2 %re,%im
  ! B-1 complex
  ! C-1 define
  ! D-2 array
  ! ====================
  subroutine array_def(z)
    complex, intent(out) :: z(:)
    integer :: i
    real :: re_val(3) = [1.25,2.5,3.75]
    real :: im_val(3) = [4.5,5.75,6.25]

    do i=1,3
      z(i)%re = re_val(i)
      z(i)%im = im_val(i)
    end do

    write(*,'(A)',advance="no") "Array def:"
    do i=1,3
      write(*,'(" (",F0.3,",",F0.3,")")',advance="no") real(z(i)),aimag(z(i))
    end do
    write(*,*)
  end subroutine

  ! ====================
  ! A-1/2 %re,%im
  ! B-1 complex
  ! C-2 reference
  ! D-1 scalar
  ! ====================
  subroutine scalar_ref(z)
    complex,intent(in)::z
    write(*,'(A,1X,F0.3," , ",F0.3)') "Scalar ref:", z%re, z%im
  end subroutine

  ! ====================
  ! A-1/2 %re,%im
  ! B-1 complex
  ! C-2 reference
  ! D-2 array
  ! ====================
  subroutine array_ref(z)
    complex,intent(in)::z(:)
    integer i

    write(*,'(A,1X)',advance="no") "Array ref:"
    do i=1,3
      write(*,'(F0.3,1X)',advance="no") z(i)%re
    end do
    write(*,'(A)',advance="no") ", "
    do i=1,3
      write(*,'(F0.3,1X)',advance="no") z(i)%im
    end do
    write(*,*)
  end subroutine

  ! ====================
  ! A-1/2 %re,%im
  ! B-1 complex
  ! C-1/2 def,ref
  ! D-2 array
  ! ====================
  subroutine array_asg(x,y)
    complex,intent(inout)::x(:)
    complex,intent(in)::y(:)
    integer i

    x%re = 4*y%re
    x%im = 4*y%im

    write(*,'(A,1X)',advance="no") "Array asg (*4):"
    do i=1,3
      write(*,'(F0.3,1X)',advance="no") real(x(i))
    end do
    write(*,'(A)',advance="no") ", "
    do i=1,3
      write(*,'(F0.3,1X)',advance="no") aimag(x(i))
    end do
    write(*,*)
  end subroutine

end program
