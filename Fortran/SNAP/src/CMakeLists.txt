################################################################################
#
# CMakeLists.txt
# 
# Author: Anthony Cabrera:
# Contact: cabreraam AT ieee DOT org
# Description: CMakeLists.txt replacement for SNAP Makefile
#
################################################################################

################################################################################
#
# Options and Variables
#
################################################################################

set(SNAP_USER_DEFS "" CACHE STRING "Semi-colon separted preprocessor pound defines")

set(FP_TOLERANCE "0.001" CACHE STRING "FP tolerance value")

set(SNAP_COMPILER_OPTIONS_LLVM_FLANG
	""
	CACHE
	STRING
	"Compiler options for LLVMFlang"
)

################################################################################
#
# Setting up build target
#
################################################################################

set(SNAP_SOURCE_FILES
	global.f90
	snap_main.f90
	utils.f90
	version.f90
	plib.F90
	geom.f90
	sn.f90
	data.f90
	control.f90
	input.f90
	setup.f90
	dealloc.f90
	translv.f90
	solvar.f90
	outer.f90
	expxs.f90
	inner.f90
	sweep.f90
	octsweep.f90
	dim1_sweep.f90
	dim3_sweep.f90
	output.f90
	time.F90
	mms.f90
	analyze.f90
	thrd_comm.f90
	mkba_sweep.f90
	CACHE
	STRING
	"List of SNAP source files"
)

add_executable(snap
	${SNAP_SOURCE_FILES}
)

target_compile_options(snap 
	PRIVATE
		$<$<Fortran_COMPILER_ID:LLVMFlang>:${SNAP_COMPILER_OPTIONS_LLVM_FLANG}>
)
target_compile_definitions(snap
	PRIVATE
		${SNAP_USER_DEFS}
)

macro(llvm_test_verify_hash_program_output _file)
  llvm_test_verify(%b/HashProgramOutput.sh ${_file})
endmacro()

# This if-body takes care of all of the llvm-test suite stuff. It is modeled
# after the llvm_multisource function in the llvm-test-suite, which takes the
# following form:
#function(llvm_multisource target)
#  set(sources ${ARGN})
#  if(NOT sources)
#    file(GLOB sources *.c *.cpp *.cc *.f *.F *.f90 *.F90)
#  endif()
#  llvm_test_executable_no_test(${target} ${sources})
#  llvm_test_traditional(${target})
#  llvm_add_test_for_target(${target})
#endfunction()
# Because 
# - I could not directly use those pre-existing functions/macros, 
# - I wanted to reference the work I'd already done with the SNAP CMake infra
# I will show how my implementation below corresponds to llvm_multisource. Look
# for comments that take the form  # start <function>
if(PROJECT_NAME STREQUAL "test-suite")
	set(target "snap")

  # start llvm_test_executable_no_test_fortran
	# Note: we ignore TEST_SUITE_PROFILE_USE. Will this break LLVM Flang? if we
	# aded that flag?
  llvm_codesign(snap)
  set_property(GLOBAL APPEND PROPERTY TEST_SUITE_TARGETS snap)
  test_suite_add_build_dependencies(snap)

  if(TEST_SUITE_LLVM_SIZE)
    add_custom_command(TARGET ${target} POST_BUILD
      COMMAND ${TEST_SUITE_LLVM_SIZE} --format=sysv $<TARGET_FILE:${target}>
      > $<TARGET_FILE:${target}>.size)
  endif()

  # start llvm_test_traditional(${target})
	# isolate path for the input file that we use	
	set(TEST_INPUT_DIR 
		"${CMAKE_CURRENT_SOURCE_DIR}/../qasnap/mms_src"
	)
	message(STATUS "TEST_INPUT_DIR - ${TEST_INPUT_DIR}")
	set(TEST_INPUT_FILENAME "2d_mms_st.inp")
	set(TEST_OUTPUT_FILENAME "snap-output")
	llvm_test_data(${target} 
		MUST_COPY
		SOURCE_DIR
			${TEST_INPUT_DIR}
		${TEST_INPUT_FILENAME}
	)
	# make run command include the new input we just copied
	list(APPEND RUN_OPTIONS 
		${TEST_INPUT_FILENAME} 
		${TEST_OUTPUT_FILENAME}
	)
  list(INSERT RUN_OPTIONS 0 WORKDIR %S)
	# here, we take the options for the RUN: command that we want to craft, and
	# pass it to the llvm_test_run function
  llvm_test_run(${RUN_OPTIONS})

  # Hash if we've been asked to.
  if(HASH_PROGRAM_OUTPUT)
    llvm_test_verify_hash_program_output(%o)
  endif()
	
	# Deal with output that we want to compare to
	if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/snap.reference_output)
		set(REFERENCE_OUTPUT 
			snap.reference_output
		)
		set(DIFFPROG_BASE %b/${FPCMP})
		set(FP_TOL_SUFFIX "-r ${FP_TOLERANCE}")
		set(FP_ABSTOL_SUFFIX "-a ${FP_ABSTOLERANCE}")
		set(DIFFPROG
			${DIFFPROG_BASE}
			"$<$<BOOL:${FP_TOLERANCE}>:${FP_TOL_SUFFIX}>"
			"$<$<BOOL:${FP_ABSTOLERANCE}>:${FP_ABSTOL_SUFFIX}>"
		)

		llvm_test_verify(${DIFFPROG} %o %S/${REFERENCE_OUTPUT})
		llvm_test_data(${target} ${REFERENCE_OUTPUT})
	else()
		message("-- No reference output found for test ${name}")
	endif()
  set(TESTSCRIPT "${TESTSCRIPT}" PARENT_SCOPE)

	# this creates the .test file for you!
	# start llvm_add_test_for_target(${target})
	# don't need to make any mods to this, woo!
  llvm_add_test_for_target(snap)

	# lit.local.cfg has since been added to the src directory. Additionally,
	# we'll need to copy that file over to the binary directory. 
	file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()

