#include "Account.hpp"
#include <iostream>
#include <ctime> 
#include <iomanip> 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
	_amount = initial_deposit; //accoun't starting money
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created:" << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);           // Get current time (seconds since 1970)
    std::tm *t = std::localtime(&now);           // Convert to local time (year, month, etc.)

    std::cout << "[" 
              << std::setfill('0') << std::setw(4) << t->tm_year + 1900  // Year
              << std::setw(2) << t->tm_mon + 1                            // Month (0-11) → (1-12)
              << std::setw(2) << t->tm_mday                               // Day
              << "_" 
              << std::setw(2) << t->tm_hour                               // Hour
              << std::setw(2) << t->tm_min                                // Minute
              << std::setw(2) << t->tm_sec                                // Second
              << "] ";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;

	if(_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;

	return true;
}

void Account::displayStatus() const //doesn't modify the account data
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  <<std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}