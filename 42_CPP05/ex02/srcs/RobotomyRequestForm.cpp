/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:33 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:14:34 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);

    std::cout << "* drilling noises *" << std::endl;

    if(rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else    
        std::cout << "ERROR\n"
                  << "robotomy failed!"
                  <<std::endl;
}
