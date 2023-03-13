#include	<iostream>
#include	<iomanip>
#include	"Phonebook.hpp"

int	processCommand(Phonebook *book, std::string cmd)
{
	int	exit = 0;

	if (cmd.size() == 0)
		return (exit);
	if (!cmd.compare(0, cmd.size(), "ADD"))
		book->cmdAdd();
	if (!cmd.compare(0, cmd.size(), "SEARCH"))
		book->cmdSearch();
	if (!cmd.compare(0, cmd.size(), "EXIT"))
	{
		book->cmdExit();
		exit = 1;
	}
	return (exit);
}

void	printWelcome()
{
	std::cout << "\033[1;43;34m";
	std::cout << "Welcome to your horrible Phonebook!";
	std::cout << TERM_END << std::endl;
}

std::string	commandPrompt()
{
	std::string	cmd;

	std::cout << "Please enter a command (";
	std::cout << TERM_YELLOW;
	std::cout << "ADD SEARCH EXIT";
	std::cout << TERM_END;;
	std::cout << ") : ";
	std::getline(std::cin, cmd);
	std::cout << std::endl;
	return (cmd);
}

int main()
{
	Phonebook 	phonebook;
	std::string	cmd;
	int			exit = 0;

	printWelcome();
	while (!exit)
	{
		cmd = commandPrompt();
		exit = processCommand(&phonebook, cmd);
	}
    return 0;
}
