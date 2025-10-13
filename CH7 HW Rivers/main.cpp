#include <iostream>
#include "Rivers.h"
using namespace std;

//int main() {
//    list<Rivers> rs1;
//    Rivers r1("Missouri",  6.5,  6.5, rs1);
//    list<Rivers> rs2;
//    Rivers r2("Jefferson", 7.0, 6.2, rs2);
//    r1.make_river(r2);
//    list<Rivers> rs3;
//    Rivers r3("Beaverhead",  6.2, 6.7, rs3);
//    r2.make_river(r3);
//
//    list<Rivers> rs4;
//    Rivers r4("Bighole",  7.0, 7.5, rs4);
//    r2.make_river(r4);
//
//    list<Rivers> rs5;
//    Rivers r5("Sun", 7.5, 7.0, rs5);
//    r1.make_river(r5);
//
//    list<Rivers> rs6;
//    Rivers r6("Yellowstone", 7.0, 7.5, rs6);
//    r1.make_river(r6);
//
//    list<Rivers> rs7;
//    Rivers r7("Gardner", 7.1, 6.9, rs7);
//    r6.make_river(r7);
//
//    list<Rivers> rs8;
//    Rivers r8("Shields", 7.9, 8.0, rs8);
//    r6.make_river(r8);
//
//    list<Rivers> rs9;
//    Rivers r9("Boulder", 8.5, 5.5, rs9);
//    r6.make_river(r9);
//
//    list<Rivers> rs10;
//    Rivers r10("Madison", 8.0, 8.0, rs10);
//    r1.make_river(r10);
//
//    list<Rivers> rs11;
//    Rivers r11("Gallatin", 6.8, 7.2, rs11);
//    r1.make_river(r11);
//
//    cout << r2.list_acidic_rivers() << endl;
//    return 0;
//}


int main() {
    list<Rivers*> rs1;
    Rivers* r1 = new Rivers("Missouri",  6.5,  6.5, rs1);
    list<Rivers*> rs2;
    Rivers* r2 = new Rivers("Jefferson", 7.0, 6.2, rs2);
    r1->make_river(r2);
    list<Rivers*> rs3;
    Rivers* r3 = new Rivers("Beaverhead",  6.2, 6.7, rs3);
    r2->make_river(r3);

    list<Rivers*> rs4;
    Rivers* r4 = new Rivers("Bighole",  7.0, 7.5, rs4);
    r2->make_river(r4);

    list<Rivers*> rs5;
    Rivers* r5 = new Rivers("Sun", 7.5, 7.0, rs5);
    r1->make_river(r5);

    list<Rivers*> rs6;
    Rivers* r6 = new Rivers("Yellowstone", 7.0, 7.5, rs6);
    r1->make_river(r6);

    list<Rivers*> rs7;
    Rivers* r7 = new Rivers("Gardner", 7.1, 6.9, rs7);
    r6->make_river(r7);

    list<Rivers*> rs8;
    Rivers* r8 = new Rivers("Shields", 7.9, 8.0, rs8);
    r6->make_river(r8);

    list<Rivers*> rs9;
    Rivers* r9 = new Rivers("Boulder", 8.5, 5.5, rs9);
    r6->make_river(r9);

    list<Rivers*> rs10;
    Rivers* r10 = new Rivers("Madison", 8.0, 8.0, rs10);
    r1->make_river(r10);

    list<Rivers*> rs11;
    Rivers* r11 = new Rivers("Gallatin", 6.8, 7.2, rs11);
    r1->make_river(r11);

//    cout << r2->list_acidic_rivers() << endl;
    Rivers::setAcidLevel(6.5);
    cout << r1->list_acidic_rivers() << endl;

//    cout << r5->unhealthy() << endl;

//    r1->print();
//    Rivers* r12 = r1->lower_all_ph();
//    r12->print();


//    Rivers* r13 = r1->find_subsystem("Yellowstone");
//    r13->print();

//    Rivers* r13 = r1->find_subsystem("Assabet");
//    r13->print();
//    r1->print();
    return 0;
}
