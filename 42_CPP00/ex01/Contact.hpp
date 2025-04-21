#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        Contact();
        ~Contact();

        void setContact();
        void displayContact() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
};

#endif