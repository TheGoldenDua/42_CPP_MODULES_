/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:41:17 by del-ganb          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:18 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int j;

    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        i =1;
        while(i < ac)
        {
            std::string str(av[i]);
            j = 0;
            while(j < str.length())
            {
                std::cout << (char)std::toupper(str[j]);
                j++;
            }
            if(i < ac - 1)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}
