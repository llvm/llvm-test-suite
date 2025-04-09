#include <hip/hip_runtime.h>
#include <iostream>
#include <cstring>
#include <cassert>

// Simple error check macro
#define HIP_CHECK(call)                                                         \
    do {                                                                        \
        hipError_t err = call;                                                  \
        if (err != hipSuccess) {                                                \
            std::cerr << "HIP error: " << hipGetErrorString(err)               \
                      << " at " << __FILE__ << ":" << __LINE__ << std::endl;    \
            std::exit(EXIT_FAILURE);                                            \
        }                                                                       \
    } while (0)

// Parametrized kernel that calls the given function pointer and stores the result
template <auto CalcF, typename R, typename... Args>
__global__ void calcWrapperKernel(R* out, Args... args) {
    if (threadIdx.x == 0 && blockIdx.x == 0) {
        *out = CalcF(args...);
    }
}

// Host test launcher: computes expected on host, launches kernel, compares
template <auto CalcF, typename R, typename... Args>
void runTest(Args... args) {
    R expected = CalcF(args...);

    R* dOut;
    R hOut;
    HIP_CHECK(hipMalloc(&dOut, sizeof(R)));
    HIP_CHECK(hipMemset(dOut, 0, sizeof(R)));

    calcWrapperKernel<CalcF, R, Args...><<<1, 1>>>(dOut, args...);
    HIP_CHECK(hipGetLastError());
    HIP_CHECK(hipMemcpy(&hOut, dOut, sizeof(R), hipMemcpyDeviceToHost));
    HIP_CHECK(hipFree(dOut));

    if (memcmp(&hOut, &expected, sizeof(R)) == 0) {
        std::cout << "[PASS] Result = " << hOut << std::endl;
    } else {
        std::cerr << "[FAIL] Expected " << expected << ", but got " << hOut << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

//
// Test Case 1: Mixed types with padding
//
namespace test_mixed_types {
    struct Args {
        int a;
        float b;
        char c;  // unused
        double d;
    };

    __host__ __device__
    int calc(Args args) {
        return static_cast<int>(args.a + args.b + args.d);
    }

    void run() {
        Args args = {3, 2.5f, 'x', 4.5};
        runTest<calc, int>(args);
    }
}

//
// Test Case 2: Deeply nested struct
//
namespace test_nested_struct {
    struct Inner {
        int x;
        float y;  // unused
    };

    struct Middle {
        Inner inner;
        int z;
    };

    struct Outer {
        Middle mid;
        int w;
    };

    __host__ __device__
    int calc(Outer args) {
        return args.mid.inner.x + args.mid.z + args.w;
    }

    void run() {
        Outer args = {{{2, 1.0f}, 3}, 4};
        runTest<calc, int>(args);
    }
}

//
// Test Case 3: Partial field usage
//
namespace test_partial_use {
    struct Args {
        int a;
        float b;
        double c;  // unused
    };

    __host__ __device__
    int calc(Args args) {
        return static_cast<int>(args.a * args.b);
    }

    void run() {
        Args args = {4, 2.0f, 9.9};
        runTest<calc, int>(args);
    }
}

//
// Test Case 4: Struct with array
//
namespace test_array_member {
    struct Args {
        int arr[4];
        int idx;
    };

    __host__ __device__
    int calc(Args args) {
        return args.arr[args.idx];
    }

    void run() {
        Args args = {{10, 20, 30, 40}, 2};
        runTest<calc, int>(args);
    }
}

//
// Test Case 5: Struct with address taken (indirect access)
//
namespace test_address_taken {
    struct Args {
        int a;
        int b;
    };

    __device__ __host__
    int getA(const Args* p) {
        return p->a;
    }

    __host__ __device__
    int calc(Args args) {
        return getA(&args) + args.b;
    }

    void run() {
        Args args = {5, 7};
        runTest<calc, int>(args);
    }
}

//
// Test Case 6: Mixed struct and non-struct arguments with unused fields
//
namespace test_mixed_struct_and_scalars {
    struct A {
        int a1;
        float a2;   // unused
        char a3;
    };

    struct B {
        double b1;
        int b2;     // unused
    };

    __host__ __device__
    int calc(char c, A a, int i1, int /*i2*/, B b) {
        return static_cast<int>(c) + a.a1 + a.a3 + i1 + static_cast<int>(b.b1);
    }

    void run() {
        A a = {10, 3.14f, 2};     // a1 = 10, a3 = 2, a2 = unused
        B b = {5.0, 42};          // b1 = 5.0, b2 = unused
        char c = 1;
        int i1 = 7;
        int i2 = 99;              // unused
        runTest<calc, int>(c, a, i1, i2, b);
    }
}

//
// Test Case 7: Struct with vector type (float3) and other fields
//
namespace test_struct_with_vector_types {
    struct A {
        float3 v;    // Used
        int id;      // Used
        float unused; // Unused
    };

    __host__ __device__
    int calc(A a) {
        int sum = static_cast<int>(a.v.x + a.v.y + a.v.z);
        return sum + a.id;
    }

    void run() {
        A a;
        a.v = make_float3(1.0f, 2.0f, 3.0f);
        a.id = 4;
        a.unused = 99.0f;
        runTest<calc, int>(a);
    }
}

int main() {
    test_mixed_types::run();
    test_nested_struct::run();
    test_partial_use::run();
    test_array_member::run();
    test_address_taken::run();
    test_mixed_struct_and_scalars::run();
    test_struct_with_vector_types::run();
    return 0;
}
