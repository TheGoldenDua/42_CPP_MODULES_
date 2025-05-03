/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:52:44 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/03 00:52:49 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str("HI THIS IS BRAIN");
    std::string &stringREF = str;
    std::string *stringPTR = &str;

    std::cout << "\n******************ADDRESSES**********************\n" << std::endl;

    std::cout << "Memmory Address of the string: " << &str 
              << "\nMemory Address of the string pointer: " << stringPTR
              << "\nMemory Address of the string reference: " << &stringREF << std::endl;

    std::cout << "\n******************VALUES**********************\n" << std::endl;

    std::cout << "Value of the string: " << str 
    << "\nValue of the string pointer: " << *stringPTR
    << "\nValue of the string reference: " << stringREF << std::endl;

    return 0;
}
