//Copyright 2025

#ifndef CHARGE_H
#define CHARGE_H
#include <string>

using std::string;

class Charge {
public:
    Charge();  // default constructor
    Charge(string business, double amount);
    Charge(const Charge& orig);
    virtual ~Charge();
    double GetAmount() const;
    string GetBusiness() const;
private:
    string business;    // business name
    double amount;      // charge amount
};

#endif /* CHARGE_H */

