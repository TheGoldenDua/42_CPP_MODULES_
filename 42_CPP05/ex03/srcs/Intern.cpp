/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:13:10 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:13:11 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

static AForm* createShrubberyForm(const std::string& target);

static AForm* createRobotomyForm(const std::string& target);

static AForm* createPresidentialForm(const std::string& target);

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

typedef AForm* (*createForm)(const std::string&);

typedef struct s_data
{
    std::string formName;
    createForm newInstance;
} t_data;

static AForm* createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string name, std::string target)
{
    t_data forms[] = {
        { "shrubbery creation", createShrubberyForm },
        { "robotomy request", createRobotomyForm },
        { "presidential pardon", createPresidentialForm }
    };
    

    for (size_t i = 0; i < 3; i++)
    {
        if(name == forms[i].formName)
        {
            AForm *newForm = forms[i].newInstance(target);
            std::cout << "Intern creates " << name << std::endl;
            return newForm;
        }
    }
    std::cout << "Intern couldn’t find the form " << name << std::endl;
    return NULL;
}
