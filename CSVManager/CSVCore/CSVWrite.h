/*



*/
#pragma once
#include <fstream>
#include <string>
#include <vector>



namespace CSVManager
{
	class CSVWrite
	{
	public:
		CSVWrite() = default;
		~CSVWrite() = default;

		void WriteFile(const std::string& filename, const std::vector<std::string>& data);


	private:

		unsigned int LongestRow();

		const char COMMA = ',';

	};
}