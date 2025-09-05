#include "computer.h"
#include "Lap_Top.h"
#include <sstream>
#include <iostream>

using std::ostringstream;
using std::ostream;
using std::string;  

string Computer::get_string () const {
    ostringstream sb;
    sb << "Manufacturer: " << manufacturer << "\n"
       << "Processor: " << processor << "\n"
       << "RAM Size (GB): " << ram_size << "\n"
       << "Disk Size (GB): " << disk_size << "\n";
    return sb.str();
}

