#include "Serializer.hpp"
#include "Data.hpp"

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.i = 42;
    data.str = (char *)"42 Network";
    data.c = 'Z';

    uintptr_t raw = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << &data << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    std::cout << "Original values:\n";
    std::cout << " i: " << data.i << "\n str: " << data.str << "\n c: " << data.c << std::endl;

    std::cout << "Deserialized values:\n";
    std::cout << " i: " << deserialized->i << "\n str: " << deserialized->str << "\n c: " << deserialized->c << std::endl;

    return 0;
}
