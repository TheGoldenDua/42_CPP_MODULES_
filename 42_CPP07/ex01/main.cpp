/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:07:31 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/17 23:07:32 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::cout << "printing an array of integers:" << std::endl;
    int I[5] = {1, 2, 3, 4, 5};
    iter(I, 5, print);

    std::cout << "\nprinting an array of strings:" << std::endl;
    std::string S[] = {"hello", "world", "I am", "using", "templates!"};
    iter(S, 5, print);

    std::cout << "\nprinting an array of characters:" << std::endl;
    char C[] = {'h', 'e', 'l', 'l', 'o'};
    iter(C, 5, print);
    return 0;
}
