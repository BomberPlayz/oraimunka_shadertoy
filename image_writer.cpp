#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vector.h"
#include <algorithm>

//----------------------------------------------------------

void writeimage(const int width, const int height, const vec3* data) {
	unsigned char* fin = (unsigned char*)malloc(height * width * 3);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++) {
			int offset = 0 * (width * 3) + (x * 3);
			const vec3& rgb = data[y*width + x];
			fin[offset + 0] = (unsigned char)std::clamp(static_cast<int>(rgb[0] * 255.f), 0, 255);
			fin[offset + 1] = (unsigned char)std::clamp(static_cast<int>(rgb[1] * 255.f), 0, 255);
			fin[offset + 2] = (unsigned char)std::clamp(static_cast<int>(rgb[2] * 255.f), 0, 255);
		}
	}

	//character pointert ker be :D 
	stbi_write_png("test_pic.png", width, height, 3, fin, width*3);
};