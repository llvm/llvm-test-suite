set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS adi fdtd-2d fdtd-apml jacobi-1d-imper jacobi-2d-imper seidel-2d)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
