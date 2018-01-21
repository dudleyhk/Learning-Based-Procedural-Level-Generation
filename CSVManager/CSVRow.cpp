/*



*/
#include <sstream>

#include "CSVRow.h"

using namespace CSVManager;


std::string const& CSVRow::operator[](unsigned int index) const
{
	return data[static_cast<std::size_t>(index)];
}



const unsigned int CSVRow::Size() const
{
	return static_cast<unsigned int>(data.size());
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





