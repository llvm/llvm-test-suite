This directory contains programs that are to be compiled and run, but consist
of multiple source files.  In this scheme, every program gets a subdirectory,
and subdirectories are automatically activated just by existing in this directory.

If you don't want a testcase to be run in your tree, just rename the subdirectory
to XXX-disabled, which will prevent it from running.


Olden Code Sizes:

trinity% foreach f ( Olden-[a-z]* )
cd $f
echo "-------------------- $f --------------------"
wc *.[ch]
cd -
end
-------------------- Olden-bh --------------------
      25      46     320 args.c
      27     111     821 code.h
     248     767    6111 defs.h
    1240    4569   33748 newbh.c
     119     357    2354 stdinc.h
      77     170    1137 util.c
     303    1172    7431 vectmath.h
      44     198    1264 walksub.c
    2083    7390   53186 total
-------------------- Olden-bisort --------------------
      36      76     512 args.c
     280     649    5422 bitonic.c
      19      44     349 node.h
      13      30     269 proc.h
     348     799    6552 total
-------------------- Olden-em3d --------------------
      66     127     972 args.c
      60     142    1424 em3d.c
      57     181    1261 em3d.h
      52      90    1047 main.c
     347     953    9763 make_graph.c
      13      41     253 make_graph.h
      63     132    1015 util.c
      25      92     593 util.h
     683    1758   16328 total
-------------------- Olden-health --------------------
      28      71     693 args.c
     298     910    7841 health.c
     100     262    2807 health.h
      47     123    1113 list.c
      30      70     528 poisson.c
     503    1436   12982 total
-------------------- Olden-mst --------------------
      16      38     252 args.c
      97     248    2038 hash.c
      20      61     482 hash.h
     155     364    3386 main.c
     117     284    2465 makegraph.c
      23      55     427 mst.h
     428    1050    9050 total
-------------------- Olden-perimeter --------------------
      49      88     714 args.c
     258     516    5604 main.c
     123     256    3112 maketree.c
      54     118     995 perimeter.h
     484     978   10425 total
-------------------- Olden-power --------------------
      87     222    1566 build.c
     331     786    7498 compute.c
     106     329    3290 main.c
      91     267    2003 power.h
     615    1604   14357 total
-------------------- Olden-treeadd --------------------
      49      92     732 args.c
     144     322    2817 node.c
      27      76     590 par-alloc.c
      25      45     318 tree.h
     245     535    4457 total
-------------------- Olden-tsp --------------------
      47      77     520 args.c
     124     323    2974 build.c
      57     131    1138 main.c
     292     943    6715 tsp.c
      58     184    1283 tsp.h
     578    1658   12630 total
-------------------- Olden-voronoi --------------------
      41      91     615 args.c
     123     390    3164 defines.h
     712    1880   17464 newvor.c
     157     472    4222 output.c
      69     235    1511 vector.c
    1102    3068   26976 total

