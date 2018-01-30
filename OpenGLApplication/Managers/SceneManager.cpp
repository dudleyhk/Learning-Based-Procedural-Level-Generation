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
	if(!shader_manager)
	{
		std::cout << "ERROR instantiating ShaderManager class" << std::endl;
		return;
	}

	shader_manager->CreateProgram("ColourShader",
								  "Shaders\\VertexShaders\\",   "VertexShader",
								  "Shaders\\FragmentShaders\\", "FragmentShader");

	shader_manager->CreateProgram("TextureShader",
								  "Shaders\\VertexShaders\\",   "TextureShaderVS",
								  "Shaders\\FragmentShaders\\", "TextureShaderFS");



	models_manager = std::make_unique<ModelsManager>();
	if(!models_manager)
	{
		std::cout << "ERROR instantiating ModelManager class" << std::endl;
		return;
	}



	//https://www.youtube.com/watch?v=RnXDUFq7T6A
	

	int width;
	int height;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto image = SOIL_load_image("..//Resources//mario1-1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	if(!image)
	{
		std::cout << "ERROR: Image location invalid" << std::endl;
		return;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}


void SceneManager::NotifyBeginFrame()
{
	models_manager->Update();

	// TODO: Create an interface class to handle the Parsing and Generation
	// GenerationTool::Core::Init init;
	// init.ReadWriteExample();
}

void SceneManager::NotifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);





	auto program = shader_manager->GetShader("TextureShader");
	if(program < 0)
	{
		std::cout << "ERROR: Invalid shader name" << std::endl;
		return;
	}

	auto intex_loc = glGetUniformLocation(program, "in_texture");
	if(intex_loc != GLEW_OK)
	{
		std::cout << "ERROR getting uniform location of texture" << std::endl;
		return;
	}

	glUseProgram(program);
	glUniform1i(intex_loc, 0);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glBindSampler(0, GL_LINEAR);


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