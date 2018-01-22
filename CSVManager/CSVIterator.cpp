/*



*/
#include "CSVIterator.h"


using namespace CSVManager;



CSVIterator::CSVIterator(std::istream& str) :
	str(str.good() ? &str : nullptr)
{
	++(*this);
}

CSVIterator& CSVIterator::operator++()
{
	if(str)
	{
		// Stream the read line into the current Rows::data vector.
		if(!((*str) >> row))
		{
			str = nullptr;
		}
	}
	return *this;
}

CSVIterator CSVIterator::operator++(int)
{
	CSVIterator tmp(*this);
	++(*this);
	return tmp;
}

CSVRow const& CSVIterator::operator*() const
{
	return row;
}

CSVRow const* CSVIterator::operator->() const
{
	return &row;
}

// TODO: Work out what this is doing
bool CSVIterator::operator==(CSVIterator const& rhs)
{
	return ((this == &rhs) || ((this->str == nullptr) && (rhs.str == nullptr)));
}

bool CSVIterator::operator!=(CSVIterator const& rhs)
{
	return !((*this) == rhs);
}
