#include "is-has.h"
#include <sstream>

using std::ostringstream;
using std::string;  

string Computer::get_string () const {
    ostringstream sb;
    sb << "Manufacturer: " << manufacturer << "\n"
       << "Processor: " << processor << "\n"
       << "RAM Size (GB): " << ram_size << "\n"
       << "Disk Size (GB): " << disk_size << "\n";
    return sb.str();
}