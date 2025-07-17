/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:07:35 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/17 23:09:31 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void print(const T& add)
{
    std::cout << add << std::endl;
}

template <typename T> void iter(T* arr, size_t length, void (*func)(const T&))
{
    if(length == 0 )
    {
        std::cout << "Empty array!" << std::endl;
        return ;
    }
    for(size_t i = 0; i < length; i++)
    {
        std::cout << "array[" << i << "] = ";
        func(arr[i]);
    }
}

#endif
