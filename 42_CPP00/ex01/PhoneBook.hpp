/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:52 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:53 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
