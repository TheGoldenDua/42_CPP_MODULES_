#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try
    {
        std::cout << "------testing with vector------" << std::endl;
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "value found in vector: " << *it << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Vector: " << e.what() << std::endl;
    }



    std::list<int> l;
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);
    l.push_back(14);
    l.push_back(15);

    try
    {
        std::cout << "\n------testing with list------" << std::endl;
        std::list<int>::iterator it = easyfind(l, 55);
        std::cout << "value found in list: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "List: " << e.what() << std::endl;
    }
    return (0);
}


