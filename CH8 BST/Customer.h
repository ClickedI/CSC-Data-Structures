/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customer.h
 * Author: hloi
 *
 * Created on November 24, 2018, 2:13 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Charge.h"
#include "Contact.h"

class Customer {
public:
    Customer();
    // non-default constructor
    Customer(string ccn, Contact& contact, double limit, list<Charge> charges);
    //copy constructor
    Customer(const Customer& orig);
    virtual ~Customer();
    void SetCharges(list<Charge> charges);
    list<Charge> GetCharges() const;
    void SetLimit(double limit);
    double GetLimit() const;
    void SetContact(Contact& contact);
    Contact GetContact() const;
    void SetCard_number(string card_number);
    string GetCard_number() const;
    
    bool operator<(const Customer& other) const;
    
    void push_back(Charge c);

    friend std::ostream& operator<<(std::ostream& out,
                           const Customer& customer){
        out << "Card Number: " << customer.GetCard_number() << "\n"
            << customer.GetContact() << "\n"
            << "Limit: " << customer.GetLimit();
        // You can optionally print charges here too
        return out;
    }

    
private:
    string card_number;
    Contact contact;
    double limit;
    list<Charge> charges;
};

#endif /* CUSTOMER_H */

