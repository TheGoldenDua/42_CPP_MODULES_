/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dua <dua@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:34 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 18:52:58 by dua              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        bool check_input(std::string str);
        void setContact();
        void displayContact() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
};

#endif
