/*

*/
#include "ModelsManager.h"



using namespace Managers;
using namespace Rendering;



ModelsManager::ModelsManager()
{

	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("ColorShader"));
	triangle->Create();
	gameModels["Triangle"] = triangle;

}

ModelsManager::~ModelsManager()
{
	for(auto model : gameModels)
	{
		delete model.second;
	}
	gameModels.clear();
}

void ModelsManager::DeleteModel(const std::string& gameModelName)
{
	// TODO : Use algorithm utilities to check if this is valid
	IGameObject* model = gameModels[gameModelName];
	model->Destroy();
	gameModels.erase(gameModelName);
}

const IGameObject& ModelsManager::GetModel(const std::string& gameModelName) const
{
	// TODO : Use algorithm utilities to check if this is valid
	return (*gameModels.at(gameModelName));
}

void ModelsManager::Update()
{
	for(auto model : gameModels)
	{
		model.second->Update();
	}
}

void ModelsManager::Draw()
{
	for(auto model : gameModels)
	{
		model.second->Draw();
	}
}