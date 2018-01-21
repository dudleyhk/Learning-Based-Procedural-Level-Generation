/*



*/
#pragma once
#include <string>
#include <vector>


namespace CSVManager
{
	class CSVRow
	{
	public:
		CSVRow()  = default;
		~CSVRow() = default;

		std::string const& operator[](unsigned int index) const;
		const unsigned int Size() const;

		void ReadNextRow(std::istream& str);


	private:
		std::vector<std::string> data;
	};


	inline std::istream& operator>>(std::istream& str, CSVRow& data)
	{
		data.ReadNextRow(str);
		return str;
	}
}


