#include "Array.hpp"

int main()
{
    try
    {
        Array<std::string> arr(5);

        arr[0] = "hello";
        arr[1] = "word";
        arr[2] = ",I am";
        arr[3] = "working on";
        arr[4] = "cpp arrays.";
        
        std::cout << arr[10] << std::endl;

        // std::cout << arr[] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
