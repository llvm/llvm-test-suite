LEVEL = ../../../

Source = lemon.c

PROG = lemon
RUN_OPTIONS = parse.y example1.y example2.y example3.y example4.y example5.y lighttpd_configparser.y lighttpd_mod_ssi_exprparser.y wireshark_dtd_grammar.lemon wireshark_grammar.lemon wireshark_mate_grammar.lemon xapian_queryparser.lemony ecmascript.y

include $(LEVEL)/Makefile.config

include ../../Makefile.multisrc
DIFFPROG := $(PROGDIR)/DiffOutput.sh "diff "

