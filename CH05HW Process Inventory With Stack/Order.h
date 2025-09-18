#ifndef ORDER_H_
#define ORDER_H_

/** Class to model an Order for Widgets */
class Order{
 public:
  /** Class constructor. Creates a new instance of Order.
      @param q Quantity (number) of widgets requested in Order
  */
  Order(int q): quantity(q){}

  //Accessor method
  int get_quantity() const {return quantity;}
  
  //Modifier method
  void set_quantity(int q) {quantity = q;}

 private:
  int quantity;
};

#endif
