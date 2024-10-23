#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>

typedef std::string str;

class Interface
{
	private:

	public:
		Interface();
		Interface(const Interface &copy);
		~Interface();

		Interface &operator =(const Interface &copy);
};

#endif