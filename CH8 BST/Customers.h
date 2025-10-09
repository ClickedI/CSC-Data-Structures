/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Customers.h
 * Author: hloi
 *
 * Created on November 24, 2018, 9:05 PM
 */

#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "Binary_Search_Tree.h"
#include "Customer.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename Item_Type>
class Customers : public Binary_Search_Tree<Item_Type> {
public:

    Customers() : Binary_Search_Tree<Item_Type>() {
    }
    Customers(const Customers& orig) {}
    virtual ~Customers() {}
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(double limit);

    bool any_over_limit();

    // increase-limit: BST Natural Number -> BST
    // consumes a BST, a credit card number, and an amount of money. Function finds that
    // card number in the BST and changes that customer's credit limit, adding the amount of money
    // given to the limit. Function returns BST identical except for limit change
    Item_Type* increase_limit(string card_number, double limit_add);

    const Item_Type* find(const string& target) const;

private:
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(const Binary_Tree<Item_Type>& the_tree, double limit);
    // check-limit: Number -> Natural
    // takes in a customer's credit limit and a given credit limit, returns 1 if the customers'
    // credit limit is higher than the given limit, 0 otherwise.
    int check_limit(Customer data, double limit);

    // any-over-limit?: BST -> Boolean
    // consumes a binary search tree and produces true if any customer in that tree has exceeded
    // their credit limit with their total purchases (charges)
    bool any_over_limit(const Binary_Tree<Item_Type>& the_tree);
    // sum-charges: ListOfCharge -> Number
    // consumes a ListOfCharge, produces the sum cost of those charges as a Number
    double sum_charges(list<Charge>::iterator begin,
            list<Charge>::iterator end);



};



#endif /* CUSTOMERS_H */

