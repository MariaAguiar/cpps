#include <iostream>
#include <ctime>
#include "Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";created" << std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
}

int Account::getNbAccounts( void )
{
	return(Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return(Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return(Account::_totalNbWithdrawals);
}

void	 Account::_displayTimestamp( void )
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer, 80,"[%Y%m%d_%H%M%S] ",timeinfo);
	std::cout << buffer;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit
	<< ";amount:" << this->_amount + deposit
	<< ";nb_deposits:" << ++this->_nbDeposits
	<< std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}
bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount - withdrawal
		<< ";nb_withdrawals:" << ++this->_nbWithdrawals
		<< std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return true;
	}
	std::cout
	<< "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";withdrawal:refused"
	<< std::endl;
	return false;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed" << std::endl;
}
