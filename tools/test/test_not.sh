#!/usr/bin/env sh
#
# USAGE: test_not.sh ${bindir}
#
# where bindir is ${CMAKE_BINARY_DIR}/tools

export SET_IN_PARENT="something"
$1/not $1/test/check_env
