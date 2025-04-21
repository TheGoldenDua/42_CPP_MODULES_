
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setContact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, FirstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, LastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, NickName);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, DarkestSecret);
}

void Contact::displayContact() const
{
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secret: " << DarkestSecret<< std::endl;
}

std::string Contact::getFirstName() const
{
    return FirstName;
}

std::string Contact::getLastName() const
{
    return LastName;
}

std::string Contact::getNickName() const
{
    return NickName;
}