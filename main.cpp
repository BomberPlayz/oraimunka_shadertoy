#include <cstddef>
#include "vector.h"
#include "THE_FUNC.cpp"
#include "image_writer.cpp"
//#include "THE_FUNC.h"

const unsigned int WIDTH = 200;
const unsigned int HEIGHT = 150;

//vec3 lenyeg(const int& height, const int& width, vec2 pixelCoord);

int main(){
	vec3 pixel_data[WIDTH*HEIGHT]; 
	vec2 pixel_coord = {0, 0};
	int pixel_counter = 0;

	for (size_t j = 0; j < HEIGHT; j++)
	{
		for (size_t i = 0; i < WIDTH; i++)
		{
			pixel_data[pixel_counter] = lenyeg(HEIGHT, WIDTH, pixel_coord);
			pixel_coord[0] = i;
			pixel_counter++;
		}
		pixel_coord[1] = j;
	}

    writeimage(WIDTH, HEIGHT, pixel_data);

}
