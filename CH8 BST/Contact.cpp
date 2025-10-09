#include "Contact.h"


Contact::Contact() : name(""), address(""), email("") {}

Contact::Contact(std::string name, std::string address, std::string email) : name(name), address(address), email(email) {}

Contact::Contact(const Contact& orig) : name(orig.name), address(orig.address), email(orig.email) {}

Contact::~Contact() {}

string Contact::getEmail() const {
    return email;
}

string Contact::getAddress() const {
    return address;
}

string Contact::getName() const {
    return name;
}

void Contact::setEmail(std::string email) {
    this->email = email;
}

void Contact::setAddress(std::string address) {
    this->address = address;
}

void Contact::setName(std::string name) {
    this->name = name;
}

std::ostream& operator<<(std::ostream&out, const Contact& contact){
    out << "Name: " << contact.name << ", Address: " << contact.address << ", Email: " << contact.email;
    return out;
}




