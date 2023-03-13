#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define	TERM_RED	"\033[1;31m"
#define	TERM_BLUE	"\033[1;34m"
#define	TERM_YELLOW	"\033[1;33m"
#define	TERM_UNDER	"\033[1;4m"
#define	TERM_END	"\033[0m"

#include	"Contact.hpp"
#include	<iostream>
#include	<iomanip>

class Phonebook
{
private:
	Contact	contacts[8];
	int		contact_n;
	int		contact_i;

public:
    Phonebook(void);
    ~Phonebook();

	int			cmdSearch();
	void		searchPrompt();
	int			cmdExit();
	int			cmdAdd();
	void		printContact(Contact cont, int id);
	void		printInfo(std::string info);
	std::string	adjustInfo(std::string info);
};

#endif