#include "write_bmp.h"

struct bmp_header create_header(const size_t width, const size_t height)
{
	const size_t padding = find_padding(width, height);
	struct bmp_header header;
		header.bfType = 19778;
		header.bfileSize = width*height*3+padding*height;
		header.bfReserved = 0;
		header.bOffBits = sizeof (struct bmp_header);
		header.biSize = 40;
		header.biWidth = width;
		header.biHeight = height;
		header.biPlanes = 1;
		header.biBitCount = 24;
		header.biCompression = 0;
		header.biSizeImage = 0;
		header.biXPelsPerMeter = 3780;
		header.biYPelsPerMeter = 3780;
		header.biClrUsed = 0;
		header.biClrImportant = 0;

	return header;

}

enum write_status to_bmp(FILE *out, struct image const *img)
{
	struct bmp_header header = create_header(img->width, img->height);
	fwrite(&header, sizeof(struct bmp_header), 1, out);

	const size_t w = img->width;
	const size_t h = img->height;
	const size_t padding = find_padding(w, h);

	size_t char_count = 0;

	for (size_t height = 0; height < h; ++height) {
		for (size_t width = 0; width < w; ++width)
			char_count += fwrite(img->data + (w * height + width), sizeof(struct pixel), 1, out);
		char_count += fwrite("0", sizeof(uint8_t), padding, out);
	}

	if (char_count == (w + padding) * h)
		return WRITE_OK;
	return WRITE_ERROR;
}
