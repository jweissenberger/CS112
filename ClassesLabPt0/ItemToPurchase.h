//
// Created by weisja15 on 10/29/17.
//

#ifndef CLASSESOBJECTLABPT0_ITEMTOPURCHASE_H
#define CLASSESOBJECTLABPT0_ITEMTOPURCHASE_H
#include <string>
using namespace std;

class ItemToPurchase {


public:
    void SetName(string name);
    string GetName();
    void SetPrice( int price);
    int GetPrice();
    void SetQuantity( int quan);
    int GetQuantity();

private:
    string itemName = "none";
    int itemPrice = 0;
    int itemQuantity = 0;
};


#endif //CLASSESOBJECTLABPT0_ITEMTOPURCHASE_H
