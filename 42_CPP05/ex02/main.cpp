
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    srand(time(0));

      srand(time(0));

    try{
        Bureaucrat high("Boss", 1);
        Bureaucrat low("Peon", 150);

        ShrubberyCreationForm shrub("Dua");
        RobotomyRequestForm robot("Sou");
        PresidentialPardonForm pardon("Ari");

        low.signForm(shrub);
        high.signForm(shrub);
        high.executeForm(shrub);

        std::cout << "---------------------------------" << std::endl;
        high.signForm(robot);
        high.executeForm(robot);

        std::cout << "---------------------------------" << std::endl;
        high.signForm(pardon);
        high.executeForm(pardon);
        

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}


