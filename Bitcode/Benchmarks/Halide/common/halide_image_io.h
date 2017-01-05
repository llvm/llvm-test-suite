// This simple PNG IO library works with *both* the Halide::Buffer<T> type *and*
// the simple halide_image.h version. Also now includes PPM support for faster load/save.

#ifndef HALIDE_IMAGE_IO_H
#define HALIDE_IMAGE_IO_H

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

namespace Halide {
namespace Tools {

namespace Internal {

typedef bool (*CheckFunc)(bool condition, const char* fmt, ...);

inline bool CheckFail(bool condition, const char* fmt, ...) {
    if (!condition) {
        char buffer[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        va_end(args);
        fprintf(stderr, "%s", buffer);
        exit(-1);
    }
    return condition;
}

inline bool CheckReturn(bool condition, const char* fmt, ...) {
    return condition;
}

// Convert to u8
inline void convert(uint8_t in, uint8_t &out) {out = in;}
inline void convert(uint16_t in, uint8_t &out) {out = in >> 8;}
inline void convert(uint32_t in, uint8_t &out) {out = in >> 24;}
inline void convert(int8_t in, uint8_t &out) {out = in;}
inline void convert(int16_t in, uint8_t &out) {out = in >> 8;}
inline void convert(int32_t in, uint8_t &out) {out = in >> 24;}
inline void convert(float in, uint8_t &out) {out = (uint8_t)(in*255.0f);}
inline void convert(double in, uint8_t &out) {out = (uint8_t)(in*255.0f);}

// Convert to u16
inline void convert(uint8_t in, uint16_t &out) {out = in << 8;}
inline void convert(uint16_t in, uint16_t &out) {out = in;}
inline void convert(uint32_t in, uint16_t &out) {out = in >> 16;}
inline void convert(int8_t in, uint16_t &out) {out = in << 8;}
inline void convert(int16_t in, uint16_t &out) {out = in;}
inline void convert(int32_t in, uint16_t &out) {out = in >> 16;}
inline void convert(float in, uint16_t &out) {out = (uint16_t)(in*65535.0f);}
inline void convert(double in, uint16_t &out) {out = (uint16_t)(in*65535.0f);}

// Convert from u8
inline void convert(uint8_t in, uint32_t &out) {out = in << 24;}
inline void convert(uint8_t in, int8_t &out) {out = in;}
inline void convert(uint8_t in, int16_t &out) {out = in << 8;}
inline void convert(uint8_t in, int32_t &out) {out = in << 24;}
inline void convert(uint8_t in, float &out) {out = in/255.0f;}
inline void convert(uint8_t in, double &out) {out = in/255.0f;}

// Convert from u16
inline void convert(uint16_t in, uint32_t &out) {out = in << 16;}
inline void convert(uint16_t in, int8_t &out) {out = in >> 8;}
inline void convert(uint16_t in, int16_t &out) {out = in;}
inline void convert(uint16_t in, int32_t &out) {out = in << 16;}
inline void convert(uint16_t in, float &out) {out = in/65535.0f;}
inline void convert(uint16_t in, double &out) {out = in/65535.0f;}


inline bool ends_with_ignore_case(const std::string &ac, const std::string &bc) {
    if (ac.length() < bc.length()) { return false; }
    std::string a = ac, b = bc;
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a.compare(a.length()-b.length(), b.length(), b) == 0;
}

inline bool is_little_endian() {
    int value = 1;
    return ((char *) &value)[0] == 1;
}

inline void swap_endian_16(bool little_endian, uint16_t &value) {
    if (little_endian) {
        value = ((value & 0xff)<<8)|((value & 0xff00)>>8);
    }
}

struct FileOpener {
    FileOpener(const char* filename, const char* mode) : f(fopen(filename, mode)) {
        // nothing
    }
    ~FileOpener() {
        if (f != nullptr) {
            fclose(f);
        }
    }
    FILE * const f;
};

}  // namespace Internal


struct BytesImgStruct {
  int dims[3]; //width, height, channels
  float* ptr;
};


template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool load_bytes(const std::string &filename, ImageType *im) {
    Internal::FileOpener f(filename.c_str(), "rb");
    if (!check(f.f != nullptr, "File %s could not be opened for reading\n", filename.c_str())) return false;

    BytesImgStruct ptrStruct;
    if (!check(fread(ptrStruct.dims, sizeof(int), 3, f.f) == 3,
               "Could not read dimensions (width, height, channels) for .bytes image\n")) return false;
    int img_size = ptrStruct.dims[0]*ptrStruct.dims[1];
    if (!check(ptrStruct.dims[0] > 0 && ptrStruct.dims[1] > 0 && ptrStruct.dims[2] > 0,
               "File %s does not have valid input\n", filename.c_str())) return false;
    ptrStruct.ptr = (float*) malloc(img_size * sizeof(float));
    if (!check(fread(ptrStruct.ptr, sizeof(float), img_size, f.f) == img_size,
               "Could not read .bytes image\n")) return false;

    if (ptrStruct.dims[2] != 1) {
        *im = ImageType(ptrStruct.dims[0], ptrStruct.dims[1], ptrStruct.dims[2]);
    } else {
        *im = ImageType(ptrStruct.dims[0], ptrStruct.dims[1]);
    }
    typename ImageType::ElemType *ptr = (typename ImageType::ElemType*)im->data();
    for (int i=0; i<img_size; i++)
      ptr[i] = (typename ImageType::ElemType) ptrStruct.ptr[i];
    free(ptrStruct.ptr);
    return true;
}

template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool save_bytes(ImageType &im, const std::string &filename) {
    BytesImgStruct ptrStruct;
    ptrStruct.dims[0] = im.width();
    ptrStruct.dims[1] = im.height();
    ptrStruct.dims[2] = im.channels();
    int img_size = ptrStruct.dims[0]*ptrStruct.dims[1];
    ptrStruct.ptr = (float*) malloc(img_size * sizeof(float));
    typename ImageType::ElemType *ptr = (typename ImageType::ElemType*)im.data();
    for (int i=0; i<img_size; i++)
      ptrStruct.ptr[i] = (float) ptr[i];

    Internal::FileOpener f(filename.c_str(), "wb");
    if (!check(f.f != nullptr, "File %s could not be opened for writing\n", filename.c_str())) return false;
    if (!check(fwrite (ptrStruct.dims, sizeof(int), 3, f.f),
               "Could not write dimensions (width, height, channels) for .bytes image\n")) return false;
    if (!check(fwrite (ptrStruct.ptr, sizeof(float), img_size, f.f),
               "Could not write .bytes image\n")) return false;
    return true;
}

template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool load_ppm(const std::string &filename, ImageType *im) {

    /* open file and test for it being a ppm */
    Internal::FileOpener f(filename.c_str(), "rb");
    if (!check(f.f != nullptr, "File %s could not be opened for reading\n", filename.c_str())) return false;

    int width, height, maxval;
    char header[256];
    if (!check(fscanf(f.f, "%255s", header) == 1, "Could not read PPM header\n")) return false;
    if (!check(fscanf(f.f, "%d %d\n", &width, &height) == 2, "Could not read PPM width and height\n")) return false;
    if (!check(fscanf(f.f, "%d", &maxval) == 1, "Could not read PPM max value\n")) return false;
    if (!check(fgetc(f.f) != EOF, "Could not read char from PPM\n")) return false;

    int bit_depth = 0;
    if (maxval == 255) { bit_depth = 8; }
    else if (maxval == 65535) { bit_depth = 16; }
    else { if (!check(false, "Invalid bit depth in PPM\n")) return false; }

    if (!check(header == std::string("P6") || header == std::string("p6"), "Input is not binary PPM\n")) return false;

    int channels = 3;
    *im = ImageType(width, height, channels);

    // convert the data to ImageType::ElemType
    if (bit_depth == 8) {
        std::vector<uint8_t> data(width*height*3);
        if (!check(fread((void *) data.data(), sizeof(uint8_t), width*height*3, f.f) == (size_t) (width*height*3), "Could not read PPM 8-bit data\n")) return false;
        typename ImageType::ElemType *im_data = (typename ImageType::ElemType*) im->data();
        for (int y = 0; y < im->height(); y++) {
            uint8_t *row = &data[(y*width)*3];
            for (int x = 0; x < im->width(); x++) {
                Internal::convert(*row++, im_data[(0*height+y)*width+x]);
                Internal::convert(*row++, im_data[(1*height+y)*width+x]);
                Internal::convert(*row++, im_data[(2*height+y)*width+x]);
            }
        }
    } else if (bit_depth == 16) {
        int little_endian = Internal::is_little_endian();
        std::vector<uint16_t> data(width*height*3);
        if (!check(fread((void *) data.data(), sizeof(uint16_t), width*height*3, f.f) == (size_t) (width*height*3), "Could not read PPM 16-bit data\n")) return false;
        typename ImageType::ElemType *im_data = (typename ImageType::ElemType*) im->data();
        for (int y = 0; y < im->height(); y++) {
            uint16_t *row = &data[(y*width)*3];
            for (int x = 0; x < im->width(); x++) {
                uint16_t value;
                value = *row++; Internal::swap_endian_16(little_endian, value); Internal::convert(value, im_data[(0*height+y)*width+x]);
                value = *row++; Internal::swap_endian_16(little_endian, value); Internal::convert(value, im_data[(1*height+y)*width+x]);
                value = *row++; Internal::swap_endian_16(little_endian, value); Internal::convert(value, im_data[(2*height+y)*width+x]);
            }
        }
    }
    (*im)(0,0,0) = (*im)(0,0,0);      /* Mark dirty inside read/write functions. */

    return true;
}

// "im" is not const-ref because copy_to_host() is not const.
template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool save_ppm(ImageType &im, const std::string &filename) {
    im.copy_to_host();

    unsigned int bit_depth = sizeof(typename ImageType::ElemType) == 1 ? 8: 16;

    Internal::FileOpener f(filename.c_str(), "wb");
    if (!check(f.f != nullptr, "File %s could not be opened for writing\n", filename.c_str())) return false;
    fprintf(f.f, "P6\n%d %d\n%d\n", im.width(), im.height(), (1<<bit_depth)-1);
    int width = im.width(), height = im.height();

    if (bit_depth == 8) {
        std::vector<uint8_t> data(width*height*3);
        for (int y = 0; y < im.height(); y++) {
            for (int x = 0; x < im.width(); x++) {
                uint8_t *p = &data[(y*width+x)*3];
                for (int c = 0; c < im.channels(); c++) {
                    Internal::convert(im(x, y, c), p[c]);
                }
            }
        }
        if (!check(fwrite((void *) data.data(), sizeof(uint8_t), width*height*3, f.f) == (size_t) (width*height*3), "Could not write PPM 8-bit data\n")) return false;
    } else if (bit_depth == 16) {
        int little_endian = Internal::is_little_endian();
        std::vector<uint16_t> data(width*height*3);
        for (int y = 0; y < im.height(); y++) {
            for (int x = 0; x < im.width(); x++) {
                uint16_t *p = &data[(y*width+x)*3];
                for (int c = 0; c < im.channels(); c++) {
                    uint16_t value;
                    Internal::convert(im(x, y, c), value);
                    Internal::swap_endian_16(little_endian, value);
                    p[c] = value;
                }
            }
        }
        if (!check(fwrite((void *) data.data(), sizeof(uint16_t), width*height*3, f.f) == (size_t) (width*height*3), "Could not write PPM 16-bit data\n")) return false;
    } else {
        return check(false, "We only support saving 8- and 16-bit images.");
    }
    return true;
}

// Returns false upon failure.
template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool load(const std::string &filename, ImageType *im) {
    if (Internal::ends_with_ignore_case(filename, ".ppm")) {
        return load_ppm<ImageType, check>(filename, im);
    } else if (Internal::ends_with_ignore_case(filename, ".bytes")) {
        return (load_bytes<ImageType, check>(filename, im));
    } else {
        return check(false, "[load] unsupported file extension (bytes|ppm supported)");
    }
}

// Returns false upon failure.
template<typename ImageType, Internal::CheckFunc check = Internal::CheckReturn>
bool save(ImageType &im, const std::string &filename) {
    if (Internal::ends_with_ignore_case(filename, ".ppm")) {
        return save_ppm<ImageType, check>(im, filename);
    } else if (Internal::ends_with_ignore_case(filename, ".bytes")) {
        return save_bytes<ImageType, check>(im, filename);
    } else {
        return check(false, "[save] unsupported file extension (bytes|ppm supported)");
    }
}

// Fancy wrapper to call load() with CheckFail, inferring the return type;
// this allows you to simply use
//
//    Image im = load_image("filename");
//
// without bothering to check error results (all errors simply abort).
class load_image {
public:
    load_image(const std::string &f) : filename(f) {}
    template<typename ImageType>
    inline operator ImageType() {
        ImageType im;
        (void) load<ImageType, Internal::CheckFail>(filename, &im);
        return im;
    }
private:
  const std::string filename;
};

// Fancy wrapper to call save() with CheckFail; this allows you to simply use
//
//    save_image(im, "filename");
//
// without bothering to check error results (all errors simply abort).
template<typename ImageType>
void save_image(ImageType &im, const std::string &filename) {
    (void) save<ImageType, Internal::CheckFail>(im, filename);
}

}  // namespace Tools
}  // namespace Halide

#endif  // HALIDE_IMAGE_IO_H
