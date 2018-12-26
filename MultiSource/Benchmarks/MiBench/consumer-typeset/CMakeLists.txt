list(APPEND CPPFLAGS -DOS_UNIX=1 -DOS_DOS=0 -DOS_MAC=0 -DDB_FIX=0 -DUSE_STAT=1 -DSAFE_DFT=0 -DCOLLATE=1 -DLIB_DIR="lout.lib" -DFONT_DIR="font" -DMAPS_DIR="maps" -DINCL_DIR="include" -DDATA_DIR="data" -DHYPH_DIR="hyph" -DLOCALE_DIR="locale" -DCHAR_IN=1 -DCHAR_OUT=0 -DLOCALE_ON=1 -DASSERT_ON=1 -DDEBUG_ON=0  -DPDF_COMPRESSION=0 -D_FORTIFY_SOURCE=0)

if(ARCH STREQUAL "Mips")
  list(APPEND CPPFLAGS -DCOLLATE=0 -DLOCALE_ON=0)
endif()

list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -x -I data/include -D data/data -F data/font -C data/maps -H data/hyph large.lout)

llvm_multisource(consumer-typeset)
llvm_test_data(consumer-typeset large.lout data)
