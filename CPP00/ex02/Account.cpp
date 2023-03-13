#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <time.h>
#include <unistd.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::getNbAccounts();
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (this->_amount - withdrawal <= 0)
	{
		std::cout << "refused";
		std::cout << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return true;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		time;
	struct tm	t_stamp;

	std::time(&time);
	t_stamp = *std::localtime(&time);
	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(4) << 1900 + t_stamp.tm_year;
	std::cout << std::setfill('0') << std::setw(2) << t_stamp.tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << t_stamp.tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << t_stamp.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << t_stamp.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << t_stamp.tm_sec;
	std::cout << "] ";
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}