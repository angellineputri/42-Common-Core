#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    std::cout << MAGENTA << std::endl << "/// original, serialized, and deserialized address/values /// " << RESET << std::endl;
    Data    original;
    original.name = "kitty";
    original.fav_number = 42;
    std::cout << "original pointer: " << &original << std::endl;

    uintptr_t   raw = Serializer::serialize(&original);
    std::cout << "serialized uintptr_t: " << raw << std::endl;

    Data*   deserialized = Serializer::deserialize(raw);
    std::cout << "deserialized pointer: " << deserialized << std::endl;

    std::cout << MAGENTA << std::endl << "/// comparison of the data /// " << RESET << std::endl;
    std::cout << "original data: " << std::endl
        << "name: " << original.name << std::endl
        << "fav number: " << original.fav_number << std::endl
        << "address: " << &original << std::endl << std::endl;

    std::cout << "deserialized data: " << std::endl
        << "name: " << deserialized->name << std::endl
        << "fav number: " << deserialized->fav_number << std::endl
        << "address: " << deserialized << std::endl;

    return (0);
}

