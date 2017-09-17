#include <iostream>
using  namespace std;

#define MIN_VAL   1
#define MAX_VAL 300

int main() {

    int N = 20;
    unsigned int rSeed;
    int arrMax = -2;
    int secondLargest = -3;
    int arrA[N];
    int i = 0;

    //enter and set the seed
    cout << "Enter Seed: " << endl;
    cin  >> rSeed;

    srand(rSeed);

   //get the random values, put them into the array, find the largest and the second largest
   for (i = 0; i < N; ++i){
      arrA[i]= (rand() % MAX_VAL) +MIN_VAL;
      cout << arrA[i] << " ";
      if (arrA[i] > arrMax){
         arrMax = arrA[i];
         }
      if ((arrMax > arrA[i]) && (arrA[i] > secondLargest)){
         secondLargest = arrA[i];
         }

      //if all of the random numbers are the same, secondLarges is set to -1
      else{
         secondLargest = -1;
         }
      }

    cout << endl << "max: " << arrMax << endl;
    cout << "2nd: " << secondLargest << endl;

    return 0;
}
