/*



*/
#pragma once
#include <string>




namespace Rendering
{
	namespace Textures
	{
		class Texture
		{
		public:
			Texture()  = default;
			~Texture() = default;

			GLuint LoadTexture(const std::string& filename, const int& width, const int& height);

		private:

		};
	}
}