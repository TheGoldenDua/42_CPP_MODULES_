/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:12:08 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:12:09 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac , char **av)
{
    if(ac != 2)
    {
        std::cerr << ("Error: (usage: ./Rpn expression)") << std::endl ;
        return 1;
    }

    RPN rpn;
    try
    {
        rpn.processInput(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
