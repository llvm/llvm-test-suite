LEVEL = ../../../

PROG = paq8p
CPPFLAGS += -DNOASM -DLLVM
LDFLAGS = -lstdc++ -lm
ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = -1 Output/file1.in
else
RUN_OPTIONS = -4 Output/file1.in
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

# The program insists on writing its output next to the input, but PROJ_SRC_DIR
# may not be writable.
Output/file1.in:
	$(VERB) cp $(PROJ_SRC_DIR)/file1.in $@

Output/paq8p.out-llc Output/paq8p.out-nat Output/paq8p.out-simple Output/paq8p.out-llc-beta Output/paq8p.out-opt-beta: Output/file1.in
