#include "span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : size(0)
{
	this->arr.reserve(0);
}

Span::Span( unsigned int n) : size(n)
{
	this->arr.reserve(n);
}

Span::Span( const Span & src ) : size(src.getSize())
{
	this->arr.reserve(src.getSize());
	copy(src.arr.begin(), src.arr.end(), back_inserter(this->arr));
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		unsigned int& n = const_cast<unsigned int&>(this->size);
		n = rhs.getSize();
		this->arr.reserve(rhs.getSize());
		copy(rhs.arr.begin(), rhs.arr.end(), back_inserter(this->arr));
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getSize() const
{
	return (this->size);
}

void Span::addNumber(int nb)
{
	if (this->size > this->arr.size())
		this->arr.push_back(nb);
	else
		throw Span::MaxSizeOfVectorException();

}

long Span::longestSpan()
{
	if (this->arr.size() < 2)
		throw Span::NoValueException();
	int ishort(INT_MAX);
	int ilongest(INT_MIN);
	for (std::vector<int>::iterator ptr = arr.begin(); ptr != arr.end(); ptr++)
	{
		*ptr > ilongest ? ilongest = *ptr: 0;
		*ptr < ishort ? ishort = *ptr: 0;
	}
	return (static_cast<long>(ilongest) - static_cast<long>(ishort));
}

long Span::shortestSpan()
{
	if (this->arr.size() < 2)
		throw Span::NoValueException();
	long ret(UINT_MAX);
	std::vector<int> ptr = this->arr;
	std::sort (ptr.begin(), ptr.end());
	std::vector<int>::iterator it = ptr.begin();
	for (size_t i = this->arr.size(); i > 1; --i)
	{
		std::vector<int>::iterator cmp = it++;
		if (*cmp == *it)
			return (0);
		if ((static_cast<long>(*it) - static_cast<long>(*cmp)) < ret)
			ret = (static_cast<long>(*it) - static_cast<long>(*cmp));
	}
	return (ret);
}

const char* Span::MaxSizeOfVectorException::what() const throw ()
{
    return ("Max size reach");
}

const char* Span::NoValueException::what() const throw ()
{
    return ("Can't find span (zero or only one value)");
}

/* ************************************************************************** */