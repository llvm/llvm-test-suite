##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 gobmk test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

Source = $(addprefix $(SPEC_BENCH_DIR)/src/sgf/,                               \
           sgf_utils.c sgftree.c sgfnode.c)                                    \
         $(addprefix $(SPEC_BENCH_DIR)/src/engine/,                            \
           aftermath.c board.c cache.c combination.c dragon.c filllib.c        \
           fuseki.c genmove.c hash.c influence.c interface.c matchpat.c        \
           move_reasons.c movelist.c optics.c owl.c printutils.c readconnect.c \
           reading.c score.c semeai.c sgfdecide.c sgffile.c shapes.c           \
           showbord.c utils.c value_moves.c worm.c globals.c persistent.c      \
           handicap.c surround.c)                                              \
         $(addprefix $(SPEC_BENCH_DIR)/src/interface/,                         \
           gtp.c main.c play_ascii.c play_gtp.c play_solo.c play_test.c)       \
         $(addprefix $(SPEC_BENCH_DIR)/src/patterns/,                          \
           connections.c dfa.c helpers.c transform.c owl_attackpat.c conn.c    \
           patterns.c apatterns.c dpatterns.c owl_vital_apat.c eyes.c          \
           influence.c barriers.c endgame.c aa_attackpat.c owl_defendpat.c     \
           fusekipat.c fuseki9.c fuseki13.c fuseki19.c josekidb.c handipat.c)  \
         $(addprefix $(SPEC_BENCH_DIR)/src/utils/,                             \
           getopt.c getopt1.c gg_utils.c random.c)

include ../../Makefile.spec2006

CPPFLAGS += -DHAVE_CONFIG_H

## FIXME: Multiple *.tst files

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := --quiet --mode gtp
  STDIN_FILENAME  := capture.tst
  STDOUT_FILENAME := capture.out
else
  RUN_OPTIONS     := --quiet --mode gtp
  STDIN_FILENAME  := arb.tst
  STDOUT_FILENAME := arb.out
endif
