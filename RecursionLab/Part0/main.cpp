#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Recur_Fun.h"

int main() {

    Recur_Fun recur;

    //to run each of the recursive functions you need to create a switch statement

    string str = "boc";

    cout<< recur.str_rev(str);

    vector<int> People(3);
    People.at(0) = 1;
    People.at(1) = 2;
    People.at(2) = 3;
    int maxV = 0;
    recur.list_max(People, 0, maxV);
    cout<< endl << maxV;

//    cout << endl << recur.palin(str);
    //cout << endl << recur.find_sub("Jack", "ck");

    return 0;
}