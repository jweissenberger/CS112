//
// Created by weisja15 on 11/4/2017.
//

#ifndef PART0_RECUR_FUN_H
#define PART0_RECUR_FUN_H
#include <string>
#include <vector>
using namespace std;

class Recur_Fun {

public:
    string str_rev(string inStr); // initialize the reverse string function
    int list_max(vector<int> inList, int i, int &maxVal);
    bool palin(string usrIn);
    int find_sub(string big, string small, int &i);
};


#endif //PART0_RECUR_FUN_H
