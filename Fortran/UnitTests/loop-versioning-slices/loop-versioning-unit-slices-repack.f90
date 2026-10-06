! Verify execution of FIR loop versioning through a frontend-generated
! fir.pack_array. Structural FIR coverage is maintained in
! flang/test/Transforms/loop-versioning-slices-source.f90.

module loop_versioning_unit_slices_repack_m
  implicit none
contains
  subroutine fill_repacked(values, indices, record)
    real, intent(inout) :: values(:, :)
    integer, intent(in) :: indices(2)
    character(*), intent(in) :: record

    read(record, *) values(2:3, indices)
  end subroutine
end module

program loop_versioning_unit_slices_repack
  use loop_versioning_unit_slices_repack_m, only: fill_repacked
  implicit none
  real :: storage(6, 2), expected(6, 2)
  integer :: indices(2)

  storage = -1.0
  expected = -1.0
  indices = [1, 2]

  ! The actual argument is noncontiguous in its first dimension. Whole-array
  ! repacking gives the callee a contiguous temporary, and the epilogue must
  ! copy the values written through the fast path back to storage.
  call fill_repacked(storage(1:5:2, :), indices, '1 2 3 4')
  expected(3:5:2, 1) = [1.0, 2.0]
  expected(3:5:2, 2) = [3.0, 4.0]
  if (any(storage /= expected)) error stop 1

  print '(A)', 'PASS'
end program
