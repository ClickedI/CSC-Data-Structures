//Copyright 2025

#include "ListOfCharge.h"

ListOfCharge::ListOfCharge() {}

ListOfCharge::~ListOfCharge() {}

void ListOfCharge::addCharge(Charge charge) {
    charges.push_back(charge);
}

list<Charge> ListOfCharge::getCharges() const {
    return charges;
}
