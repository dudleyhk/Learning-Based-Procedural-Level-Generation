/*



*/
#pragma once


#pragma once
#include <map>

#include "ShaderManager.h"
#include "Rendering/IGameObject.h"
#include "Rendering/Models/Triangle.h"


namespace Managers
{
	class ModelsManager
	{
	public:
		ModelsManager();
		~ModelsManager();

		void Draw();
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const Rendering::IGameObject& GetModel(const std::string& gameModelName) const;

	private:
		std::map<std::string, Rendering::IGameObject*> gameModels;
	};
}