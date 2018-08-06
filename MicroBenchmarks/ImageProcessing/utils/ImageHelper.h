/**
This file contains some utility functions that Image processing kernels require

Written by Pankaj Kukreja
Indian Institute of Technology Hyderabad
*/

#ifndef _IMAGEHELPER_H_
#define _IMAGEHELPER_H_

void initializeRandomImage(int *image, int height, int width);
void initializeRandomColouredImage(int *image, int height, int width);
void saveImage(int *image, const char *outputFile, int height, int width);

#endif /* _IMAGEHELPER_H_ */
