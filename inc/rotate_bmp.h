#ifndef ROTATE_BMP_H
#define ROTATE_BMP_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

/* создаёт копию изображения, которая повёрнута на 90 градусов */
struct image rotate( struct image const source);

#endif //ROTATE_BMP_H
