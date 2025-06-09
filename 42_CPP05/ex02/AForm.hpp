#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public: 
                const char *what() const throw();
        };

         class GradeTooLowException : public std::exception
        {
            public: 
                const char *what() const throw();
        };
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif