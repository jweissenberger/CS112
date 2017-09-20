#include <iostream>
#include <math.h>
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

    /*iLimit, maxPrime=2, primeDiffAvg=0,
            primeDiff, numTwinPtrimePairs=0;
    */


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
            numPrimes += 1;
            if (primes[i] > maxPrime){
                maxPrime = primes[i];
            }

        }

    }

    cout << endl << "# Primes: " << numPrimes << ", Max_Prime: " << maxPrime << endl;

    return 0;
}
