#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0, found;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result += line.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += line.substr(pos);
    return result;
}


int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string line;
    
    s1 = av[2];
    s2 = av[3];
    if(ac != 4)
    {
        std::cout << "*************Wrong Parametrs!*********\n"
                  << "Expected 3 arguments : <file_name> <string to replace> <replacement string>." << std::endl;
        return 1;
    }
    if(s1.empty() || s2.empty())
    {
        std::cout << "*************ERROR***************\n"
        << "The string to replace cannot be empty." << std::endl;
        return 1;
    }
    
    std::ifstream infile(av[1]);
    if(!infile)
    {
        std::cout << "*************ERROR***************\n"
                  << "Could not open the input file." << std::endl;
        return 1;
    }
    std::ofstream outfile((std::string(av[1]) + ".replace").c_str());
    if(!outfile)
    {
        std::cout << "*************ERROR***************\n"
                  << "Could not create the output file." << std::endl;
        return 1;
    }

    while(std::getline(infile, line))
    {
        std::string replacedLine = replaceAll(line, s1, s2);
        outfile << replacedLine << std::endl;
    }


    infile.close();
    outfile.close();
    return 0;
}