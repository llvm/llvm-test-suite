set(RUN_OPTIONS -f ${CMAKE_CURRENT_SOURCE_DIR}/INPUT/adj.awk type=l linelen=70 indent=5 ${CMAKE_CURRENT_SOURCE_DIR}/INPUT/words-large.awk)
set(PROG gawk)
list(APPEND LDFLAGS -lm)
set(Source alloca.c ${CMAKE_CURRENT_BINARY_DIR}/awk.tab.c debug.c field.c main.c msg.c regex.c array.c builtin.c eval.c io.c node.c)
list(APPEND CPPFLAGS -DBCOPY_MISSING -DSPRINTF_INT -DDOPRNT_MISSING  -DGCVT_MISSING -DSTRCASE_MISSING -DSTRTOD_MISSING  -DTMPNAM_MISSING)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_yacc_parser(gawk_parser awk.y ${CMAKE_CURRENT_BINARY_DIR}/awk.tab.c ${CMAKE_CURRENT_BINARY_DIR}/awk.tab.h)
    llvm_multisource()
