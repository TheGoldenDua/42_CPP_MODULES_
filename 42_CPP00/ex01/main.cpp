/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:38 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:39 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string input;

    while (input != "EXIT")
    {
        std::cout << "Select a command: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "> ";

        if (!std::getline(std::cin, input))
            return (1); 

        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input != "EXIT")
            std::cout << "Unknown command. Please use ADD, SEARCH, or EXIT." << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;
    return (0);
}
