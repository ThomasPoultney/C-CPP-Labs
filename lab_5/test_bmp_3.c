#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "bmp.h"
#include "draw.h"

// Example usage: $ ./test_bmp_3 dragons.bmp test_3.bmp
//
// Takes two file paths for the input and output files 
//
int main(int argc, char *argv[]) {

	if (argc < 3) {
		printf("Not enough parameters...\n");
		return -1;
	}

	struct Bitmap image;
	
	printf("Loading image [%s]\n", argv[1]);
	if ( ! Bitmap_load(&image, argv[1]) ) {
		printf("Error while loading file [ %s ]\n", argv[1]);
		return -1;
	}

	const int min_radius  = fmin(image.width, image.height) / 6,
	          max_radius  = fmin(image.width, image.height) / 8,
	          num_smileys = 8 + (rand() % 8);

	// Seed the random number generator with the current time	          
	srand(time(NULL));

	int i;
	for (i = 0; i < num_smileys; i++) {

		// Sample a random location and size for the smiley
		const int x = (rand() % image.width), 
		          y = (rand() % image.height), 
		          radius = min_radius + (rand() % (max_radius - min_radius));

		printf("Drawing random smiley at %d, %d with radius %d...\n", x, y, radius);

		draw_smiley(&image, x, y, radius);
	}

	printf("Saving image [%s]\n", argv[2]);
	if ( ! Bitmap_save(&image, argv[2]) ) {
		printf("Error while saving file [ %s ]\n", argv[2]);
		// Continue safely to destructor even though the save failed...
	}

	Bitmap_destructor(&image);

	return 0;
}