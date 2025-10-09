/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Charge.h
 * Author: hloi
 *
 * Created on November 24, 2018, 12:38 AM
 */

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

