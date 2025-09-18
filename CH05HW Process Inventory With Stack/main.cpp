#include <iostream>
#include "ProcessOrders.h"
#include "Order.h"

int main() {
    ProcessOrders po;
    double amount = po.process_order(2);
    // shipment arrives.  Quantity of 5 items, cost $5 each
    // inventory 5
    amount = po.process_shipment(5,5);

    // inventory 2 -> 7
    amount = po.process_shipment(2,10);

    amount = po.process_shipment(2,7);

    amount = po.process_shipment(1,15);

    amount = po.process_order(10);

    return 0;
}
