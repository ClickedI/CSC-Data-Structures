//Copyright 2025

#include "Charge.h"

Charge::Charge() : business(""), amount(0.0) {}

Charge::Charge(std::string business, double amount) : business(business), amount(amount) {}

Charge::Charge(const Charge &orig) : business(orig.business), amount(orig.amount) {}

Charge::~Charge() {}

double Charge::GetAmount() const {
    return amount;
}

string Charge::GetBusiness() const {
    return business;
}
