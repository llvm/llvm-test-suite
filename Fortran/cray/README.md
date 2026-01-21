# Fortran feature tests

This directory contains tests for standard Fortran language features.

Tests are organized by the commonly used Fortran standard edition label
that defines the behavior under test.

## Layout

```text
fXX/<clause>/<subclause>/...
```

Where:

- `XX` is the commonly understood standard edition year in either two
  or four digits (e.g. `90`, `2003`, etc).
- `<clause>` is the clause number in that edition, zero-padded to 2 digits.
- `<subclause>` is one or more further zero-padded numeric levels that
  identify the relevant subclause(s) within the clause. The number of
  levels is not fixed; use as many as needed based on the test (e.g. `06/02`
  or `01/02/03/04`).

## Examples

- `f90/07/03/` contains tests based on Clause 7, Subclause 3 of the
  Fortran 90 edition of the standard.
- `f2003/10/02/` contains tests based on Clause 10, Subclause 2
  from Fortran 2003.
- `f2023/05/04/03/02/` would contain tests of deeper Sublause references,
  as required.

## Test organization

Test organization within a subclause directory is intentionally not
prescribed. A directory may contain:

- multiple test source files, and/or
- per-test subdirectories when a test requires supporting files.

## Non-standard sources

Tests derived from sources outside the base published standard (e.g.
interpretations and corrigenda) are kept with the related subclause(s)
rather than in separate directories. When relevant, note provenance in the
test name and/or as a comment in the test itself.

## Reproducers

Application reproducers (reduced real-world codes and bug triggers) live
under reproducers/ rather than the YYYY/ standard hierarchy. These tests
are organized by broad category (e.g. ice/, miscompile/, runtime/, qoi/,
diagnostics/) and use a short, descriptive identifier for the directory
name. Customer names and internal bug IDs must not appear in paths;
relevant context should be captured in a local README.

### Example reproducer paths:

    reproducers/ice/assumed-rank-select-rank-crash/
    reproducers/miscompile/do-concurrent-reduction-real8-wrong/
    reproducers/diagnostics/interface-implicit-mismatch-accepted/
    reproducers/qoi/array-temporaries-slice-assignment-perf/
