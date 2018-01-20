/*



*/
#include <iostream>
#include <string>

#include "Dependencies\GL\freeglut.h"
#include "Dependencies\GL\glut.h"
#include "Dependencies\PNG\png.h"

#include "Texture.h"

#define TEXTURE_LOAD_ERROR 0;

using namespace Rendering::Textures;




GLuint Texture::LoadTexture(const std::string & filename, const int & width, const int & height)
{
	//// header for testing if it is a png (png_byte is a typedef for below but erroring)
	//png_byte header[8];
	// 

	//FILE* file_ptr;
	//auto result = fopen_s(&file_ptr, filename.c_str(), "rb");
	//if(result != 0)
	//{
	//	// TODO: Look into errorno handling.
	//	std::cout << "ERROR: Filename '" << filename << "' invalid." << std::endl;
	//	return TEXTURE_LOAD_ERROR;
	//}

	//if(!file_ptr)
	//	return TEXTURE_LOAD_ERROR;

	//// read the header
	//fread(header, 1, 8, file_ptr);

	//// test if file is png
	//int is_png = !png_sig_cmp(header, 0, 8);
	//if(!is_png)
	//{
	//	fclose(file_ptr);
	//	return TEXTURE_LOAD_ERROR;
	//}

	//// create png structure
	//png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	//if(!png_ptr)
	//{
	//	fclose(file_ptr);
	//	return TEXTURE_LOAD_ERROR;
	//}



	return 0;
}
