#!/bin/bash

testname=$1
if [ -z "$testname" ]
then
  echo "Error: Pass test name as parameter"
  exit 1
fi

arch=$3

if [ -z $4 ]
then
  srcin=$2/${arch}_tests/${testname}.bc
  outpath=${arch}_opt_tests
  srcout=${outpath}/${testname}.ll
  mkdir -p $outpath
  ../../../bin/opt -O3 ${srcin} -S -o ${srcout}
  cat ${srcout} | sed -e 's:@unopt_test_op:@test_op:g' > ${srcout}_tmp
  cat ${srcout}_tmp | sed -e 's:@__unopt_test_op:@__test_op:g' > ${srcout}
  ../../../bin/llvm-as ${srcout}
  rm ${srcout}_tmp
  rm ${srcout}
else
  srcin=$2/${arch}_scalar_tests/scalar_${testname}.bc
  outpath=${arch}_opt_scalar_tests
  srcout=${outpath}/scalar_${testname}.ll
  mkdir -p $outpath
  ../../../bin/opt -O3 ${srcin} -S -o ${srcout}
  cat ${srcout} | sed -e 's:@unopt_scalar_test_op:@scalar_test_op:g' > ${srcout}_tmp
  cat ${srcout}_tmp | sed -e 's:@__unopt_scalar_test_op:@__scalar_test_op:g' > ${srcout}
  ../../../bin/llvm-as ${srcout}
  rm ${srcout}_tmp
  rm ${srcout}
fi

