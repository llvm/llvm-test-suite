! SPEC: F2008 R515
! SPEC: F2008 R522 implied-shape-spec

program t1
  use iso_fortran_env

  integer, parameter :: vec1(*) = [4, 6, 4, 9]       ! vec1(1:4) = [4,6,4,9]
  integer(kind=INT64), parameter :: vec2(0:*) = int([1, 2, 3, 4], INT64)
                                                     ! vec2(0:3) = [1,2,3,4]
  real, parameter :: vec3(1:*) = vec1(2:)*10.0       ! vec3(1:3) = [60.0,40.0,90.0]
  
  integer, parameter :: arr1(0:1, 1:4) = &           ! arr1(0:1,1:4) = [1,3,5,7]
       reshape([1, 2, 3, 4, 5, 6, 7, 8], [2, 4])     !                 [2,4,6,8]

  integer, parameter :: arr2(*, *, *) = spread(arr1, dim=1, ncopies=3)
                                                     ! arr2(1:3, 1:2, 1:4)

  write(*,"(i0,' ',i0,' ',i0)") size(vec1), size(vec2), size(vec3)
  write(*,"(i0,' ',i0,' ',i0)") ubound(vec1), ubound(vec2), ubound(vec3)
  write(*,"(i0,' ',i0,' ',f4.1)") vec1(2), vec2(2), vec3(2)

  write(*,"(*(i0,' '))") shape(arr1)
  write(*,"(*(i0,' '))") arr1(0,1), arr1(1,1), arr1(0,2), arr1(1,2)

  write(*,"(*(i0,' '))") shape(arr2)
  write(*,"(*(i0,' '))") arr2(1,1,1), arr2(1,2,3), arr2(3,2,1), arr2(3,2,4)

end program
