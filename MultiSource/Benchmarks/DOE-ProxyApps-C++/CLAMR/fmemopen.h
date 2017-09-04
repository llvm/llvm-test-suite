#ifndef FMEMOPEN_H_
#define FMEMOPEN_H_

#if defined __cplusplus
extern "C" {
#endif

/**
 * A BSD port of the fmemopen Linux method using funopen.
 *
 * man docs for fmemopen:
 * http://linux.die.net/man/3/fmemopen
 *
 * man docs for funopen:
 * https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man3/funopen.3.html
 *
 * This method is ported from ingenuitas' python-tesseract project.
 *
 * You must call fclose on the returned file pointer or memory will be leaked.
 *
 * @param buf The data that will be used to back the FILE* methods. Must be at least
 *            @c size bytes.
 * @param size The size of the @c buf data.
 * @param mode The permitted stream operation modes.
 * @return A pointer that can be used in the fread/fwrite/fseek/fclose family of methods.
 *         If a failure occurred NULL will be returned.
 * @ingroup NimbusMemoryMappping
 */
FILE *fmemopen(void *buf, size_t size, const char *mode);

#ifdef __cplusplus
}
#endif

#endif // #ifndef FMEMOPEN_H_
