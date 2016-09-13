#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "../common/benchmark.h"
#include "../common/halide_image.h"
#include "../common/halide_image_io.h"
#include "bilateral_grid.h"

using namespace Halide::Tools;

int main(int argc, char **argv) {

    if (argc < 5) {
        printf("Usage: ./filter input.png range_sigma timing_iterations output.png\n"
               "e.g. ./filter input.png 0.1 10 output.png\n");
        return 0;
    }

    int timing_iterations = atoi(argv[3]);

    Image<float> input = load_image(argv[1]);
    Image<float> output(input.width(), input.height(), 1);

    bilateral_grid(atof(argv[2]), input, output);

    // Timing code. Timing doesn't include copying the input data to
    // the gpu or copying the output back.
    double min_t = benchmark(timing_iterations, 10, [&]() {
        bilateral_grid(atof(argv[2]), input, output);
    });
    printf("%gms\n", min_t * 1e3);

    save_image(output, argv[4]);

    return 0;
}
