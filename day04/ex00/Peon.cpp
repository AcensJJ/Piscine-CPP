#include "Peon.hpp"

Peon::Peon()
{
	try
	{
		throw 20;
	}
	catch(int a) {
		std::cout << "Some random peon called " << Name << " just appeared!" << std::endl;
   	}
}

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}

Peon & operator=(const Peon &rhs)
{
	if (this == &rhs)
		return (*this);
	Victim::operator=(rhs);
	return (*this);
}