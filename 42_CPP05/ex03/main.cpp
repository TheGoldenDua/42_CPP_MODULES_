/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:12:30 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:12:31 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/Intern.hpp"
#include "includes/Bureaucrat.hpp"
#include <iostream>

int main()
{
    Intern randomIntern;

    AForm* form1 = randomIntern.makeForm("shrubbery creation", "Dua");
    AForm* form2 = randomIntern.makeForm("robotomy request", "Sou");
    AForm* form3 = randomIntern.makeForm("presidential pardon", "Ari");
    AForm* form4 = randomIntern.makeForm("unknown form", "Tani");

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
