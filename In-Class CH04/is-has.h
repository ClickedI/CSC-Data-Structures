#ifndef IN_CLASS_H
#define IN_CLASS_H
#include <string>


class Computer {
    private:
        std::string manufacturer;
        std::string processor;
        int ram_size; // in GB
        int disk_size; // in GB
    public :
        Computer(std::string man, std::string proc, int ram, int disk) 
            : manufacturer(man), processor(proc), ram_size(ram), disk_size(disk) {}

        int get_ram_size() const {
            return ram_size;
        }

        int get_disk_size() const {
            return disk_size;
        }
        std::string get_string () const;
};

#endif // IN_CLASS_H