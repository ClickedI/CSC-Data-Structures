/*
 * ProcessOrders.h
 *
 *  Created on: Mar 17, 2013
 *      Author: hloi	œ
 */

#ifndef PROCESSORDERS_H_
#define PROCESSORDERS_H_

#include <stack>
#include <ostream>
#include <queue>
#include "Inventory.h"
#include "Order.h"

class ProcessOrders
{
public:

	/** Process new Shipment
	 @param q Quantity of widgets in shipment
	 @param c Cost of the widgets in shipment
	 Also process any un-filled orders in the orders_to_be_filled stack
	 @return total amount that were processed from orders_to_be_filled stack
	 */
	double process_shipment(int q, double c)
	{

	}
 // process shipments arrive; return total shipment
	/** Process new Order
	 @param q Quantity of widgets in shipment
	 @return total amount that were processed from orders_to_be_filled stack
	 */
	double process_order(int q)
	{
		std::cout << "Process Order " << q << std::endl;
		while (q > 0 && !Inventory_on_hand.empty())
		{
			auto top = Inventory_on_hand.top();
			auto quantity = top.get_quantity();
			auto cost = top.get_cost();
			auto price = cost*1.5;
			if (top.get_quantity() <= q )
			{
				std::cout << "Processed " << quantity << "for order, obtained from most recent shipment;" << std::endl;
				std::cout << "no more items in shipment, removed from stack." << std::endl;
				std::cout << "Cost: " << cost << "Selling Price" << price << std::endl;
				std::cout << "total order: " << quantity*price << std::endl;
				q-=quantity;
				Inventory_on_hand.pop();
			}
			else if (top.get_quantity() > q)
			{
				std::cout << "Processed " << quantity << "for order, obtained from most recent shipment;" << std::endl;
				std::cout << "Cost: " << cost << "Selling Price" << price << std::endl;
				std::cout << "total order: " << quantity*price << std::endl;
				q-=quantity;
				top.set_quantity(q);
			}


		}
		std::cout << std::endl;

	}
	// process orders

//	void do_shipment_arrived();					// get inputs from user when the shipments arrive
//	void do_order_arrived();					// get inputs from user when the orders arrive

private:

	std::stack<Inventory> Inventory_on_hand;	// keep track of inventory on hand
	std::queue<Order> orders_to_be_filled;		// keep track of orders

};

#endif /* PROCESSORDERS_H_ */
