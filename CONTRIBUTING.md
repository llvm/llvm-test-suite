# Contributing

## License

This project is licensed under the terms of the Apache License v2.0 with LLVM
Exceptions license ([LICENSE.txt](LICENSE.TXT)) to ensure our ability to
contribute this project to the LLVM test suite project under the same license.

By contributing to this project, you agree to the Apache License v2.0 with LLVM
Exceptions and copyright terms there in and release your contribution under
these terms.

## Contribution process

### Development

For any changes not related to DPC++, but rather to LLVM in general, it is
strongly encouraged that you submit the patch to https://github.com/llvm/llvm-test-suite directly.
See [LLVM contribution guidelines](https://llvm.org/docs/Contributing.html)
for more information.

- Create a personal fork of the project on GitHub
  - For the DPC++ end-to-end test development, use **intel** branch as baseline
    for your changes.
- Prepare your patch
  - follow [LLVM coding standards](https://llvm.org/docs/CodingStandards.html)
  - [clang-format](https://clang.llvm.org/docs/ClangFormat.html) and
    [clang-tidy](https://clang.llvm.org/extra/clang-tidy/) tools can be
    integrated into your workflow to ensure formatting and stylistic
    compliance of your changes.
  - use

    ```bash
    wget https://raw.githubusercontent.com/intel/llvm/sycl/clang/tools/clang-format/git-clang-format
    python git-clang-format `git merge-base origin/intel HEAD`
    ```

    to check the format of your current changes against the `origin/intel`
    branch.
    - `-f` to also correct unstaged changes
    - `--diff` to only print the diff without applying

### Testing

- See [SYCL/README.md](SYCL/README.md) for instructions.

### Commit message

- When writing your commit message, please make sure to follow
  [LLVM developer policies](
  https://llvm.org/docs/DeveloperPolicy.html#commit-messages) on the subject.
- For any DPC++-related commit, the `[SYCL]` tag should be present in the
  commit message title. To a reasonable extent, additional tags can be used
  to signify the component changed, e.g.: `[LIT]`, `[NFC]`, `[Doc]`.

### Review and acceptance testing

- Create a pull request for your changes following [Creating a pull request
instructions](https://help.github.com/articles/creating-a-pull-request/).
  - PR description should follow same rules as commit message. It is used as
    commit message on the final merge.
- Changes addressing comments made during code review should be added as a
  separate commits to the same PR.
- CI will run checks which are prerequisites for submitting PR:
  - clang-format-check/build checks that the patch matches coding style
    (see [clang-format](https://clang.llvm.org/docs/ClangFormat.html));
  - Jenkins/pre-ci-cuda - runs all related tests on CUDA backend for GPU device
    on Ubuntu 18.04;
  - Jenkins/pre-ci-linux - runs all related tests on Ubuntu 18.04 machine with
  Level_Zero backend (GPU device) and OpenCL backend (CPU, GPU and FPGA
  emulator devices);
  - Jenkins/pre-ci-windows - runs all related tests on Windows Server 2019 with
  Level_Zero backend (GPU device) and OpenCL backend (CPU, GPU and FPGA
  emulator devices).

The last three checks are done for the latest available nightly build for DPC++
compiler and runtime from [intel/llvm](https://github.com/intel/llvm). The
build happens around 18:00 UTC if there are new commits since previous build.

Once the PR is approved and all checks have passed, the pull request is
ready for merge.

### Merge

Project maintainers merge pull requests by "Squash and merge". PR description
is used as final commit message.

\*Other names and brands may be claimed as the property of others.
