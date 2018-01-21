/*



*/
#pragma once
#include <istream>

#include "CSVRow.h"


namespace CSVManager
{
	class CSVIterator
	{
	public:
		CSVIterator() = default;
		CSVIterator(std::istream& str);
		~CSVIterator() = default;

		// Pre Incremenet
		CSVIterator& operator++();

		// Post Increment
		CSVIterator  operator++(int);
		CSVRow const& operator*() const;
		CSVRow const* operator->() const;

		bool operator==(CSVIterator const& rhs);
		bool operator!=(CSVIterator const& rhs);

	private:
		std::istream* str = nullptr;
		CSVRow row;
	};
}