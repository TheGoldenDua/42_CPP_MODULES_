/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dua <dua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:27 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 18:57:33 by dua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool Contact::check_input(std::string str)
{
    int i = 0;
    if(str.empty())
    {
        std::cout << "Empty input!" << std::endl;
        return (false);
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if(isprint(str[i]) == 0 || str[i] == 32)
        {
            std::cout << "Non printable charachters!" << std::endl;
            return (false);
        }
    }
    return (true);
}

void Contact::setContact()
{
    std::string tmp;
    while(true && !std::cin.eof())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, tmp);
        if(check_input(tmp))
        {
            this->FirstName = tmp;
            break;
        }
    }

    while(true && !std::cin.eof())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, tmp);
        if(check_input(tmp))
        {
            this->LastName = tmp;
            break;
        }
    }
    
    while(true && !std::cin.eof())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, tmp);
        if(check_input(tmp))
        {
            this->NickName = tmp;
            break;
        }
    }
    
    while(true && !std::cin.eof())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, tmp);
        if(check_input(tmp))
        {
            this->PhoneNumber = tmp;
            break;
        }
    }

    while(true && !std::cin.eof())
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, tmp);
        if(check_input(tmp))
        {
            this->DarkestSecret = tmp;
            break;
        }
    }
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

std::string Contact::getPhoneNumber() const
{
    return PhoneNumber;
}
