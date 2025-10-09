
#include "Binary_Search_Tree.h"
#include "Customers.h"
#include <iostream>
#include <list>

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(double limit) {
    return count_big_limits(*this, limit);
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit() {
    return any_over_limit(*this);
}

template<typename Item_Type>
Item_Type* Customers<Item_Type>::increase_limit(string card_number, double limit_add) {
    auto customer = this->find(card_number);
    if (customer) {
        customer->SetLimit(customer->GetLimit() + limit_add);
    }
    return customer;
}

template<typename Item_Type>
const Item_Type* Customers<Item_Type>::find(const string& target) const {
    return Binary_Search_Tree<Item_Type>::find(target);
}

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(const Binary_Tree<Item_Type>& the_tree, double limit) {
    if (the_tree.empty()) return 0;
    int count = check_limit(the_tree.get_data(), limit);
    count += count_big_limits(the_tree.left(), limit);
    count += count_big_limits(the_tree.right(), limit);
    return count;
}

template<typename Item_Type>
int Customers<Item_Type>::check_limit(Customer data, double limit) {
    return (data.GetLimit() > limit) ? 1 : 0;
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit(const Binary_Tree<Item_Type>& the_tree) {
    if (the_tree.empty()) return false;
    if (sum_charges(the_tree.get_data().GetCharges().begin(), the_tree.get_data().GetCharges().end()) > the_tree.get_data().GetLimit())
        return true;
    return any_over_limit(the_tree.left()) || any_over_limit(the_tree.right());
}

template<typename Item_Type>
double Customers<Item_Type>::sum_charges(list<Charge>::iterator begin, list<Charge>::iterator end) {
    double sum = 0.0;
    for (auto it = begin; it != end; ++it) {
        sum += it->GetAmount();
    }
    return sum;
}








