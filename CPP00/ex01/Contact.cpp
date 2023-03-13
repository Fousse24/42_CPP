#include "Contact.hpp"

Contact::Contact()
{
	setFirstName("");
	setLastName("");
	setNickname("");
	setPhoneNumber("");
	setSecret("");
}

Contact::~Contact()
{

}

void Contact::setFirstName(std::string str)
{
	this->first_name = str;
}

void Contact::setLastName(std::string str)
{
	this->last_name = str;
}

void Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phone_number = str;
}

void Contact::setSecret(std::string str)
{
	this->secret = str;
}

std::string Contact::getFirstName()
{
	return (this->first_name);
}

std::string Contact::getLastName()
{
	return (this->last_name);
}

std::string Contact::getNickname()
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
	return (this->phone_number);
}

std::string Contact::getSecret()
{
	return (this->secret);
}