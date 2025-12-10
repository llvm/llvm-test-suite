# HIP Catch Tests Integration

This document describes the Catch-based test framework for HIP functionality in the LLVM Test Suite.

## Overview

The HIP Catch Tests framework provides comprehensive HIP tests using the Catch2 testing framework. The framework includes:

- **Unit tests**: Core HIP API functionality (memory, streams, events, kernels, compiler features, etc.)
- Support for multiple ROCm versions (per-variant testing)
- Hierarchical test organization (category and subdirectory levels)
- Integration with LLVM's LIT test runner

Currently included test categories:
- `unit/compiler`: Tests for HIP compiler features (kernels, device code compilation)

## Requirements

1. **ROCm installation**: A valid ROCm installation with HIP support

2. **LLVM Test Suite**: This repository contains the Catch test infrastructure in `External/HIP/catch/`

3. **clang++**: ROCm's clang++ compiler for building HIP code

4. **Catch2 v2.13.10+**: Obtained automatically via:
   - **System installation**: If Catch2 >= 2.13.10 is installed, it will be used
   - **FetchContent**: If not found, CMake will download Catch2 v2.13.10 from GitHub at configure time (requires internet connection for first build)

## Quick Start

### Basic Configuration

Configure the test suite with Catch tests enabled:

```bash
cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=/path/to/rocm/installation \
  -DTEST_SUITE_EXTERNALS_DIR=/path/to/externals \
  -DAMDGPU_ARCHS=gfx90a \
  -DENABLE_HIP_CATCH_TESTS=ON \
  -DCATCH_TEST_CATEGORIES="unit" \
  -DCMAKE_CXX_COMPILER=/path/to/clang++ \
  -DCMAKE_C_COMPILER=/path/to/clang \
  /path/to/llvm-test-suite
```

**Note**: Catch tests are **enabled by default** (`ENABLE_HIP_CATCH_TESTS=ON`). Catch2 is automatically obtained via `find_package` (system) or `FetchContent` (download). Set `ENABLE_HIP_CATCH_TESTS=OFF` to disable all Catch test targets.

### Platform Support

The Catch tests are **platform-agnostic** and support both AMD and NVIDIA GPUs through HIP:

#### AMD ROCm Backend (Default)

Use AMD's clang++ compiler directly:

```bash
cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=/opt/rocm \
  -DCMAKE_CXX_COMPILER=/opt/rocm/llvm/bin/clang++ \
  -DCMAKE_C_COMPILER=/opt/rocm/llvm/bin/clang \
  -DAMDGPU_ARCHS=gfx90a \
  /path/to/llvm-test-suite
```

#### NVIDIA CUDA Backend

Use HIP's `hipcc` wrapper (built with CUDA backend):

```bash
cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=/path/to/hip-cuda \
  -DCMAKE_CXX_COMPILER=/path/to/hip-cuda/bin/hipcc \
  -DCMAKE_C_COMPILER=/path/to/hip-cuda/bin/hipcc \
  -DCUDA_ARCH=sm_75 \
  /path/to/llvm-test-suite
```

**Note**: The `hipcc` wrapper automatically handles platform-specific compile and link flags. The same test source code works on both platforms without modification!

### Build Targets

After configuration, hierarchical targets are available at three levels: **top-level** (all catch tests), **category-level** (e.g., unit tests), and **subdirectory-level** (e.g., unit/compiler tests). Each level has both **aggregated** (all ROCm variants) and **per-variant** targets.

#### Top-Level Targets

Build or run **all** Catch tests across all categories:

| Target | Description |
|--------|-------------|
| `ninja hip-tests-catch` | Build all Catch tests, all variants |
| `ninja hip-tests-catch-hip-7.2.0` | Build all Catch tests for specific variant |
| `ninja check-hip-catch` | Run all Catch tests, all variants |
| `ninja check-hip-catch-hip-7.2.0` | Run all Catch tests for specific variant |

#### Category-Level Targets

Build or run tests for a specific **category** (e.g., `unit`, `stress`):

| Target | Description |
|--------|-------------|
| `ninja hip-tests-catch-unit` | Build all unit tests, all variants |
| `ninja hip-tests-catch-unit-hip-7.2.0` | Build all unit tests for specific variant |
| `ninja check-hip-catch-unit` | Run all unit tests, all variants |
| `ninja check-hip-catch-unit-hip-7.2.0` | Run all unit tests for specific variant |

#### Subdirectory-Level Targets

Build or run tests for a specific **subdirectory** within a category (e.g., `unit/compiler`):

| Target | Description |
|--------|-------------|
| `ninja hip-tests-catch-unit-compiler` | Build unit/compiler tests, all variants |
| `ninja hip-tests-catch-unit-compiler-hip-7.2.0` | Build unit/compiler tests for specific variant |
| `ninja check-hip-catch-unit-compiler` | Run unit/compiler tests, all variants |
| `ninja check-hip-catch-unit-compiler-hip-7.2.0` | Run unit/compiler tests for specific variant |

#### Other Targets

| Target | Description |
|--------|-------------|
| `ninja hip-tests-all` | Build all HIP tests (including Catch tests if enabled) |

## Configuration Options

### ENABLE_HIP_CATCH_TESTS

**Type**: Boolean
**Default**: ON
**Description**: Master switch to enable or disable the entire HIP Catch test framework. When disabled, no Catch test targets are created, and the build only includes simple HIP tests.

**When ENABLED (default)**:
- All Catch test targets are created (top-level, category-level, subdirectory-level, per-variant)
- Examples: `hip-tests-catch`, `hip-tests-catch-unit`, `hip-tests-catch-unit-compiler`
- `hip-tests-all` includes both simple and catch tests

**When DISABLED**:
- No Catch test targets are created
- Only simple HIP tests are available
- `hip-tests-all` includes only simple tests
- Faster CMake configuration (no Catch test infrastructure processed)

Examples:
```bash
# Enable Catch tests (default)
-DENABLE_HIP_CATCH_TESTS=ON

# Disable Catch tests (only simple tests)
-DENABLE_HIP_CATCH_TESTS=OFF
```

**Use cases for disabling**:
- Quick builds when you only need simple HIP tests
- CI environments that don't require comprehensive testing
- Debugging simple test failures without the overhead of Catch tests
- Systems with limited resources where minimal test coverage is acceptable

### HIP_CATCH_TEST_VERBOSE

**Type**: Boolean (ON/OFF)
**Default**: OFF
**Description**: Show verbose output with individual TEST_CASE results from Catch2

When enabled, test output will show:
- Each source file being executed
- Individual TEST_CASE names and results
- Success/failure status for each TEST_CASE
- Compact reporter format for better readability

Example:
```bash
# Enable verbose Catch2 output
-DHIP_CATCH_TEST_VERBOSE=ON

# Disable verbose output (default - only shows LIT summary)
-DHIP_CATCH_TEST_VERBOSE=OFF
```

**Output Comparison:**

With `HIP_CATCH_TEST_VERBOSE=OFF` (default):
```
Testing Time: 0.06s
Total Discovered Tests: 3
  Passed: 3 (100.00%)
```

With `HIP_CATCH_TEST_VERBOSE=ON`:
```
=== Running: catch_unit_compiler_hipSquare-hip-7.2.0 ===
Passed: Unit_test_compressed_codeobject

=== Running: catch_unit_compiler_hipClassKernel-hip-7.2.0 ===
Passed: Unit_hipClassKernel_Overload_Override
Passed: Unit_hipClassKernel_Friend
Passed: Unit_hipClassKernel_Empty
Passed: Unit_hipClassKernel_BSize
Passed: Unit_hipClassKernel_Size
Passed: Unit_hipClassKernel_Virtual
Passed: Unit_hipClassKernel_Value

=== Running: catch_unit_compiler_hipSquareGenericTarget-hip-7.2.0 ===
Passed: Unit_test_generic_target_in_compressed_fatbin
Passed: Unit_test_generic_target_in_regular_fatbin
Passed: Unit_test_generic_target_only_in_compressed_fatbin
Passed: Unit_test_generic_target_only_in_regular_fatbin

Testing Time: 0.06s
Total Discovered Tests: 3
  Passed: 3 (100.00%)
```

**Note**: The verbose TEST_CASE output appears in the terminal during the test run (sent to stderr). It's also saved to `.out` files in `build/External/HIP/Output/` for later analysis.

### CATCH_TEST_CATEGORIES

**Type**: Semicolon-separated list
**Default**: "unit"
**Description**: Test categories to include in the build

Available categories:
- `unit`: Unit tests for core HIP APIs (currently: compiler tests)

Example:
```bash
# Include unit tests (default and currently only available category)
-DCATCH_TEST_CATEGORIES="unit"
```

### CATCH_TEST_SUBDIRS

**Type**: Semicolon-separated list
**Default**: "" (empty - includes all subdirectories)
**Description**: Specific subdirectories to include within enabled categories. When empty, all subdirectories are automatically discovered and included.

This option provides fine-grained control over which tests to build. For example, within the `unit` category, you can selectively include only `compiler`, `memory`, and `stream` tests while excluding others.

Examples:
```bash
# Include only compiler tests from enabled categories
-DCATCH_TEST_SUBDIRS="compiler"

# Include multiple specific subdirectories
-DCATCH_TEST_SUBDIRS="compiler;memory;stream;kernel"

# Include all subdirectories (default behavior)
-DCATCH_TEST_SUBDIRS=""
# or simply omit the option
```

**Note**: The subdirectory filter applies to all enabled categories. For example, if you set `-DCATCH_TEST_CATEGORIES="unit;stress"` and `-DCATCH_TEST_SUBDIRS="compiler"`, the framework will include:
- `catch/unit/compiler` (if it exists)
- `catch/stress/compiler` (if it exists)

Available subdirectories in the `unit` category include:
- `compiler` - Compiler-specific tests
- `memory` - Memory management tests
- `stream` - Stream management tests
- `event` - Event handling tests
- `kernel` - Kernel execution tests
- `device` - Device management tests
- `math` - Math operations tests
- And 40+ more subdirectories...

### HIP_CATCH_TEST_TIMEOUT

**Type**: Integer (seconds)
**Default**: 60
**Description**: Timeout for individual Catch tests

```bash
-DHIP_CATCH_TEST_TIMEOUT=120
```

## Example Configurations

### Example 1: Basic Unit Tests Only

```bash
#!/bin/bash

export CLANG_DIR=/opt/rocm-7.2.0/llvm
export ROCM_PATH=/opt/rocm-7.2.0
export AMDGPU_ARCHS=gfx90a

cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=${ROCM_PATH} \
  -DTEST_SUITE_EXTERNALS_DIR=${ROCM_PATH} \
  -DAMDGPU_ARCHS=${AMDGPU_ARCHS} \
  -DCMAKE_CXX_COMPILER="${CLANG_DIR}/bin/clang++" \
  -DCMAKE_C_COMPILER="${CLANG_DIR}/bin/clang" \
  -DCATCH_TEST_CATEGORIES="unit" \
  /path/to/llvm-test-suite
```

### Example 2: Selective Subdirectory Testing

Build only specific subdirectories (e.g., compiler tests):

```bash
#!/bin/bash

export CLANG_DIR=/opt/rocm-7.2.0/llvm
export ROCM_PATH=/opt/rocm-7.2.0
export AMDGPU_ARCHS=gfx90a

cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=${ROCM_PATH} \
  -DTEST_SUITE_EXTERNALS_DIR=${ROCM_PATH} \
  -DAMDGPU_ARCHS=${AMDGPU_ARCHS} \
  -DCMAKE_CXX_COMPILER="${CLANG_DIR}/bin/clang++" \
  -DCMAKE_C_COMPILER="${CLANG_DIR}/bin/clang" \
  -DCATCH_TEST_CATEGORIES="unit" \
  -DCATCH_TEST_SUBDIRS="compiler" \
  /path/to/llvm-test-suite

# Build compiler tests
ninja hip-tests-catch-unit-compiler

# Run compiler tests
ninja check-hip-catch-unit-compiler
```

### Example 3: Comprehensive Testing

```bash
#!/bin/bash

export CLANG_DIR=/opt/rocm-7.2.0/llvm
export EXTERNAL_DIR=/opt/rocm-7.2.0
export AMDGPU_ARCHS=gfx90a
export TEST_SUITE_DIR=/path/to/llvm-test-suite

cd /path/to/build-llvm-test-suite

PATH=${CLANG_DIR}/bin:$PATH \
CXX=clang++ \
CC=clang \
cmake -G Ninja \
  -DTEST_SUITE_EXTERNALS_DIR=${EXTERNAL_DIR} \
  -DTEST_SUITE_HIP_ROOT=${EXTERNAL_DIR} \
  -DAMDGPU_ARCHS=${AMDGPU_ARCHS} \
  -DCMAKE_CXX_COMPILER="${CLANG_DIR}/bin/clang++" \
  -DCMAKE_C_COMPILER="${CLANG_DIR}/bin/clang" \
  -DCATCH_TEST_CATEGORIES="unit" \
  ${TEST_SUITE_DIR}

# Build all tests
ninja hip-tests-all

# Run simple tests
ninja check-hip-simple

# Run Catch tests at different levels
ninja check-hip-catch              # All catch tests
ninja check-hip-catch-unit         # All unit tests
ninja check-hip-catch-unit-compiler # Only unit/compiler tests
```

### Example 4: Simple Tests Only (Catch Tests Disabled)

For quick builds or when you only need simple HIP tests:

```bash
#!/bin/bash

export CLANG_DIR=/opt/rocm-7.2.0/llvm
export ROCM_PATH=/opt/rocm-7.2.0
export AMDGPU_ARCHS=gfx90a

cmake -G Ninja \
  -DTEST_SUITE_HIP_ROOT=${ROCM_PATH} \
  -DTEST_SUITE_EXTERNALS_DIR=${ROCM_PATH} \
  -DAMDGPU_ARCHS=${AMDGPU_ARCHS} \
  -DCMAKE_CXX_COMPILER="${CLANG_DIR}/bin/clang++" \
  -DCMAKE_C_COMPILER="${CLANG_DIR}/bin/clang" \
  -DENABLE_HIP_CATCH_TESTS=OFF \
  /path/to/llvm-test-suite

# With Catch tests disabled, only simple test targets available
ninja hip-tests-all              # Build all simple tests
ninja check-hip-simple           # Run all simple tests
ninja hip-tests-simple-hip-7.2.0 # Build simple tests for specific variant
ninja check-hip-simple-hip-7.2.0 # Run simple tests for specific variant

# Catch test targets are NOT created (will error if you try to use them)
# ninja hip-tests-catch            # ERROR: target not found
# ninja check-hip-catch-unit       # ERROR: target not found
```

## Target Hierarchy

The framework creates a three-level hierarchical structure for organizing and running tests (when `ENABLE_HIP_CATCH_TESTS=ON`, which is the default):

**Note**: When `ENABLE_HIP_CATCH_TESTS=OFF`, NO Catch test targets are created at all. Only simple HIP test targets are available.

### Hierarchy Levels

```
Level 1: Top-Level (ALL catch tests)
├── hip-tests-catch                    (all categories, all variants)
├── hip-tests-catch-hip-7.2.0          (all categories, one variant)
│
Level 2: Category (e.g., unit tests)
├── hip-tests-catch-unit               (all unit subdirs, all variants)
├── hip-tests-catch-unit-hip-7.2.0     (all unit subdirs, one variant)
│
Level 3: Subdirectory (e.g., unit/compiler tests)
├── hip-tests-catch-unit-compiler      (compiler tests, all variants)
└── hip-tests-catch-unit-compiler-hip-7.2.0  (compiler tests, one variant)
```

### Benefits of Hierarchical Targets

1. **Flexibility**: Build/run at any granularity level
2. **Efficiency**: Test only what you need during development
3. **Multi-Variant Support**: Test across multiple ROCm versions or focus on one
4. **Incremental Testing**: Quick feedback by testing changed components

### Example Workflows

**Scenario 1: Compiler developer working on code generation**
```bash
# Quick iteration: test only compiler tests for one ROCm version
ninja hip-tests-catch-unit-compiler-hip-7.2.0
ninja check-hip-catch-unit-compiler-hip-7.2.0
```

**Scenario 2: Testing a change across all ROCm versions**
```bash
# Build compiler tests for all installed ROCm versions
ninja hip-tests-catch-unit-compiler
ninja check-hip-catch-unit-compiler
```

**Scenario 3: Pre-commit validation**
```bash
# Run all unit tests across all variants
ninja check-hip-catch-unit
```

**Scenario 4: Nightly CI testing**
```bash
# Run everything
ninja check-hip-catch
```

## Test Organization

The framework organizes tests by:

1. **ROCm Version**: Each ROCm installation gets its own test variant
   - Example: `hip-7.2.0`, `hip-6.2.0`

2. **Category**: Tests are grouped by category
   - `unit`: Core API functionality
   - `stress`: High-load scenarios
   - `performance`: Benchmarking
   - `perftests`: Detailed metrics

3. **Subdirectory**: Each subdirectory within a category
   - `unit/compiler`, `unit/memory`, `unit/stream`, etc.

4. **Test Executable**: Each subdirectory produces a test executable
   - Example: `catch_unit_compiler-hip-7.2.0`

## Building Tests at Different Levels

### Build by Category

```bash
# Configure to include only unit tests
cmake -DCATCH_TEST_CATEGORIES="unit" ...

# Build all unit tests (all variants)
ninja hip-tests-catch-unit

# Build all unit tests for specific variant
ninja hip-tests-catch-unit-hip-7.2.0
```

### Build by Subdirectory

```bash
# Configure to include specific subdirectories
cmake -DCATCH_TEST_SUBDIRS="compiler;memory" ...

# Build unit/compiler tests (all variants)
ninja hip-tests-catch-unit-compiler

# Build unit/compiler tests for specific variant
ninja hip-tests-catch-unit-compiler-hip-7.2.0
```

### Build Everything

```bash
# Build all catch tests (all categories, all variants)
ninja hip-tests-catch

# Build all catch tests for specific variant
ninja hip-tests-catch-hip-7.2.0
```

## Running Tests at Different Levels

### Run All Catch Tests

```bash
# Run all catch tests (all categories, all variants)
ninja check-hip-catch

# Run all catch tests for specific variant
ninja check-hip-catch-hip-7.2.0
```

### Run Category-Level Tests

```bash
# Run all unit tests (all variants)
ninja check-hip-catch-unit

# Run all unit tests for specific variant
ninja check-hip-catch-unit-hip-7.2.0
```

### Run Subdirectory-Level Tests

```bash
# Run unit/compiler tests (all variants)
ninja check-hip-catch-unit-compiler

# Run unit/compiler tests for specific variant
ninja check-hip-catch-unit-compiler-hip-7.2.0
```

### Run Individual Test Executable

Each `.cc` source file is compiled into a separate test executable, allowing for individual test execution:

```bash
# Run a specific test executable directly
./External/HIP/catch_tests/catch_unit_compiler_hipSquare-hip-7.2.0
./External/HIP/catch_tests/catch_unit_compiler_hipClassKernel-hip-7.2.0

# Run with Catch2 filtering to select specific test cases
./External/HIP/catch_tests/catch_unit_compiler_hipSquare-hip-7.2.0 "[tag]"
./External/HIP/catch_tests/catch_unit_compiler_hipClassKernel-hip-7.2.0 "Unit_hipClassKernel_*"
```

### Using LIT

The tests are integrated with the LIT test runner. Each `.cc` source file creates a separate LIT test:

```bash
# Run all HIP tests
lit External/HIP

# Run only Catch tests (filter by name pattern)
lit -a External/HIP | grep catch_

# Run a specific test file
llvm-lit catch_unit_compiler_hipSquare-hip-7.2.0.test
```

**Note**: LIT reports one test per source file. For example, `unit/compiler` with 3 `.cc` files will show "Total Discovered Tests: 3" in LIT output. Each test executable may contain multiple Catch2 TEST_CASE definitions internally.

**Viewing Verbose Output**: When `HIP_CATCH_TEST_VERBOSE=ON`, the detailed TEST_CASE output is displayed in the terminal during the test run (sent to stderr to bypass LIT's stdout redirection). The output is also saved to `.out` files for later analysis.

## Troubleshooting

### Catch2 Download Failed

**Error**: `FetchContent failed to download Catch2`

**Cause**: No internet connection during first configure, and Catch2 is not installed system-wide.

**Solutions**:
1. **Install Catch2 system-wide** (recommended for offline builds):
   ```bash
   # Ubuntu/Debian
   sudo apt install catch2

   # Or build from source (exact version)
   git clone -b v2.13.10 https://github.com/catchorg/Catch2.git
   cd Catch2
   cmake -B build -DCMAKE_INSTALL_PREFIX=/usr/local
   cmake --build build
   sudo cmake --install build
   ```

2. **Ensure internet connectivity** during first CMake configure. Subsequent builds use the cached download.

### No Test Sources Found

**Error**: `No test sources found in category/subdir`

**Solution**: The CMakeLists.txt parser may have failed. This can happen if:
- The test category doesn't exist in your hip-tests version
- The CMakeLists.txt format is not recognized

Check available test categories:
```bash
ls /path/to/hip-tests/catch/
```

### Compilation Errors

**Common issues**:

1. **Missing includes**: Ensure ROCm headers are accessible
2. **Architecture mismatch**: Verify `AMDGPU_ARCHS` matches your GPU
3. **ROCm version mismatch**: Ensure HIP runtime matches compiler version

## Architecture

The framework consists of:

1. **HipCatchTests.cmake**: Main CMake module with functions for:
   - Repository discovery and validation
   - Test category discovery
   - Test executable creation (one per `.cc` source file)
   - LIT integration

2. **Modified CMakeLists.txt**: Integration points in the main HIP test CMakeLists.txt:
   - Initialization in `create_hip_tests()`
   - Per-variant integration in `create_hip_test()`
   - Target dependencies in `hip-tests-all`

3. **Test Granularity**: Each `.cc` source file is compiled into a separate test executable, allowing:
   - Individual test tracking in LIT
   - Parallel test execution
   - Fine-grained failure reporting
   - Independent test filtering

4. **Test Wrappers**: Shell scripts for LIT integration

## Extending the Framework

### Adding Custom Test Categories

To add support for additional test categories:

1. Add the category to `CATCH_TEST_CATEGORIES`:
   ```bash
   -DCATCH_TEST_CATEGORIES="unit;stress;mycategory"
   ```

2. The framework will automatically discover subdirectories in:
   ```
   llvm-test-suite/External/HIP/catch/mycategory/
   ```

## Performance Considerations

- **Build Time**: Each `.cc` file is compiled into a separate executable, which can increase build time. Use specific categories or subdirectories to reduce build scope.
- **Disk Space**: Each `.cc` source file creates a separate executable per variant. For example, 3 source files with 2 variants = 6 executables.
- **Parallelism**: Use ninja's `-j` flag to parallelize builds (particularly beneficial with multiple test executables):
  ```bash
  ninja -j16 hip-tests-catch
  ```

## Contributing

To contribute improvements to the framework:

1. Test changes with multiple ROCm versions
2. Verify tests build and run correctly
3. Update this documentation
4. Submit changes to the LLVM Test Suite

## Future Enhancements

Potential improvements:
- [ ] Add more test categories (stress, performance, etc.)
- [ ] Add more unit test subdirectories (memory, streams, etc.)
- [ ] Test selection by regex pattern
- [ ] Integration with CTest
- [ ] Test result aggregation and reporting
- [ ] Enhanced test filtering options

## Directory Structure

The Catch test infrastructure is located in `External/HIP/catch/`:

```
External/HIP/catch/
├── unit/                    # Unit test category
│   └── compiler/           # Compiler test subdirectory
│       ├── hipClassKernel.cc
│       ├── hipClassKernel.h
│       ├── hipSquare.cc
│       └── hipSquareGenericTarget.cc
├── include/                # Common test headers
│   ├── hip_test_common.hh
│   ├── hip_test_context.hh
│   ├── hip_test_features.hh
│   ├── hip_test_filesystem.hh
│   └── cmd_options.hh
├── hipTestMain/            # Test framework main files
│   ├── main.cc
│   ├── hip_test_context.cc
│   └── hip_test_features.cc
└── external/               # Third-party libraries
    └── picojson/
        └── picojson.h      # JSON parser (vendored)

# Note: Catch2 is obtained via find_package or FetchContent, not vendored
```

**Note**: The `kernels/` directory is not needed for `unit/compiler` tests. These tests define kernels inline using `__global__` functions.

## References

- [hip-tests Repository](https://github.com/ROCm/hip-tests) (original source of tests)
- [ROCm Documentation](https://rocm.docs.amd.com/)
- [LLVM Test Suite](https://llvm.org/docs/TestSuiteGuide.html)
- [Catch2 Framework](https://github.com/catchorg/Catch2)
