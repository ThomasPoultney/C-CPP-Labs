#include <stdio.h>
#include <math.h>

#include "bmp.h"
#include "draw.h"

int main(int argc, char *argv[]) {

	struct Bitmap image;
	Bitmap_constructor(&image, 800, 600);

	Bitmap_clear(&image, 128, 128, 255);

	draw_smiley(&image, image.width / 2, image.height / 2, 200);

	if ( ! Bitmap_save(&image, "test_1.bmp") ) {
		printf("Error saving...\n");
	}

	Bitmap_destructor(&image);

	return 0;
}