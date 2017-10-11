#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// NAME: Jack Weissenberger
// LAB: CSC 112 Lab #2 Part 0

// Determine al the primes in a given range, print them out, along with the Max prime
// the average distance between the primes, the number of twin prime pairs
// Then if the digit in the unit's position of primes[i]> digit in the unit position of
// primes[i+1], then swap the digit in the units position in the two locations
// Then print out the following: If the digit in the unit's position in primes[i] > digit in the unit's position in
// primes[i+1], then swap the digits in the units position in these two locations. E.g., assume primes[i]=19 and
// primes[i+1]=23. The swap would produce:primes[i]=13 and primes[i+1]=29

int main() {
    const int kMaxN = 5000;
    vector<bool> isPrime;
    unsigned int kN, i, j, k;
    vector<int> primes;
    int numPrimes = 0;
    int maxPrime = 2;
    vector<int> pVector;
    int primeDiff = 0;
    int totalDiff = 0;
    int primeDiffAvg = 0;
    int numTwinPrimeParis = 0;
    int temp = 0;


    cout << "Enter Kn: " << endl;
    cin >> kN;

    for (i=0; i<=kN; ++i) {
        isPrime.push_back(true);
    }

    //Sieve of Eratosthenes algorithm
    for (i = 2; i <= sqrt(kN); ++i){
        if (isPrime.at(i)){
            k=0;
            for (j = i*i; j<= kN; j = i*i +k*i){
                isPrime.at(j) = false;
                k +=1;
            }
        }
    }


    //enters the prime numbers into the 'primes' vector
    for (i=2; i<kN; ++i){
        if (isPrime.at(i)){
            primes.push_back(i);
        }

    }

    // outputs the prime values, counts them in numPrimes and finds the maxPrime
    for (i=0; i<primes.size(); ++i){
        cout << primes.at(i) << " ";

        numPrimes += 1;

    }


    maxPrime = primes.at(primes.size()-1);

    cout << endl << "# Primes: " << numPrimes << ", Max_Prime: " << maxPrime << endl;

    //calculates the difference between the prime values, and checks if it is a twin prime
    for (i = 1; i<primes.size(); ++i){
        primeDiff = primes.at(i) - primes.at(i-1);

        if (primeDiff == 2){
            numTwinPrimeParis +=1;
        }

        totalDiff +=primeDiff;
    }

    //calculates the average difference of the primes
    // **note** to calculate the actual average I would have to convert this type to a
    // double but in the assignment he does not so I left this as an int
    primeDiffAvg = totalDiff/numPrimes;

    cout << "Avg prime diff: " << primeDiffAvg << endl;
    cout << "#Twin prime pairs: " << numTwinPrimeParis << endl;

    //swap the unit position of the two numbers if the one above has a lower value in the digit position
    for(i = 0; i < primes.size() -1; ++i){
        if((primes.at(i) % 10) > primes.at(i +1) % 10){
            temp = primes.at(i+1) % 10;
            primes.at(i+1) = primes.at(i+1) - (primes.at(i+1) % 10) +(primes.at(i) % 10);
            primes.at(i) = primes.at(i) - (primes.at(i)%10) + temp;
        }
    }

    for (i=0; i<primes.size(); ++i){
        cout << primes.at(i) << " ";

    }


    return 0;
}
