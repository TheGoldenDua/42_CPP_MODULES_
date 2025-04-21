
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
    int i = count % 8;
    arr[i].setContact();
    count++;
}

void PhoneBook::displayContacts() const
{
    int i;

    i = 0;
    std::cout << std::setw(10) << "Index" << "|"
              <<std::setw(10) << "First Name" << "|"
              <<std::setw(10) << "Last Name" << "|"
              <<std::setw(10) << "Nickname" << "|" << std::endl;
    while(i < 8)
    {
        std::cout << std::setw(10) << i << "|";

        std::string firstName = arr[i].getFirstName();
        std::string lastName = arr[i].getLastName();
        std::string nickName = arr[i].getNickName();

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickName.length() > 10)
            nickName = nickName.substr(0, 9) + ".";

        std::cout << std::setw(10) << firstName << "|"
                  << std::setw(10) << lastName << "|"
                  << std::setw(10) << nickName << std::endl;

        i++;
    } 
}

void PhoneBook::searchContact() const
{
    displayContacts();

    std::cout << "Enter index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '0';

    if (index < 0 || index >= count || index >= 8)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    arr[index].displayContact();
}

