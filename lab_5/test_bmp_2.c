#include <stdio.h>
#include <math.h>

#include "bmp.h"
#include "draw.h"

int main(int argc, char *argv[]) {

	struct Bitmap image;
	if ( ! Bitmap_load(&image, "dragons.bmp") ) {
		printf("Error while loading [ dragons.bmp ]\n");
		return -1;
	}

	draw_smiley(&image,               (image.width / 4), image.height / 2, 100);
	draw_smiley(&image, image.width - (image.width / 4), image.height / 2, 100);

	if ( ! Bitmap_save(&image, "test_2.bmp") ) {
		printf("Error while saving [ test_2.bmp ]\n");
	}

	Bitmap_destructor(&image);

	return 0;
}