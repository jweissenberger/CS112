// Jack Weissenberger, pointers lab

#include <iostream>
using namespace std;

void printVariableInformation();

void printVariableInformation(){
    static double* doubValptr, doubVal = 23.7;
    static int* intValptr, intVal = 5;
    static bool* boolValptr, boolVal = false;

    cout << "Double value: " << doubVal << ", Double value pointer: " << doubValptr << endl;
    cout << "Boolean value: " << boolVal << ", Boolean value pointer: " << boolValptr << endl;
    cout << "Integer value: " << intVal << ", Integer value pointer: " << intValptr << endl;

    cout << sizeof(doubVal) << endl;
    cout << sizeof(boolVal) << endl;
    cout << sizeof(intVal) << endl;


}

void printArrayInformation();

void printArrayInformation() {
    int arrayOfIntegers[10];
    int j = 20;
    for (int i = 0; i < 10; ++i) {
        arrayOfIntegers[i] = j;
        j += 2;

    }

    cout << arrayOfIntegers        << endl;

    cout << &(arrayOfIntegers[0])  << endl;
    cout << arrayOfIntegers + 0    << endl;
    cout << arrayOfIntegers[0]     << endl;
    cout << *(arrayOfIntegers + 0) << endl;

    cout << &(arrayOfIntegers[1])  << endl;
    cout << arrayOfIntegers + 1    << endl;
    cout << arrayOfIntegers[1]     << endl;
    cout << *(arrayOfIntegers + 1) << endl;
    cout << (*arrayOfIntegers) + 1 << endl;

    cout << &(arrayOfIntegers[10]) << endl;
    cout << arrayOfIntegers + 10   << endl;
    //cout << arrayOfIntegers[10]    << endl;

}

void foo1(int xval){
    int x = xval;
    cout << x << endl << &x << endl;
}

void foo2(int dummy){
    int y = dummy;
    cout << y << endl << &y << endl;

}

void PrintArray2(){
    int array1[10];
    int* array2 = new int[10];
    cout << array1 << endl; // line 3
    cout << array2 << endl; // line 4
    delete [] array2;

}


int main() {

    //printVariableInformation();
    //printArrayInformation();
    //foo1(10);
    //foo2(10);
    PrintArray2();

    return 0;
}
