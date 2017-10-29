//
// Created by weisja15 on 10/29/17.
//

#include "ItemToPurchase.h"

void ItemToPurchase::SetName(string name){
    itemName = name;
    return;
}

string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
    return;
}

int ItemToPurchase ::GetPrice() {
    return itemPrice;
}

void ItemToPurchase ::SetQuantity(int quan) {
    itemQuantity = quan;
    return;
}

int ItemToPurchase ::GetQuantity() {
    return itemQuantity;
}
