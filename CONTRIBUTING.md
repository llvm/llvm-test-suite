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
- Instructions about running DPC++ tests
  - see [README.md](SYCL/README.md).

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
- CI will run checks (e.g. clang-format-check) as soon as the PR is created.
- Once the PR is approved and all checks have passed, the pull request is
ready for merge.

### Merge

Project maintainers merge pull requests using one of the following options:

- [Rebase and merge] The preferable choice for PRs containing a single commit
- [Squash and merge] Used when there are multiple commits in the PR
  - Squashing is done to make sure that the project is buildable on any commit
- [Create a merge commit] Used for LLVM pull-down PRs to preserve hashes of the
commits pulled from the LLVM community repository

*Other names and brands may be claimed as the property of others.
