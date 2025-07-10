/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:15:57 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:15:58 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n--------------Valid grade---------------\n";
    try
    {
        Bureaucrat Dua("Dua", 42);
        std::cout << Dua << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Invalid high grade---------------\n";
    try
    {
        Bureaucrat Sou("Sou", 0); 
        std::cout << Sou << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Invalid low grade---------------\n";
    try
    {
        Bureaucrat Bob("Bob", 200);
        std::cout << Bob << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Testing incrementGrade-------------\n";
    try
    {
        Bureaucrat Ari("Ari", 10);
        std::cout << Ari << std::endl;
        Ari.incrementGrade();
        std::cout << "incremented grade:\n";
        std::cout << Ari << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Testing decrementGrade-------------\n";
    try
    {
        Bureaucrat Tani("Tani", 151);
        std::cout << Tani << std::endl;
        Tani.decrementGrade();
        std::cout << "decremented grade:\n";
        std::cout << Tani << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Testing increment at max grade-------------\n";
    try
    {
        Bureaucrat Max("Max", 1);
        std::cout << Max << std::endl;
        Max.incrementGrade(); 
    } 
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--------------Testing copy constructor and assignment-------------\n";
    try
    {
        Bureaucrat Original("Original", 50);
        Bureaucrat Copy(Original);
        std::cout << "Copy: " << Copy << std::endl;

        Bureaucrat Another("Another", 100);
        Another = Original;
        std::cout << "Assigned: " << Another << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
