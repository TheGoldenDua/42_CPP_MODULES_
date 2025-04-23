#include "Account.hpp"
#include <iostream>
#include <ctime> // for std::time, std::localtime
#include <iomanip> // for std::setw, std::setfill

// Initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}
