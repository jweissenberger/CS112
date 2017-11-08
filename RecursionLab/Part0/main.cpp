#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Recur_Fun.h"

int main() {

    Recur_Fun recur;
    char inCmd;
    string str1;
    int vecInput;
    vector<int> maxValVec;

    cout << "Enter a command: " << endl;
    cin >> inCmd;

    while (inCmd != 'E'){
        switch (inCmd){
            case 'R':
                cout << "Input a string to be reversed: ";
                cin >> str1;
                cout << endl << recur.str_rev(str1);
                break;

            case 'M':
                cout << "Enter values to be inputted into the vector: ";
                cin >> vecInput;
                while (vecInput >= 0){
                    maxValVec.push_back(vecInput);
                    cin >> vecInput;
                }
                int maxV = 0;
                recur.list_max(maxValVec, 0, maxV);
                cout<< endl << "Maximum value is: " << maxV;
                break;
                
        }

    }

    //to run each of the recursive functions you need to create a switch statement

    string str = "whywontthisworkthen";
    string str2 = "ywontth";

    cout<< recur.str_rev(str);


    cout << endl << str.substr(0, str2.length());
    int i = 0;
    cout << endl << recur.find_sub(str, str2, i) << endl;

    return 0;
}