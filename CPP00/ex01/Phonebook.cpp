#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->contact_n = 0;
	this->contact_i = 0;
}

Phonebook::~Phonebook()
{

}

/* 
* Make a new string if the information is longer than 10 characters
* The new string will be 10 in length and terminated with an '.'
*/
std::string	Phonebook::adjustInfo(std::string info)
{
	std::string	adjusted;

	adjusted = info;
	if (adjusted.length() > 10)
	{
		adjusted = info.substr(0, 10);
		adjusted[9] = '.';
	}
	return (adjusted);
}

void	Phonebook::printInfo(std::string info)
{
	info = adjustInfo(info);
	std::cout << std::setw(10) << info;
	return ;
}

void	Phonebook::printContact(Contact cont, int id)
{
	std::cout << std::endl;
	std::cout << TERM_BLUE << "Informations of contact " << id << TERM_END << std::endl;

	std::cout << TERM_UNDER << "First name" << TERM_END << " : ";
	std::cout << cont.getFirstName() << std::endl;

	std::cout << TERM_UNDER << "Last name" << TERM_END << " : ";
	std::cout << cont.getLastName() << std::endl;

	std::cout << TERM_UNDER << "Nickname" << TERM_END << " : ";
	std::cout << cont.getNickname() << std::endl;

	std::cout << TERM_UNDER << "Phone number" << TERM_END << " : ";
	std::cout << cont.getPhoneNumber() << std::endl;

	std::cout << TERM_UNDER << "Darkest secret" << TERM_END << " : ";
	std::cout << cont.getSecret() << std::endl;

	std::cout << std::endl;
}

void	Phonebook::searchPrompt()
{
	std::cout << TERM_BLUE << std::setw(35) << "List of contacts" << TERM_END << std::endl;
	Phonebook::printInfo("index");
	std::cout << " | ";
	Phonebook::printInfo("first name");
	std::cout << " | ";
	Phonebook::printInfo("last name");
	std::cout << " | ";
	Phonebook::printInfo("nickname");
	std::cout << std::endl;

	for (int i = 0; i < this->contact_n; i++)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | ";
		Phonebook::printInfo(this->contacts[i].getFirstName());
		std::cout << " | ";
		Phonebook::printInfo(this->contacts[i].getLastName());
		std::cout << " | ";
		Phonebook::printInfo(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Enter the relevant contact index : ";
}

int	Phonebook::cmdSearch()
{
	std::string	input;
	int			id = 0;
	int			i = 0;

	Phonebook::searchPrompt();
	std::getline(std::cin, input);
	if (input.length() > 0)
	{
		while ((size_t)i < input.length() && std::isdigit(input.at(i)))
			i++;
		if ((size_t)i == input.length())
			id = std::stoi(input);
	}
	if (id <= this->contact_n && id > 0)
		Phonebook::printContact(this->contacts[id - 1], id);
	else
		std::cout << TERM_RED << "Invalid input" << TERM_END << std::endl;
	std::cout << std::endl;
	return (0);
}

int	Phonebook::cmdExit()
{
	exit(0);
	return (0);
}

int	Phonebook::cmdAdd()
{
	Contact		contact;
	std::string	input;

	std::cout << TERM_BLUE << "Enter the following informations" << TERM_END << std::endl;

	std::cout << TERM_UNDER << "First name" << TERM_END << " : ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << TERM_UNDER << "Last name" << TERM_END << " : ";
	std::getline(std::cin, input);
	contact.setLastName(input); 

	std::cout << TERM_UNDER << "Nickname" << TERM_END << " : ";
	std::getline(std::cin, input);
	contact.setNickname(input); 

	std::cout << TERM_UNDER << "Phone number" << TERM_END << " : ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << TERM_UNDER << "The darkest secret that haunts the contact's soul" << TERM_END << " : ";
	std::getline(std::cin, input);
	contact.setSecret(input);

	std::cout << std::endl;

	// Increment the number of contacts (up to 8) and move the index
	this->contacts[this->contact_i++] = contact;
	if (this->contact_i == 8)
		this->contact_i = 0;
	if (this->contact_n != 8)
		this->contact_n++;
	return (0);
}
