/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:45 by del-ganb          #+#    #+#             */
/*   Updated: 2025/06/27 10:14:46 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), signGrade(gradeToSign), execGrade(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSign() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->signGrade;
}

int AForm::getGradeToExec() const
{
    return this->execGrade;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() > signGrade)
        throw GradeTooLowException();
    if(isSigned)
        return ;
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "AForm " << f.getName()
        << " (Sign grade: " << f.getGradeToSign()
        << ", Exec grade: " << f.getGradeToExec()
        <<") is ";
	if (f.getSign())
		out << " signed." << std::endl;
	else
		out << " not signed." << std::endl;
	return out;
}

void AForm::checkExecution(Bureaucrat const & executor) const
{
    if(!this->getSign())
        throw AForm::FormNotSignedException();

    if(executor.getGrade() > this->getGradeToExec())
        throw AForm::FormNotSignedException();
}
