#include <stdio.h>

enum open_status  {
	OPEN_OK = 0,
	OPEN_ERROR

};

enum close_status  {
	CLOSE_OK = 0,
	CLOSE_ERROR

};

enum open_status open_bmp( FILE** in, const char *filename, const char *modes);

enum close_status close_bmp( FILE** out);

