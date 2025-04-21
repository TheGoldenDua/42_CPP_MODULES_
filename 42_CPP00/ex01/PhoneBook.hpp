#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
        Contact arr[8];
        int count;
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
        void displayContacts() const;
};

#endif