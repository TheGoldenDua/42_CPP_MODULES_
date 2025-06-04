#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n--------------Valid signing---------------\n";
    try 
    {
        Bureaucrat Dua("Dua", 42);
        Form Contract("Contract", 50, 20);

        std::cout << Contract << std::endl;
        Dua.signForm(Contract);
        std::cout << Contract << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--------------Invalid signing ( too low)---------------\n";
    try 
    {
        Bureaucrat Sou("Sou", 120);  
        Form Taxs("taxs", 50, 30);

        std::cout << Taxs << std::endl;
        Sou.signForm(Taxs);
        std::cout << Taxs << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected error:" << e.what() << std::endl;  
    }

    std::cout << "\n------------Already signed form--------------\n";
    try 
    {
        Bureaucrat Ari("Ari", 40);
        Form nda("NDA", 50, 10);

        Ari.signForm(nda);  
        Ari.signForm(nda);
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }    

    return 0;
}
