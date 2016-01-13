set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS bh em3d mst power tsp bisort health perimeter treeadd voronoi)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
