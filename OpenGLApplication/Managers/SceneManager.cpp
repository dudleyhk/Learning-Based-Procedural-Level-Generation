/*
	


*/
#include <fstream>

#include "SceneManager.h"

#include "CSVReadIterator.h"
#include "CSVWrite.h"



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

	auto filename = "..//Resources//CSV Data//Totals.csv";
	std::ifstream file(filename);
	if(!file.good())
	{
		std::cout << "ERROR: CSV file '" << filename << "' empty" << std::endl;
	}
	std::vector<std::string> out_data;

	// TODO: Create an interface class to handle the level generation
	for(CSVManager::CSVReadIterator iter(file); iter != CSVManager::CSVReadIterator(); iter++)
	{
		auto row = *iter;
		for(auto i = 0; i < row.Size(); i++)
		{
			std::cout << "Cell - " << row[i] << std::endl;
			out_data.push_back(row[i]);
		}
	}
	out_data[0] = "TEST FILE";


	CSVManager::CSVWrite write;
	write.WriteFile("..//Resources//CSV Data//TestOut.csv", out_data);
	int i = 0;
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