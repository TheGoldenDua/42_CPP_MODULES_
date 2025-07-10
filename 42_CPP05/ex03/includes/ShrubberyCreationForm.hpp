/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:13:38 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:13:39 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
         ShrubberyCreationForm();
         ShrubberyCreationForm(std::string target);
         ShrubberyCreationForm(const  ShrubberyCreationForm& other);
         ShrubberyCreationForm& operator=(const  ShrubberyCreationForm& other);
        ~ ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
