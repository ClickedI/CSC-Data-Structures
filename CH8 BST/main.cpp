//
// Created by apees on 6/10/2024.
//
#include <iostream>
#include "Contact.h"
#include "Charge.h"
#include "ListOfCharge.h"

int main() {

    Contact contact1("0001", "John Doe", "123 Main St", "john.doe@example.com");
    Contact contact2("0002", "Jane Smith", "456 Elm St", "jane.smith@example.com");
    Contact contact3("0003", "Alice Johnson", "789 Maple St", "alice.johnson@example.com");
    Contact contact4("0004", "Bob Brown", "101 Oak St", "bob.brown@example.com");
    Contact contact5("0005", "Charlie Davis", "102 Pine St", "charlie.davis@example.com");
    Contact contact6("0006", "Diana White", "103 Cedar St", "diana.white@example.com");
    Contact contact7("0007", "Eve Black", "104 Birch St", "eve.black@example.com");
    Contact contact8("0008", "Frank Green", "105 Spruce St", "frank.green@example.com");
    Contact contact9("0009", "Grace Blue", "106 Willow St", "grace.blue@example.com");
    Contact contact10("0010", "Hank Yellow", "107 Cherry St", "hank.yellow@example.com");

    ListOfCharge list1;
    list1.addCharge(Charge("Store A", 50.25));
    list1.addCharge(Charge("Store B", 30.40));
    list1.addCharge(Charge("Store C", 70.00));

    ListOfCharge list2;
    list2.addCharge(Charge("Store D", 20.15));
    list2.addCharge(Charge("Store E", 15.30));
    list2.addCharge(Charge("Store F", 100.50));

    ListOfCharge list3;
    list3.addCharge(Charge("Store G", 25.00));
    list3.addCharge(Charge("Store H", 45.90));
    list3.addCharge(Charge("Store I", 60.75));

    ListOfCharge list4;
    list4.addCharge(Charge("Store J", 35.20));
    list4.addCharge(Charge("Store K", 80.40));
    list4.addCharge(Charge("Store L", 95.00));

    ListOfCharge list5;
    list5.addCharge(Charge("Store M", 10.50));
    list5.addCharge(Charge("Store N", 40.30));
    list5.addCharge(Charge("Store O", 75.20));

    ListOfCharge list6;
    list6.addCharge(Charge("Store P", 55.00));
    list6.addCharge(Charge("Store Q", 65.40));
    list6.addCharge(Charge("Store R", 85.75));

    ListOfCharge list7;
    list7.addCharge(Charge("Store S", 15.20));
    list7.addCharge(Charge("Store T", 35.50));
    list7.addCharge(Charge("Store U", 95.40));

    ListOfCharge list8;
    list8.addCharge(Charge("Store V", 45.10));
    list8.addCharge(Charge("Store W", 55.30));
    list8.addCharge(Charge("Store X", 65.20));

    ListOfCharge list9;
    list9.addCharge(Charge("Store Y", 75.40));
    list9.addCharge(Charge("Store Z", 85.00));
    list9.addCharge(Charge("Store AA", 95.30));

    ListOfCharge list10;
    list10.addCharge(Charge("Store AB", 105.20));
    list10.addCharge(Charge("Store AC", 115.40));
    list10.addCharge(Charge("Store AD", 125.00));

    std::cout << "Contact 1: " << contact1.getName() << ", " << contact1.getAddress() << ", " << contact1.getEmail() << std::endl;
    std::cout << "Charges for List 1:" << std::endl;
    for (const auto& charge : list1.getCharges()) {
        std::cout << "  Business: " << charge.GetBusiness() << ", Amount: " << charge.GetAmount() << std::endl;
    }

    return 0;

}



