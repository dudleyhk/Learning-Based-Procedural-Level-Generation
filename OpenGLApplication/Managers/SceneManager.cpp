/*
	


*/
#include <fstream>

#include "SceneManager.h"

#include "CSVIterator.h"



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

	auto filename = "..//Resources//Totals.csv";
	std::ifstream file(filename);
	if(!file.good())
	{
		std::cout << "ERROR: CSV file '" << filename << "' empty" << std::endl;
	}
	
	int i = 0;
	// TODO: Create an interface class to handle the level generation
	for(CSVManager::CSVIterator iter(file); iter != CSVManager::CSVIterator(); iter++)
	{
		auto row = *iter;
		for(auto i = 0; i < row.Size(); i++)
		{
			std::cout << "Cell - " << row[i] << std::endl;
		}
	}
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