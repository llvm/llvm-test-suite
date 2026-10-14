! SPEC: F2008:5.4.7 DATA statement

program dataStmtRelax_001
  use iso_fortran_env
  implicit none

  call sin_curve

contains

  subroutine sin_curve
    integer :: graph(0:36, -40:40)
    integer, parameter :: ndots = size(graph)
    integer, parameter :: nasters = size(graph, 1)
    integer, parameter :: nspaces = (ndots - nasters) / 2
    integer :: i, j

    data (graph(i,int(sind(i*10.0)*40)),i=0,36) / nasters * 1 /
    data ((graph(i,j),j=-40,int(sind(i*10.0)*40)-1),i=0,36) / nspaces * 0 /
    data ((graph(i,j),j=int(sind(i*10.0)*40)+1,40),i=0,36) / nspaces * 0 /

    !! draw sine curve
    do i = 0, 36
       do j = -40, 40
          if (graph(i,j) == 1) THEN
             write(*, "('*')", advance='no')
          else
             write(*, "(' ')", advance='no')
          end if
       end do
       write(*,*)
    end do

  end subroutine sin_curve

end program dataStmtRelax_001
