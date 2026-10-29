# Testing for the  --exclude-stat-from-submission command line argument.
#
# Check a basic test-suite run.
# RUN: %{run-test-suite} \
# RUN:   --sandbox %t.SANDBOX \
# RUN:   --test-suite %S/Inputs/test-suite-cmake \
# RUN:   --cc %S/Inputs/FakeCompilers/clang-r154331 \
# RUN:   --use-cmake %S/Inputs/test-suite-cmake/fake-cmake \
# RUN:   --use-make %S/Inputs/test-suite-cmake/fake-make \
# RUN:   --use-lit %S/Inputs/test-suite-cmake/fake-lit \
# RUN:   --exclude-stat-from-submission compile \
# RUN:   --no-timestamp > %t.log 2> %t.err
# RUN: filecheck --check-prefix CHECK-REPORT < %t.SANDBOX/build/report.json %s
# CHECK-REPORT:     "Name": "nts.{{[^.]+}}.exec"
# CHECK-REPORT-NOT: "Name": "nts.{{[^.]+}}.compile"
