#include <stdio.h>

#include "bmp.h"
#include "util.h"
#include "read_bmp.h"
#include "rotate_bmp.h"
#include "write_bmp.h"
#include "file_io.h"


void usage()
{
	fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main(int argc, char **argv)
{
	if (argc != 2) usage();
	if (argc < 2) err("Not enough arguments \n");
	if (argc > 2) err("Too many arguments \n");

	struct bmp_header h = {0};
	if (read_header_from_file(argv[1], &h)) {
		bmp_header_print(&h, stdout);
	}
	else {
		err("Failed to open BMP file or reading header.\n");
	}

	struct image img = {h.biWidth, h.biHeight};
	struct image rotated_img = {h.biHeight, h.biWidth};

	//создание объектов класса файл
	FILE *f_in = NULL;
	FILE *f_out = NULL;

	//открытие файлов
	if (open_bmp(&f_in, argv[1], "rb") != OPEN_OK)
		err("input file open error\n");
	if (open_bmp(&f_out, "../images/image2.bmp", "wb") != OPEN_OK)
		err("output file open error\n");

	//чтение файлов и удаление паддингов
	switch (from_bmp(f_in, &img, &h)) {
	case READ_OK:
		break;
	case READ_INVALID_OBJECTS_COUNT:
		err("More read objects were expected");
	case READ_INVALID_BITS:
		err("Invalid count of bits for one pixel");
	case READ_INVALID_HEADER:
		err("Invalid size of header");
	}

	//переворот массива
	rotated_img = rotate(img);

	//запись файлов и добавление паддингов
	if (to_bmp(f_out, &rotated_img) != WRITE_OK)//
		err("More pixels were expected");

	//закрытие файлов
	if (close_bmp(&f_in) == CLOSE_ERROR)
		err("input file close error\n");
	if (close_bmp(&f_out) == CLOSE_ERROR)
		err("output file close error\n");

	free(img.data);
	free(rotated_img.data);
	return 0;
}