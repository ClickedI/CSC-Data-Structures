#include "Lap_Top.h"
#include <sstream>
#include <iostream>

using std::ostringstream;
using std::ostream;
using std::string;

string Lap_Top::get_string () const {
    ostringstream sb;
    sb  << Computer::get_string()
        << "Screen Size: " << screen_size << "\n"
        << "Weight: " << weight << "\n";
    return sb.str();
}

const char* Lap_Top::DEFAULT_LT_MAN = "My Brand";
