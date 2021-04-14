#include <math.h> 

#include "draw.h" // draw.h internally includes bmp.h 

#define PI_OVER_180 (3.14159265359 / 180.0)

void draw_circle_slow(struct Bitmap * const image, 
	                  const int cx, 
	                  const int cy,
	                  const int radius,
	                  const unsigned char red, 
	                  const unsigned char green, 
	                  const unsigned char blue) {
	
	// Loop over whole image, very slow! 
	// The circle is probably not everywhere so looping over the whole image
	// is a poor assumption...
	int y;
	for (y = 0; y < image->height; y++) {
		int x;
		for (x = 0; x < image->width; x++) {
			
			// For each pixel, if the distance from the pixel to the centre 
			// of the circle is less than the radius, then set the colour
			const float distance = sqrt(pow(cx - x, 2.f) + pow(cy - y, 2.f));

			if (distance < radius) {
				Bitmap_set_pixel(image, x, y, red, green, blue);
			}
		}	
	}
}

void draw_circle(struct Bitmap * const image, 
                 const int cx, 
                 const int cy,
                 const int radius,
                 const unsigned char red, 
                 const unsigned char green, 
                 const unsigned char blue) {

	// Precompute the squared radius to avoid per pixel sqrt() call...
	const int radius_sq = radius * radius;

	// Get the bounds of the square around the circle and clip the 
	// square so it doesn't exceed the bounds of the image
	const int y0 = fmax(0, cy - radius), 
	          y1 = fmin(image->height, cy + radius);

    const int x0 = fmax(0, cx - radius), 
	          x1 = fmin(image->width,  cx + radius);

    // Loop only over the rectangle where the circle could be within the image	                   
	int y;
	for (y = y0; y < y1; y++) {
		int x;
		for (x = x0; x < x1; x++) {
			
			// Compute the difference in x and y between the pixel and 
			// the centre of the circle. 
			const int dx = (cx - x), dy = (cy - y);

			// Compute the square of the euclidean distance between 
			// the pixel and the centre of the circle.
			const int distance_sq = (dx * dx) + (dy * dy);

			// if x < y then (x*x) < (y*y) for all x,y in R
			if (distance_sq < radius_sq) {
				Bitmap_set_pixel(image, x, y, red, green, blue);
			}
		}	
	}
}

void draw_smiley(struct Bitmap * const image, 
                 const int cx, 
                 const int cy,
                 const int radius) {

	// Draw the main yellow circle
	draw_circle(image, cx, cy,  radius,        0,   0,   0);
	draw_circle(image, cx, cy, (radius - 2), 235, 216,  52);

	// Size the face based on its radius
	const int eye_x_offset = radius / 3;
	const int eye_y_offset = radius / 4;

	// Draw both eyes
	draw_circle(image, (cx - eye_x_offset), (cy + eye_y_offset), radius / 10, 0, 0, 0);
	draw_circle(image, (cx + eye_x_offset), (cy + eye_y_offset), radius / 10, 0, 0, 0);

	// Not very efficient! Drawing multiple overlapping circles in an arc for the smile
	float a;
	for (a = -25; a < 25; a += 0.5) {

		// Don't hate me for including some trig...
		int mx = cx + (sin(a * PI_OVER_180) * (radius / 3));
		int my = cy - (cos(a * PI_OVER_180) * (radius / 3));

		draw_circle(image, mx, my, radius / 15, 0, 0, 0);	
	}
	
}