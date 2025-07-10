/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:29 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:14:30 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);

    std::ofstream outfile(((this->target) + "_shrubbery").c_str());
    if(!outfile)
    {
        std::cerr << "ERROR\n"
                  << "Could not create the output file." << std::endl;
        return ;
    }
    
    outfile << "       ####      \n";
    outfile << "      #o#o##      \n";
    outfile << "    ##o###o###    \n";
    outfile << "   #o#\\#|#/###   \n";
    outfile << "    ###\\|/#o#    \n";
    outfile << "     # }|{  #    \n";
    outfile << "       }|{       \n";


    outfile.close();
}
