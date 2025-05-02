#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
}

void Harl::error(void)
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*pfunc[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int index = -1;
    int i = 0;
    while(i < 4) 
    {
        if (levels[i] == level) {
            index = i;
            break;
        }
        i++;
    }

    switch (index) {
        case 0:
            (this->*pfunc[0])();
            break;
        case 1:
            (this->*pfunc[1])();
            break;
        case 2:
            (this->*pfunc[2])();
            break;
        case 3:
            (this->*pfunc[3])();
            break;
        default:
            std::cout << "*************ERROR*************\n" 
                      << "Invalid level!" 
                      << std::endl;
    }
}

