//Copyright 2025

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <list>
#include "Charge.h"
#include <sstream>
#include <iostream>


using std::list;
using std::string;

class Contact {
public:
    // default constructor
    Contact();
    // non default constructor
    Contact(string name, string address, string email);
    // copy constructor
    Contact(const Contact& orig);
    virtual ~Contact();        
    void setEmail(string email);
    string getEmail() const;
    void setAddress(string address);
    string getAddress() const;
    void setName(string name);
    string getName() const;
    friend std::ostream& operator<<(std::ostream& out, 
                           const Contact& contact);
private:    
    string name;
    string address;
    string email;    
};



#endif /* CONTACT_H */

