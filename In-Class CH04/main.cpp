
#include <iostream>
#include "computer.h"
#include "lap_top.h"

int main()
{
    Computer comp1("Dell", "Intel i7", 16, 512);
    Computer comp2("HP", "AMD Ryzen 5", 8, 256);
    Lap_Top laptop("Apple", "M1", 16, 512, 13.3, 3.0);


    std::cout << "Computer 1 Details:\n" << comp1.get_string();
    std::cout << "Computer 2 Details:\n" << comp2.get_string();
    std::cout << "Laptop Details:\n" << laptop.get_string() << laptop.get_screen_size() << "\n" << laptop.get_weight() << "\n";

    return 0;
}
