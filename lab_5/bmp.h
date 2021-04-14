#ifndef __BMP__
#define __BMP__

struct Bitmap {

	unsigned int width, height;
	unsigned char *data;
};

void Bitmap_constructor(struct Bitmap * const image, 
	                    const unsigned int width, 
	                    const unsigned int height);

void Bitmap_destructor(struct Bitmap * const image);

void Bitmap_get_pixel(const struct Bitmap * const image, 
					  const unsigned int x, 
	                  const unsigned int y,
	                  unsigned char * const red, 
	                  unsigned char * const green, 
	                  unsigned char * const blue);

void Bitmap_set_pixel(struct Bitmap * const image, 
	                  const unsigned int x, 
	                  const unsigned int y,
	                  const unsigned char red, 
	                  const unsigned char green, 
	                  const unsigned char blue);

void Bitmap_clear(struct Bitmap * const image, 
	              const unsigned char red, 
	              const unsigned char green, 
	              const unsigned char blue);

int Bitmap_save(const struct Bitmap * const image, 
	            const char * const file_path);

int Bitmap_load(struct Bitmap * const image, 
	            const char * const file_path);

#endif