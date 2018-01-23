/*



*/
#include "CSVReadIterator.h"


using namespace CSVManager;



CSVReadIterator::CSVReadIterator(std::istream& str) :
	str(str.good() ? &str : nullptr)
{
	++(*this);
}

/* Get the next row. */
CSVReadIterator& CSVReadIterator::operator++()
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

CSVReadIterator CSVReadIterator::operator++(int)
{
	CSVReadIterator tmp(*this);
	++(*this);
	return tmp;
}

CSVRow const& CSVReadIterator::operator*() const
{
	return row;
}

CSVRow const* CSVReadIterator::operator->() const
{
	return &row;
}

// TODO: Work out what this is doing
bool CSVReadIterator::operator==(CSVReadIterator const& rhs)
{
	return ((this == &rhs) || ((this->str == nullptr) && (rhs.str == nullptr)));
}

bool CSVReadIterator::operator!=(CSVReadIterator const& rhs)
{
	return !((*this) == rhs);
}
