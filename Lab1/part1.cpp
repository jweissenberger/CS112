#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// NAME: Professor Sai Mukkavilli
// LAB: CSC 112 Lab #1 - Part 0

// Determine primes; calculate # primes, %primes, max prime, avg distance between primes.
// Examine all numbers in the closed interval, [0, kN], where kN>= 2.

int main() {
    const int kMaxN = 5000;
    bool isPrime[kMaxN+1];
    int kN, i, j, k;
    int primes[kMaxN+1];
    int numPrimes = 0;
    int maxPrime = 2;
    vector<int> pVector;
    int primeDiff = 0;
    int totalDiff = 0;
    int primeDiffAvg = 0;
    int numTwinPrimeParis = 0;


    cout << "Enter Kn: " << endl;
    cin >> kN;

    for (i=0; i<=kN; ++i) {
        isPrime[i] = true;
        primes[i] = 0;
    }

    //Sieve of Eratosthenes algorithm
    for (i = 2; i <= sqrt(kN); ++i){
        if (isPrime[i]){
            k=0;
            for (j = i*i; j<= kN; j = i*i +k*i){
                isPrime[j] = false;
                k +=1;
            }
        }
    }

    //enters the prime numbers into the 'primes' array
    for (i=2; i<kN; ++i){
        if (isPrime[i]){
            primes[i]= i;
        }

    }

    // outputs the prime values, counts them in numPrimes and finds the maxPrime
    for (i=0; i<kN; ++i){
        if (primes[i] != 0) {
            cout << primes[i] << " ";

            //creates a vector of only the prime values
            pVector.push_back(primes[i]);

            numPrimes += 1;
            if (primes[i] > maxPrime){
                maxPrime = primes[i];
            }

        }

    }

    cout << endl << "# Primes: " << numPrimes << ", Max_Prime: " << maxPrime << endl;

    //calculates the difference between the prime values, and checks if it is a twin prime
    for (i = 1; i<pVector.size(); ++i){
        primeDiff = pVector.at(i) - pVector.at(i-1);

        if (primeDiff == 2){
            numTwinPrimeParis +=1;
        }

        totalDiff +=primeDiff;
    }

    //calculates the average difference of the primes
    // **note** to calculate the actual difference I would have to convert this type to a
    // double but in the assignment he does not so I left this as an int
    primeDiffAvg = totalDiff/numPrimes;

    cout << "Avg prime diff: " << primeDiffAvg << endl;
    cout << "#Twin prime pairs: " << numTwinPrimeParis << endl;


    //pt. 3 swaps primes if unit digit is larger than one above it
    auto temp = 0;
    for (i = 0; i<(pVector.size()-1); ++i){ ;
        if ((pVector.at(i)%10) > (pVector.at(i+1)%10)){
            temp = pVector.at(i);
            pVector.at(i) = pVector.at(i+1);
            pVector.at(i+1) = temp;
        }
    }

    //pt 4. swaps the largest and second largest values
    int maxLoc = 0;
    int secondMaxPrime;
    int secondMaxLoc = 0;
    for (i = 0; i<pVector.size(); ++i){
        if (pVector.at(i) == maxPrime){
            maxLoc = i;
        }
        if (pVector.at(i) < maxPrime && pVector.at(i) > secondMaxPrime){
            secondMaxPrime = pVector.at(i);
            secondMaxLoc = i;
        }
        cout << pVector.at(i) << " ";
    }

    temp = pVector.at(maxLoc);
    pVector.at(maxLoc) = pVector.at(secondMaxLoc);
    pVector.at(secondMaxLoc) = temp;
    cout << endl;

    for (i = 0; i<pVector.size(); ++i){
        cout << pVector.at(i) << " ";
    }
    return 0;
}
