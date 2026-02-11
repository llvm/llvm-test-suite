This directory holds test for bugs or issues discovered as part of
application testing. 

These tests should be organized by broad category (e.g. ice/, miscompile/,
runtime/, qoi/, diagnostics/, etc) and use a short, descriptive identifier
for the test directory name such as:

    reproducers/ice/assumed-rank-select-rank-crash/
    reproducers/miscompile/do-concurrent-reduction-real8-wrong/
    reproducers/diagnostics/interface-implicit-mismatch-accepted/
    reproducers/qoi/array-temporaries-slice-assignment-perf/

Customer names and internal bug IDs should not appear in paths;
relevant context should be captured in a local README.
