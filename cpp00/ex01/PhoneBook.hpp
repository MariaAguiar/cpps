#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void Add();
        void Search();
	private:
		Contact contacts[8];
        int index;
};

#endif