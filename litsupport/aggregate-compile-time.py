"""Post-build helper: aggregate per-object .o.time files and the
<exe>.link.time file produced by timeit into a single
<exe>.compile_link_time summary file that compiletime.py reads at run time.

Usage:
    python3 aggregate-compile-time.py <exe_name> <test_dir> [--maxrss]

Outputs:  <test_dir>/<exe_name>.compile_link_time
"""
import argparse
import os
import re
import sys

# ---------------------------------------------------------------------------
# Minimal copies of the two helpers from litsupport.modules.timeit so this
# script can be run stand-alone during the build without requiring the full
# litsupport package to be importable from sys.path.
# ---------------------------------------------------------------------------

def _getUserTime(contents):
    for line in contents.splitlines():
        if isinstance(line, bytes):
            line = line.decode("utf-8")
        if line.startswith("user"):
            m = re.match(r"user\s+([0-9.]+)", line)
            if m:
                return float(m.group(1))
    raise ValueError("No 'user' line found in timeit output:\n%s" % contents)


def _getMaxRSS(contents):
    for line in contents.splitlines():
        if isinstance(line, bytes):
            line = line.decode("utf-8")
        if line.startswith("maxrss"):
            m = re.match(r"maxrss\s+([0-9]+)", line)
            if m:
                return int(m.group(1))
    return 0


def _read(path):
    with open(path) as f:
        return f.read()


def main():
    ap = argparse.ArgumentParser(
        description="Aggregate .o.time and .link.time files into a single summary."
    )
    ap.add_argument("exe_name", help="Basename of the executable (no directory)")
    ap.add_argument("test_dir", help="Directory containing the executable and CMakeFiles/")
    ap.add_argument("--maxrss", action="store_true",
                    help="Also aggregate peak RSS (requires TEST_SUITE_REPORT_COMPILE_MAX_RSS)")
    args = ap.parse_args()

    compile_time = 0.0
    compile_maxrss = 0
    link_time = 0.0
    link_maxrss = 0

    # ------------------------------------------------------------------
    # Compile time: sum all .o.time files under CMakeFiles/<exe>.dir/
    # ------------------------------------------------------------------
    # TODO: This path relies on CMake's internal Makefile/Ninja generator
    # convention for per-target object directories. When the project minimum
    # version is raised to CMake >= 3.21, replace this inference with an
    # explicit --obj-time-files argument populated by
    # $<TARGET_OBJECTS:tgt> in the POST_BUILD command in TestSuite.cmake,
    # which eliminates this layout dependency entirely.
    obj_dir = os.path.join(args.test_dir, "CMakeFiles", args.exe_name + ".dir")
    if os.path.isdir(obj_dir):
        for dirpath, _subdirs, files in os.walk(obj_dir):
            for fname in files:
                if fname.endswith(".o.time"):
                    try:
                        contents = _read(os.path.join(dirpath, fname))
                        compile_time += _getUserTime(contents)
                        if args.maxrss:
                            compile_maxrss = max(compile_maxrss, _getMaxRSS(contents))
                    except Exception as e:
                        print("WARNING: could not parse %s: %s" % (fname, e),
                              file=sys.stderr)

    # ------------------------------------------------------------------
    # Link time: single <exe>.link.time written by timeit alongside the
    # executable (CMake's <TARGET>.link.time expands to that path).
    # ------------------------------------------------------------------
    link_time_file = os.path.join(args.test_dir, args.exe_name + ".link.time")
    if os.path.isfile(link_time_file):
        try:
            contents = _read(link_time_file)
            link_time = _getUserTime(contents)
            if args.maxrss:
                link_maxrss = _getMaxRSS(contents)
        except Exception as e:
            print("WARNING: could not parse %s: %s" % (link_time_file, e),
                  file=sys.stderr)

    # ------------------------------------------------------------------
    # Write summary in the same key: value format timeit uses.
    # ------------------------------------------------------------------
    out_path = os.path.join(args.test_dir, args.exe_name + ".compile_link_time")
    with open(out_path, "w") as f:
        f.write("compile_time %.9f\n" % compile_time)
        f.write("link_time %.9f\n" % link_time)
        if args.maxrss:
            f.write("compile_maxrss %d\n" % compile_maxrss)
            f.write("link_maxrss %d\n" % link_maxrss)


if __name__ == "__main__":
    main()
