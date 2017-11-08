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

    //base case, once the string is reduced to one letter
    if (inStr.length() == 1){
        return inStr;
    }

    //recursive case, letters are reversed one by one until the input string is reduced to 1
    else{
        return str_rev(inStr.substr(1, inStr.length())) + inStr.at(0);
    }

}

// recursively checks each value in a vector so find which value is the largest
//starts with the last value of the vector and then iterates down
int Recur_Fun::list_max(vector<int> inList, int i, int & maxVal) {

    // recursive case, if the value of the vector at i is larger than the previous max value
    // it is replaced and then then the function is called again to check the next value
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

}



// checks to see if the user input is a palindrome, checks to see that the outer most are the same and then works its
// way in, checking they are all the same
//if it outputs a value greater than 0 then it is true, 0 if it is not true
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

// checks to each substring of the larger string of the same length of the smaller string to see if it is
// the same as the substring
//outputs a non zero value if the substring exists, outputs 0 if it does not exist
int Recur_Fun::find_sub(string big, string small, int &i) {
    int bigLen = big.size();
    int smallLen = small.size();

    // the substring is found in the string
    if (small == big.substr(i, smallLen)){
        return 1;
    }

    //recursive case
    if (i <= (bigLen-1)) {
        find_sub(big, small, ++i);
    }

    // if the string as been iterated through and, there has not been a match, output 0
    if (i == bigLen){
        return 0;
    }

}