#include "Contact.hpp"

Contact::Contact(){}

void Contact::setString(std::string name, int index)
{
	switch (index)
	{
	case 0:
		this->FirstName = name;
		break;
	case 1:
		this->LastName = name;
		break;
	case 2:
		this->Nickname = name;
		break;
	case 3:
		this->PhoneNumber = name;
		break;
	case 4:
		this->DarkestSecret = name;
		break;
	default:
		break;
	}
}

std::string Contact::getString(int index) const
{
	switch (index)
	{
	case 0:
		return this->FirstName;
		break;
	case 1:
		return this->LastName;
		break;
	case 2:
		return this->Nickname;
		break;
	case 3:
		return this->PhoneNumber;
		break;
	case 4:
		return this->DarkestSecret;
		break;
	default:
		break;
	}
	return NULL;
}

Contact::~Contact(){}
