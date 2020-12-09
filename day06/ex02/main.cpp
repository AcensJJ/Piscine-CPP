
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate(void)
{
	Base *ret;
	int i = std::rand() % 3;

	if (!i)
	{
		ret = new A();
	}
	else if (i == 1)
	{
		ret = new B();
	}
	else
	{
		ret = new C();
	}
	return (ret);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;

}

void identify_from_reference( Base & p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int main2(void)
{
	Base *special;
	A *a = new A();
	B *b = new B();
	C *c = new C();
	std::srand(std::time(nullptr));

	special = generate();
	identify_from_pointer(special);
	identify_from_reference(*special);
	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);
	delete (a);
	return (1);
}

int	main(void)
{
	main2();
	while (1)
	{

	}

	return (0);
}