//copyright 2025

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

private:

    int count_big_limits_helper(BTNode<Item_Type>* node, double limit);

    bool any_over_limit_helper(BTNode<Item_Type>* node);


    double sum_charges(const list<Charge>& charges);
};

// Implementation of member functions
template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(double limit) {
    return count_big_limits_helper(this->root, limit);
}

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits_helper(BTNode<Item_Type>* node, double limit) {
    if (node == NULL) {
        return 0;
    }

    int count = 0;

    // Check if current node's limit is greater than the given limit
    if (node->data.GetLimit() > limit) {
        count = 1;
    }

    //check left and right subtrees
    count += count_big_limits_helper(node->left, limit);
    count += count_big_limits_helper(node->right, limit);

    return count;
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit() {
    return any_over_limit_helper(this->root);
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit_helper(BTNode<Item_Type>* node) {
    if (node == NULL) {
        return false;
    }

    // Calculate sum of charges for current customer
    double total_charges = sum_charges(node->data.GetCharges());

    // Check if this customer is over limit
    if (total_charges > node->data.GetLimit()) {
        return true;
    }

    // Check left and right subtrees
    return any_over_limit_helper(node->left) || any_over_limit_helper(node->right);
}

template<typename Item_Type>
double Customers<Item_Type>::sum_charges(const list<Charge>& charges) {
    double sum = 0.0;
    for (typename list<Charge>::const_iterator it = charges.begin(); it != charges.end(); ++it) {
        sum += it->GetAmount();
    }
    return sum;
}

template<typename Item_Type>
Item_Type* Customers<Item_Type>::increase_limit(string card_number, double limit_add) {
    Contact temp_contact("", "", "");
    list<Charge> temp_charges;
    Item_Type temp(card_number, temp_contact, 0.0, temp_charges);

    // Find the customer in the tree
    const Item_Type* found = Binary_Search_Tree<Item_Type>::find(temp);

    if (found) {
        Item_Type* customer = const_cast<Item_Type*>(found);
        customer->SetLimit(customer->GetLimit() + limit_add);
        return customer;
    }
    return NULL;
}

#endif /* CUSTOMERS_H */
