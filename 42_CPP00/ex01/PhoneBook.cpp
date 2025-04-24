/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:47 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:48 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
    int index = count % 8;
    contacts[index].setContact();
    count++;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count && i < 8; i++)
    {
        std::cout << std::setw(10) << i << "|";

        std::string firstName = contacts[i].getFirstName();
        std::string lastName = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickName();

        std::cout << std::setw(10) << cutField(firstName) << "|"
                  << std::setw(10) << cutField(lastName) << "|"
                  << std::setw(10) << cutField(nickname) << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    displayContacts();

    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
        return;
    }

    int index = input[0] - '0';

    if (index < 0 || index >= count || index >= 8)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    contacts[index].displayContact();
}

std::string PhoneBook::cutField(const std::string& field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}
