#ifndef LAPTOP_H
#define LAPTOP_H
#include "computer.h"
#include <string>

class Lap_Top : public Computer {
    private :
        double screen_size; // in inches
        double weight; // in pounds
    public :
        Lap_Top(const std::string& man, const std::string& proc, int ram, int disk, double screen, double wt)
            : Computer(man, proc, ram, disk), screen_size(screen), weight(wt) {}
        std::string get_screen_size() const {
            return std::to_string(screen_size) + " inches";
        }
        std::string get_weight() const {
            return std::to_string(weight) + " pounds";
        }
};

#endif // LAPTOP_H