#ifndef READ_BMP_H
#define READ_BMP_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"
#include "util.h"

enum read_status  {
	READ_OK = 0,
	READ_INVALID_OBJECTS_COUNT,
	READ_INVALID_BITS,
	READ_INVALID_HEADER
};
enum read_status from_bmp( FILE* in, struct image* img, struct bmp_header *header);

#endif //READ_BMP_H
