/*
  NAME: Jack Weissenberger
  DATE: 9/15/16
  LAB: CSC 112 Lab 0
*/

#include <iostream>
using namespace std;


int main() {
    int num_ints, in_int, i;
    double total = 0.0;

    //the input must be between 20000000 and -20000000
    int max_int = -20000000;
    int min_int = 20000000;
    cout << "Enter number of integers: " << endl;
    cin >> num_ints;
    cout << num_ints << endl;

    for (i=1; i<=num_ints; ++i) {
        cout << "Enter integer # " << i << endl;
        cin >> in_int;
        cout << in_int << endl;
        if (in_int > max_int) {
            max_int = in_int;
        }

        if (in_int < min_int) {
            min_int = in_int;
        }
        total += in_int;

    }

    double mean;
    mean = total/num_ints;


    cout << "Max: " << max_int << endl;
    cout << "Min: " << min_int << endl;
    cout << "Mean: " << mean << endl;

    return 0;
}
