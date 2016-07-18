#include "halide_buffer.h"

template<typename T>
T rand_value() {
    return (T)(rand() * 0.125) - 100;
}

template<typename T>
buffer_t make_buffer(int w, int h) {
    T *mem = new T[w*h];
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
    const int W = 4096, H = 512;
    // Make some input buffers
    buffer_t bufs[] = {
        make_buffer<uint8_t>(W, H),
        make_buffer<int32_t>(W, H)
    };

    for (int i = 0; i < 1; i++) {
        filter f = filters[i];
        f.fn(bufs + 0,
             bufs + 1);
    }

    for (int i = 0; i < sizeof(bufs)/sizeof(buffer_t); i++) {
        delete[] bufs[i].host;
    }

    return err_code;
}
