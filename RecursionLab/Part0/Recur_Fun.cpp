//
// Created by weisja15 on 11/6/17.
//

#include "Recur_Fun.h"
#include <cstring>
#include <string>
using namespace std;

// Function that reverses a string
string Recur_Fun::str_rev(string inStr) {
    string temp;

    //base case
    if (inStr.length() == 1){
        return inStr;
    }
    else{
        return str_rev(inStr.substr(1, inStr.length())) + inStr.at(0);
    }

}

//starts with the last value of the vector and then iterates down
int Recur_Fun::list_max(vector<int> inList, int i, int & maxVal) {

    if (i != inList.size()){
        if (inList.at(i) > maxVal){
            maxVal = inList.at(i);
        }
        list_max(inList, ++i, maxVal);
    }

        //base case
    else{
        return 0;
    }

    //recursive case, iterates down through the vector

}


//if it outputs a value greater than 0 then it is true
// checks to see if the user input is a pallindrome, checks to see that the outer most are the same and then works its
// way in, checking they are all the same
bool Recur_Fun::palin(string usrIn) {
    int len = usrIn.length();

    //base case to check if the word has gotten to the middle, in which case it is a palindrome
    if (len <= 1){
        return true;
    }

        // if the values do not match, then it is not
    else if (usrIn.at(0) != usrIn.at(len-1)){
        return false;
    }

        // recursive step, if they do match, the rest of the values need to be checked
    else if (usrIn.at(0) == usrIn.at(len-1)){
        palin(usrIn.substr(1,(len-2)));
    }
}

//outputs a non zero value if the substring exists, outputs 0 if it does not exist
int Recur_Fun::find_sub(string big, string small, int &i) {
    int bigLen = big.size();
    int smallLen = small.size();

    if (small == big.substr(i, smallLen)){
        return 1;
    }

    if (i < bigLen) {
        find_sub(big, small, ++i);
    }

    if (i == bigLen){
        return 0;
    }

}