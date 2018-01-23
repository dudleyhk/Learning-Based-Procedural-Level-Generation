/*



*/
#pragma once
#include <istream>

#include "CSVRow.h"


namespace CSVManager
{
	class CSVReadIterator
	{
	public:
		CSVReadIterator() = default;
		CSVReadIterator(std::istream& str);
		~CSVReadIterator() = default;

		// Pre Incremenet
		CSVReadIterator& operator++();

		// Post Increment
		CSVReadIterator  operator++(int);
		CSVRow const& operator*() const;
		CSVRow const* operator->() const;

		bool operator==(CSVReadIterator const& rhs);
		bool operator!=(CSVReadIterator const& rhs);

	private:
		std::istream* str = nullptr;
		CSVRow row;
	};
}