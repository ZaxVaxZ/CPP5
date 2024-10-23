#include "Interface.hpp"

Interface::Interface()
{
	std::cout << "An Interface has been created!\n";
}

Interface::Interface(const Interface &copy)
{
	std::cout << "An Interface has been created with the same qualities as another!\n";
}

Interface &Interface::operator =(const Interface &copy)
{
	//if (&copy != this)
		//copy
	return *this;
}

Interface::~Interface()
{
	std::cout << "The Interface has been destroyed!\n";
}