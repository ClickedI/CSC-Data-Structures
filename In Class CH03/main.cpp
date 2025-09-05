
#include <iostream>
#include "computer.h"
#include "Lap_Top.h"

int main()
{
    Computer comp1("Dell", "Intel i7", 16, 512);
    Computer comp2("HP", "AMD Ryzen 5", 8, 256);
    Lap_Top laptop1("Apple", "M1", 16, 512, 13.3, 3.0);
    Lap_Top laptop2("M1", 16, 512, 13.3, 3.0);


    std::cout << "Computer 1 Details:\n" << comp1.get_string() << std::endl;
    std::cout << "Computer 2 Details:\n" << comp2.get_string() << std::endl;
    std::cout << "Laptop Details:\n" << laptop1.get_string() << std::endl;
    std::cout << "Laptop Details:\n" << laptop2.get_string() << std::endl;

    return 0;
}
