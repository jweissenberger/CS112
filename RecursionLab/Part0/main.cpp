// Jack Weissenberger Recursion Lab part 0
// This program has a class with 4 recursive methods that are accessed by user input

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Recur_Fun.h"

int main() {

    //initialize variables
    Recur_Fun recur;
    char inCmd;
    string str1;
    int vecInput;
    vector<int> maxValVec;
    string big, small;
    int maxV = 0;
    int i = 0;

    cout << "Enter a command: " << endl;
    cin >> inCmd;

    // keep running commands as long as the user does not enter E
    while (inCmd != 'E'){
        switch (inCmd){

            //if the user inputs R, the program outputs the string backwards
            case 'R':
            case 'r':
                cout << "Input a string to be reversed: ";
                cin >> str1;
                cout << endl << recur.str_rev(str1);
                break;

            // if the user inputs M, the user inputs values into a vector and the program
            // outputs the largest value
            case 'M':
            case 'm':
                cout << "Enter values to be inputted into the vector: ";
                cin >> vecInput;

                //keeps getting input until the user inputs a negative value
                while (vecInput >= 0){
                    maxValVec.push_back(vecInput);
                    cin >> vecInput;
                }

                recur.list_max(maxValVec, 0, maxV);
                cout<< endl << "Maximum value is: " << maxV;
                break;

            // if the user inputs P, the the program checks if the inputted string is a palindrome
            case 'P':
            case 'p':
                cout << "Input a string to check if it is a palindrome:  ";
                cin >> str1;
                if (recur.palin(str1) > 0){
                    cout << endl << true << " It is a palindrome";
                } else{
                    cout << endl << false << " It is not a palindrome";
                }
                break;

            // if the user inputs F, the program checks to see if one of the uer inputtted strings
            // is a substring of the other
            case 'F':
            case 'f':
                cout << "Input the larger string: ";
                cin >> big;
                cout << endl << "Input the substring: ";
                cin >> small;

                if (recur.find_sub(big, small, i) > 0){
                    cout << endl << true << " It is a substring";
                } else{
                    cout << endl << false << " It is not a substring";
                }
                break;


            // if the user enters an unknown command, the loop is run again
            default:
                cout << "Bad Command" << endl;
                break;
        }
        cout << endl << "Command: " << endl;
        cin >> inCmd;
    }

    return 0;
}