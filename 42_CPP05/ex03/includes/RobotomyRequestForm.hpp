/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:13:42 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:13:43 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
         RobotomyRequestForm();
         RobotomyRequestForm(std::string target);
         RobotomyRequestForm(const  RobotomyRequestForm& other);
         RobotomyRequestForm& operator=(const  RobotomyRequestForm& other);
        ~ RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
