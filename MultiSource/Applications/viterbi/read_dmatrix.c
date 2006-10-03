#include <stdio.h>
#include <memory.h>

#include "common.h"

size_t read_dmatrix(dvarray* out, const char* filename) {
    FILE* fid = fopen(filename,"rt");
    double value;
    size_t i, j, width = 0, height = 0;

    printf("Opened file %s for matrix reading\n", filename);

    fscanf(fid, "%d %d", &height, &width);

    dvarray_init(out, height, width);

    for (i=0; i<height; ++i) {
      for (j=0; j<width; ++j) {
        fscanf(fid,"%lf",&value);
        out->data[i].data[j] = value;
      }
    }

    printf("%g\n", out->data[i-1].data[j-1]);
    fclose(fid);
    printf("File read and closed\n");
    return i*j;
}
