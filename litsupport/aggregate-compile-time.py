"""Post-build helper: collect the paths of every .o.time file produced for a
target and the path of its .link.time file, then write them into two
co-located path-list files that compiletime.py reads at run time.

Usage:
    python3 aggregate-compile-time.py <exe_name> <test_dir>

Outputs (written next to the executable in <test_dir>):
    <exe_name>.o.time.list    -- one absolute path per line, one per .o.time
    <exe_name>.link.time.list -- one absolute path (or empty if no link step)

These files form the public contract between the build stage and the
llvm-lit run stage. External test suites that do not use CMake's
add_executable() / add_library() can fulfill the contract by writing their
own <exe_name>.o.time.list and <exe_name>.link.time.list files alongside
the executable.
"""
import argparse
import os
import sys

def main():
    ap = argparse.ArgumentParser(
        description="Collect .o.time and .link.time paths into path-list files."
    )
    ap.add_argument("exe_name", help="Basename of the executable (no directory)")
    ap.add_argument("test_dir", help="Directory containing the executable and CMakeFiles/")
    args = ap.parse_args()

    exe_name = args.exe_name
    test_dir = os.path.abspath(args.test_dir)

    # ------------------------------------------------------------------
    # Compile-time path list: collect all .o.time files under
    # CMakeFiles/<exe>.dir/.
    #
    # This path relies on the CMake Makefile/Ninja generator convention
    # for per-target object directories (present since CMake 2.8).
    # External test suites that do not use add_executable()/add_library()
    # should write their own <exe_name>.o.time.list directly alongside the
    # executable instead of invoking this script.
    # ------------------------------------------------------------------
    o_time_paths = []
    obj_dir = os.path.join(test_dir, "CMakeFiles", exe_name + ".dir")
    if os.path.isdir(obj_dir):
        for dirpath, _subdirs, files in os.walk(obj_dir):
            for fname in sorted(files):
                if fname.endswith(".o.time"):
                    o_time_paths.append(os.path.join(dirpath, fname))

    o_time_list = os.path.join(test_dir, exe_name + ".o.time.list")
    with open(o_time_list, "w") as f:
        for p in o_time_paths:
            f.write(p + "\n")

    # ------------------------------------------------------------------
    # Link-time path list: the single <exe>.link.time file written by
    # timeit alongside the executable.
    # ------------------------------------------------------------------
    link_time_file = os.path.join(test_dir, exe_name + ".link.time")
    link_time_list = os.path.join(test_dir, exe_name + ".link.time.list")
    with open(link_time_list, "w") as f:
        if os.path.isfile(link_time_file):
            f.write(link_time_file + "\n")


if __name__ == "__main__":
    main()
