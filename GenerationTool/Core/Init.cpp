/*



*/
#pragma comment (lib, "CSVManager.lib") 

#include <iostream> // TODO: If in Debug Mode - Log to output window.

#include "CSVCore/CSVReadIterator.h"
#include "CSVCore/CSVWrite.h"

#include "Init.h"

using namespace GenerationTool::Core;




void Init::ReadWriteExample()
{
	auto filename = "..//Resources//CSV Data//Totals.csv";
	std::ifstream file(filename);
	if(!file.good())
	{
		std::cout << "ERROR: CSV file '" << filename << "' empty" << std::endl;
	}
	std::vector<std::string> out_data;
	
	
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
	int debug = 0;

}