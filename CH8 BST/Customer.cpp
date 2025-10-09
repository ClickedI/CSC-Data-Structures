#include "Customer.h"
#include "Contact.h"
#include "Charge.h"


Customer::Customer() : card_number(""),  contact(), limit(0.0), charges() {}

Customer::Customer(std::string ccn, Contact &contact, double limit, list <Charge> charges) : card_number(ccn), contact(contact), limit(limit), charges(charges) {}

Customer::Customer(const Customer &orig) : card_number(orig.card_number), contact(orig.contact), limit(orig.limit), charges(orig.charges) {}

Customer::~Customer() {}

void Customer::SetCharges(list <Charge> charges) {
    this->charges = charges;
}

void Customer::SetCard_number(std::string card_number) {
    this->card_number = card_number;
}

void Customer::SetContact(Contact &contact) {
    this->contact = contact;
}

void Customer::SetLimit(double limit) {
    this->limit = limit;
}

string Customer::GetCard_number() const {
    return card_number;
}

list<Charge> Customer::GetCharges() const {
    return charges;
}

double Customer::GetLimit() const {
    return limit;
}

Contact Customer::GetContact() const {
    return contact;
}

bool Customer::operator<(const Customer &other) const {
    return this->card_number < other.card_number;
}

void Customer::push_back(Charge c) {
    charges.push_back(c);
}











