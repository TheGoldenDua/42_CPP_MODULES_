/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:07:00 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/17 23:07:01 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<std::string> arr(5);

        arr[0] = "hello";
        arr[1] = "word";
        arr[2] = ",I am";
        arr[3] = "working on";
        arr[4] = "cpp arrays.";
        
        std::cout << arr[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
