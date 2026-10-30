! SPEC: F2008 R602 C602

module mod
  real, target :: tmp1, tmp2
  real, parameter :: c = 8.0

contains
  function f(flag) result(res)
    real, intent(in) :: flag
    real, pointer :: res

    if (flag > 0.0) then
       res => tmp1
    else
       res => tmp2
    end if
  end function f
end module mod

program main
  use mod
  real :: a
  real :: v
  real :: arr(2)

  real, target :: pv
  real, pointer :: p

  a = 3.0
  tmp1 = 5.0
  tmp2 = 6.0

  ! ---- literal ----
  write(*,'(F8.2)') f(a)
  f(a) = 7.0
  write(*,'(F8.2)') f(a)

  ! ---- constant ----
  f(a) = c
  write(*,'(F8.2)') f(a)

  ! ---- variable ----
  v = -9.0
  f(a) = v
  write(*,'(F8.2)') f(a)

  ! ---- array element ----
  arr = [10.0, -11.0]
  f(a) = arr(2)
  write(*,'(F8.2)') f(a)

  ! ---- pointer variable ----
  pv = 12.0
  p => pv
  f(a) = p
  write(*,'(F8.2)') f(a)
end program main
