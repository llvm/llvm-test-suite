set(PARALLEL_DIRS)

set(PARALLEL_DIRS IRSmk AMGmk CrystalMk )

llvm_add_subdirectories(${PARALLEL_DIRS})
