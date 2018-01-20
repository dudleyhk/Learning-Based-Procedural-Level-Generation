/*



*/
#include "SceneManager.h"

using namespace Managers;


SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = std::make_unique<ShaderManager>();
	shader_manager->CreateProgram("ColorShader",
								  "Shaders\\VertexShaders\\VertexShader.glsl",
								  "Shaders\\FragmentShaders\\FragmentShader.glsl");

	models_manager = std::make_unique<ModelsManager>();

}


void SceneManager::NotifyBeginFrame()
{
	models_manager->Update();
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