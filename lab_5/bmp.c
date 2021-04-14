#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

void Bitmap_constructor(struct Bitmap * const image, 
	                    const unsigned int width, 
	                    const unsigned int height) {

	// Copy constructor parameters
	image->width  = width;
	image->height = height;

	// Allocate space for the image and set all pixels to black
	const int image_byte_size = ((3 * width) * height * sizeof(unsigned char));
	image->data = (unsigned char*) malloc(image_byte_size);
	memset(image->data, 0, image_byte_size);
}

void Bitmap_destructor(struct Bitmap * const image) {
	// Zero reported dimensions
	image->width  = 0;
	image->height = 0;

	// Free resource if non-null
	if (image->data) {
		free(image->data);
		image->data = NULL;
	}
}

void Bitmap_get_pixel(const struct Bitmap * const image, 
					  const unsigned int x, 
	                  const unsigned int y,
	                  unsigned char * const red, 
	                  unsigned char * const green, 
	                  unsigned char * const blue) {

	// Pixels stored in x0,y0,z0,x1,y1,z1,...,xn,yn,zn
	// Rows are 3x wider than as a result...
	const int offset = (x * 3) + (y * 3 * image->width);

	// Read pixel channel values into the result addresses
	*blue  = image->data[offset];
	*green = image->data[offset + 1];
	*red   = image->data[offset + 2]; 
}

void Bitmap_set_pixel(struct Bitmap * const image, 
	                  const unsigned int x, 
	                  const unsigned int y,
	                  const unsigned char red, 
	                  const unsigned char green, 
	                  const unsigned char blue) {

	const int offset = (x * 3) + (y * 3 * image->width);

	// Write pixel channel values into the result addresses
	image->data[offset]     = blue;
	image->data[offset + 1] = green;
	image->data[offset + 2] = red; 
}

void Bitmap_clear(struct Bitmap * const image, 
	              const unsigned char red, 
	              const unsigned char green, 
	              const unsigned char blue) {

	// Visit all pixels and set them to the clear colour
	int y;
	for (y = 0; y < image->height; y++) {
		int x;
		for (x = 0; x < image->width; x++) {
			
			Bitmap_set_pixel(image, x, y, red, green, blue);
		}	
	}
}

int Bitmap_save(const struct Bitmap * const image, 
	            const char * const file_path) {

	// Base Header
	const unsigned int header_size = 0x36; // dec 54
	const unsigned char header[0x36] = { 
		66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0,
		40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24 
	};

	// Compute number of bytes in one row of pixels and pad it to a multiple to 4 bytes
	// R is the remainder, R_padding is the amount needed to be added to each row.
	const unsigned int  R = ((image->width * 3) % 4), R_padding = (R == 0 ? 0 : (4 - R));
	const unsigned int width_padded = (image->width * 3) + R_padding;

	// Header contains size of full file in bytes which should be the header length
	// plus the total number of bytes in the padded image...
	const unsigned int fileSize = header_size + (width_padded * image->height);

	// Overwrite offsets within the header
	*((unsigned int*)(header + 0x02)) = fileSize;
	*((unsigned int*)(header + 0x12)) = image->width;
	*((unsigned int*)(header + 0x16)) = image->height;

	// Open file in binary write mode
	FILE *fp = fopen(file_path, "wb");
	if ( !fp ) {
		return 0;
	}

	fwrite(header, 1, header_size, fp);

	// Save pixels by row
	int y;
	for (y = 0; y < image->height; y++) {

		// Compute pixel offset in memory using non-padded width
		const unsigned char * row_start = &(image->data[(y * 3 * image->width)]);

		// Write an entire row at once for efficiency because it is contiguous
		fwrite(row_start, 3, image->width, fp);

		// Skip the padding bytes at the end of each row of pixels
		if (R_padding > 0) {
			fseek(fp, R_padding, SEEK_CUR);
		}
	}

	fclose(fp);

	return 1;
}

int Bitmap_load(struct Bitmap * const image, 
	            const char * const file_path) {

	// Open file in binary write mode
	FILE *fp = fopen(file_path, "rb");
	if ( !fp ) {
		image->width  = 0;
		image->height = 0;
		image->data   = NULL;
		return 0;
	}

	const unsigned int header_size = 0x36; // dec 54
	
	unsigned int width, height;

	fseek(fp, 0x12, SEEK_SET);
	fread(&width,  4, 1, fp);
	fread(&height, 4, 1, fp);

	fseek(fp, header_size, SEEK_SET);

	Bitmap_constructor(image, width, height);

	// Compute number of bytes in one row of pixels and pad it to a multiple to 4 bytes
	// R is the remainder, R_padding is the amount needed to be added to each row.
	const unsigned int R = ((width * 3) % 4), R_padding = (R == 0 ? 0 : (4 - R));
	const unsigned int width_padded = (width * 3) + R_padding;

	// Read in pixels by row
	int y;
	for (y = 0; y < height; y++) {

		// Compute pixel offset in memory using non-padded width
		unsigned char * row_start = &(image->data[(y * 3 * width)]);

		// Write an entire row at once for efficiency because it is contiguous
		fread(row_start, 3, width, fp);
		
		// Skip the padding bytes at the end of each row of pixels
		if (R_padding > 0) {
			fseek(fp, R_padding, SEEK_CUR);
		}
	}

	fclose(fp);

	return 1;
}