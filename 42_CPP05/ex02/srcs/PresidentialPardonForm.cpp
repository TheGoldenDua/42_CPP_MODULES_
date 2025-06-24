#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
