#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), signGrade(gradeToSign), execGrade(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->signGrade;
}

int Form::getGradeToExec() const
{
    return this->execGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() > signGrade)
        throw GradeTooLowException();
    if(isSigned)
        return ;
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form " << f.getName()
        << " (Sign grade: " << f.getGradeToSign()
        << ", Exec grade: " << f.getGradeToExec()
        <<") is ";
	if (f.getSign())
		out << " signed." << std::endl;
	else
		out << " not signed." << std::endl;
	return out;
}