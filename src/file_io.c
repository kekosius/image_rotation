#include "file_io.h"

enum open_status open_bmp(FILE **file, const char *filename, const char *modes)
{
	*file = fopen(filename, modes);

	if (*file)
		return OPEN_OK;

	return OPEN_ERROR;
}

enum close_status close_bmp(FILE **file)
{
	if (fclose(*file) != EOF)
		return CLOSE_OK;

	return CLOSE_ERROR;
}

