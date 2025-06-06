#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;

    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

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
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif