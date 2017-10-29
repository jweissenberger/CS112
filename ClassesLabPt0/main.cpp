#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

// This is a program that introduces classes and objects that calcuates the total price of two items using the
// ItemToPurchase class

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;
    string name;
    int price;
    int quan;


    // item 1
    cout << "Item 1" << endl;

    cout << "Enter the item name:";
    getline(cin, name);
    item1.SetName(name);

    cout << endl << "Enter the item price: ";
    cin >> price;
    item1.SetPrice(price);

    cout << endl << "Enter the item quantity: ";
    cin >> quan;
    item1.SetQuantity(quan);



    //item 2
    cout << endl << endl << "Item 2" << endl;

    cout << "Enter the item name:";
    cin.ignore();
    getline(cin, name);
    item2.SetName(name);

    cout << endl << "Enter the item price: ";
    cin >> price;
    item2.SetPrice(price);

    cout << endl << "Enter the item quantity: ";
    cin >> quan;
    item2.SetQuantity(quan);

    //Total cost calculation
    cout << endl << endl << "TOTAL COST" << endl;
    cout<< item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" <<item1.GetQuantity() * item1.GetPrice() << endl;
    cout<< item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" <<item2.GetQuantity() * item2.GetPrice() << endl;

    cout << "Total: " << item1.GetQuantity() * item1.GetPrice() + item2.GetQuantity() * item2.GetPrice();

    return 0;
}
