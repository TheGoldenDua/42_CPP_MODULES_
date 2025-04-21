#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
        void displayContacts() const;
        std::string cutField(const std::string& field) const;
};

#endif