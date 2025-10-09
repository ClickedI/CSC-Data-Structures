//Copyright 2025

#ifndef HW_CSC211BINARYTREE_1_LISTOFCHARGE_H
#define HW_CSC211BINARYTREE_1_LISTOFCHARGE_H

#include <list>
#include "Charge.h"

using std::list;


class ListOfCharge {
public:
    ListOfCharge();
    virtual ~ListOfCharge();
    void addCharge(Charge charge);
    list<Charge> getCharges() const;

    private:
    list<Charge> charges;
};


#endif //HW_CSC211BINARYTREE_1_LISTOFCHARGE_H
