/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:12:00 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/03 12:21:06 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

Base *generate(void)
{
    Base *res;
    int i = rand() % 3;

    if(i == 1)
    {
        res = new A;
        std::cout << "Generated A" << std::endl;
    }
    else if(i == 2)
    {
        res = new B;
        std::cout << "Generated B" << std::endl;
    }
    else
    {
        res = new C;
        std::cout << "Generated c" << std::endl;
    }
    return (res);
}

void identify(Base* p)
{
   if (!p)
    {
        std::cout << "Null pointer!" << std::endl;
        return;
    }

    A* derivedA = dynamic_cast<A*>(p);
    B* derivedB = dynamic_cast<B*>(p);
    C* derivedC = dynamic_cast<C*>(p);

    if(derivedA)
        std::cout << "A" << std::endl;
    else if(derivedB)
        std::cout << "B" << std::endl;
    else if(derivedC)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type!" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& derivedA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void) derivedA;
        return ;
    }
    catch (std::exception& e){}

    try
    {
        B& derivedB = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void) derivedB;
        return ;
    }
    catch (std::exception& e){}
    
    try
    {
        C& derivedC = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void) derivedC;
        return ;
    }
    catch (std::exception& e){}

    std::cout << "Unknown type!" << std::endl;
}

int main()
{
    srand(time(NULL));

    Base *ptr = generate();

    std::cout << "Using pointer: ";
    identify(ptr);
    
    std::cout << "-------------------" << std::endl;

    std::cout << "Using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
