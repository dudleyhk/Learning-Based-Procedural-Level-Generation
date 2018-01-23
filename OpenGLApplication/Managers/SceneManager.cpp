/*
	


*/
#include <fstream>

#include "../Dependencies/SOIL2/SOIL2.h"

#include "GenerationTool\Core\Init.h"

#include "SceneManager.h"






using namespace Managers;


SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = std::make_unique<ShaderManager>();
	shader_manager->CreateProgram("ColourShader",
								  "Shaders\\VertexShaders\\VertexShader.glsl",
								  "Shaders\\FragmentShaders\\FragmentShader.glsl");

	models_manager = std::make_unique<ModelsManager>();
}


void SceneManager::NotifyBeginFrame()
{
	models_manager->Update();

	// TODO: Create an interface class to handle the Parsing and Generation
	GenerationTool::Core::Init init;
	init.ReadWriteExample();

	int width;
	int height;

	//https://www.youtube.com/watch?v=RnXDUFq7T6A
	unsigned char* image = SOIL_load_image("..Resorces//mario1-1.png", &width, &height,0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void SceneManager::NotifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	models_manager->Draw();
}

void SceneManager::NotifyEndFrame()
{
	//nothing here for the moment
}

void SceneManager::NotifyResize(int width, int height,
								  int previous_width, int previous_height)
{
	//nothing here for the moment 
}