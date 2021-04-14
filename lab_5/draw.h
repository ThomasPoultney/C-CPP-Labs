#ifndef __DRAW__
#define __DRAW__

// Header needs to include bmp.h as the function declarations need
// to know struct Bitmap exists for their input parameters...
#include "bmp.h"

// A naive way of drawing a filled in coloured circle...
void draw_circle_slow(struct Bitmap * const image, 
	                  const int cx, 
	                  const int cy,
	                  const int radius,
	                  const unsigned char red, 
	                  const unsigned char green, 
	                  const unsigned char blue);

// A more sensible way of drawing a filled in coloured circle...
void draw_circle(struct Bitmap * const image, 
                 const int cx, 
                 const int cy,
                 const int radius,
                 const unsigned char red, 
                 const unsigned char green, 
                 const unsigned char blue);

// Draw a yellow smiley face with black eyes and mouth at the coordinate
// where radius is the size of the main yellow circle...
void draw_smiley(struct Bitmap * const image, 
                 const int cx, 
                 const int cy,
                 const int radius);

#endif