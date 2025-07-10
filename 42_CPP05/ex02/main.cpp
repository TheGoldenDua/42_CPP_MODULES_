/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:18 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:14:21 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

int main()
{
    srand(time(0));

    try{
        Bureaucrat high("Boss", 1);
        Bureaucrat low("Bob", 150);

        ShrubberyCreationForm shrub("Dua");
        RobotomyRequestForm robot("Sou");
        PresidentialPardonForm pardon("Ari");

        std::cout << "\n----------------Shrub test-----------------\n" << std::endl;
        low.signForm(shrub);
        high.signForm(shrub);
        high.executeForm(shrub);

        std::cout << "\n----------------Robot test-----------------\n" << std::endl;
        high.signForm(robot);
        high.executeForm(robot);

        std::cout << "\n----------------Pardon test-----------------\n" << std::endl;
        high.signForm(pardon);
        high.executeForm(pardon);
        

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}
