#include "filter_test_op.h"

#ifdef _MSC_VER
#include <errno.h>
#include <malloc.h>
#endif

// Allocate aligned memory, per recent requirement by the
// Halide tests updated upstream.
int allocate_aligned(void **mem, size_t alignment, size_t size) {
#ifdef _MSC_VER
  *p = _aligned_malloc(size, alignment);
  return (*p) ? 0 : errno;
#else
  return posix_memalign(mem, alignment, size);
#endif
}

#if defined(__aarch64__) || defined(__arm__)
#define FACTOR 5
#else
#define FACTOR 1
#endif

template<typename T>
T rand_value() {
    return (T)(rand() * 0.125) - 100;
}

// Even on android, we want errors to stdout
extern "C" void halide_print(void *, const char *msg) {
    printf("%s\n", msg);
}

template<typename T>
buffer_t make_buffer(int w, int h) {
    T *mem;
    int err = allocate_aligned((void **)&mem, 128, w * h * sizeof(T));

    buffer_t buf = {0};
    buf.host = (uint8_t *)mem;
    buf.extent[0] = w;
    buf.extent[1] = h;
    buf.elem_size = sizeof(T);
    buf.stride[0] = 1;
    buf.stride[1] = w;

    for (int i = 0; i < w*h; i++) {
        mem[i] = rand_value<T>();
    }

    return buf;
}


int main(int argc, char **argv) {
    unsigned int err_code = 0;
#if (!__has_builtin(__builtin_cpu_supports) && (defined(__i386__) || defined(__x86_64__)))
    return err_code;
#endif
#if defined(__i386__) || defined(__x86_64__)
    if (!__builtin_cpu_supports("avx")) {
      return err_code;
    }
#endif
    time_t seed;
    if (argc > 1) {
        seed = atoi(argv[1]);
    }
    else {
        seed = time(NULL);
        srand (seed);
    }
    int W = 256*FACTOR, H = 100;
    // Make some input buffers
    buffer_t bufs[] = {
        make_buffer<float>(W, H),
        make_buffer<double>(W, H),
        make_buffer<int8_t>(W, H),
        make_buffer<uint8_t>(W, H),
        make_buffer<int16_t>(W, H),
        make_buffer<uint16_t>(W, H),
        make_buffer<int32_t>(W, H),
        make_buffer<uint32_t>(W, H),
        make_buffer<int64_t>(W, H),
        make_buffer<uint64_t>(W, H)
    };
    W/=FACTOR;

    int NO = 2;
    buffer_t out[] = {
        make_buffer<double>(W, H),
        make_buffer<double>(W, H)
    };
    double *out_value[NO];

    for (int i = 0; i < NO; i++) {
        filter f = filters[i];
        f.fn(bufs + 0,
             bufs + 1,
             bufs + 2,
             bufs + 3,
             bufs + 4,
             bufs + 5,
             bufs + 6,
             bufs + 7,
             bufs + 8,
             bufs + 9,
             &(out[i]));
        out_value[i] = (double *)(out[i].host);
    }

    int err;
    for (int i = 0; i < W*H; i++) {
       if ((err = out_value[0][i] - out_value[1][i]) > 0.0001) {
         fprintf(stderr, "Code generation error (%d): %d. Seer used %ld\n", i, err, seed);
         err_code = 1;
         break;
       }
    }

    for (int i = 0; i < sizeof(bufs)/sizeof(buffer_t); i++) {
        delete[] bufs[i].host;
    }

    for (int i = 0; i < NO; i++) {
        delete[] out[i].host;
    }

    return err_code;
}

