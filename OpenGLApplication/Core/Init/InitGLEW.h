/*



*/
#pragma once
#include <iostream>

#include "Dependencies\GL\glew.h"
#include "Dependencies\GL\freeglut.h"



namespace Core
{
	namespace Init
	{
		class InitGLEW
		{
		public:
			InitGLEW() = default;
			~InitGLEW() = default;

			static void Init();

		private:

		};
	}
}