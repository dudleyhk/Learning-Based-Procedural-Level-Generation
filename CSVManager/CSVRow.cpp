/*



*/
#include <sstream>

#include "CSVRow.h"

using namespace CSVManager;


std::string const& CSVRow::operator[](std::size_t index) const
{
	return data[index];
}



const std::size_t CSVRow::Size() const
{
	return data.size();
} 



void CSVRow::ReadNextRow(std::istream& str)
{
	std::string line;
	std::getline(str, line);

	std::stringstream lineStream(line);
	std::string       cell;

	data.clear();
	while(std::getline(lineStream, cell, ','))
	{
		data.push_back(cell);
	}

	// Check for trailing comma
	if(!lineStream && cell.empty())
	{
		// add empty element at the end
		data.push_back("");
	}
}





