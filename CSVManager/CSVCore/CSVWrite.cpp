/*



*/
#include "CSVWrite.h"

using namespace CSVManager;


void CSVWrite::WriteFile(const std::string& filename, const std::vector<std::string>& data)
{
	std::ofstream file(filename);
	if(!file.good()) return;

	//auto longest_row = CSVRow.LongestRow("..//Resources//Totals.csv");

	std::vector<std::string> csv_data;
	std::string string_data;

	int i = 0;
	for(const auto& value : data)
	{
		if(i % 6 == 0 && i > 0)
		{
			string_data += "\n";
		}

		string_data += value;
		string_data += COMMA;

		i++;
	}
	string_data.pop_back();

	file << string_data;
	file.close();
}
