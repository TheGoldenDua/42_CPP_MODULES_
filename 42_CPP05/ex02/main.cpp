
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

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

        std::cout << "\n----------------Robot test-----------------\n" << std::endl;
        high.signForm(robot);
        high.executeForm(robot);

        std::cout << "\n----------------Presidential test-----------------\n" << std::endl;
        high.signForm(pardon);
        high.executeForm(pardon);
        

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}

