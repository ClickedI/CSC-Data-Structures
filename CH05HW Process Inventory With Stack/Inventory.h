#ifndef SHIPMENT_H_
#define SHIPMENT_H_

/** Class to model a shippment of Widgets */
class Inventory {
 public:
  
  /** Class constructor. Creates a new instance of Shipment.
      @param q Quantity (number) of widgets in shipment
      @param c Cost of the widgets in shipment
  */
  Inventory(int q, double c): quantity(q), cost(c) {}

  // Accessor methods
  int get_quantity() const {return quantity;}
  double get_cost() const {return cost;}
  
  //Modifier method
  void set_quantity(int q) {quantity = q;}

 private:
  int quantity;
  double cost;
};

#endif

