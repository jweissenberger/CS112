#include <iostream>
#include <fstream>
#define OUTFILE "/home/weisja15/CLionProjects/Assignment2pt2/OUTFILE.txt"
using namespace std;

// This program allows you roll two die until doubles are rolled
// The sum of the two die until doubles are rolled are calculated and so is the number of rolls it took to get doubles
// These two values are outputted to a text file and have been plotted in rollData.jpg
// The total number of rolls of dice are calculated in total rolls 
// Counts for two-die roll counts is the number of times each sum has appeared from the dice
// ex. the first number is the number of times 2 has been rolled and then three etc

int main() {
    int rSeed, numTrials, numSides, i;
    int roll1 =0;
    int roll2 = 1;
    int sum = 0;
    int numRolls = 0;
    int totalRolls = 0;

    cout << "Enter seed: " << endl;
    cin >> rSeed;

    cout << "Enter number of trials: " << endl;
    cin >> numTrials;

    cout << "Enter number of sides per die: " << endl;
    cin >> numSides;

    srand(rSeed);

    ofstream outFS;
    outFS.open(OUTFILE);

    int sumCount[2*numSides + 5] = {0};

    // for loop runs over the number of trails re-initializes each of the variables that count at each iteration
    for (i= 0; i< numTrials; ++i) {
        roll1 = 0;
        roll2 = 1;
        numRolls = 0;
        sum = 0;

        //calculates the rolls until they are equal,
        while (roll1 != roll2) {
            roll1 = (rand() % numSides) + 1;
            roll2 = (rand() % numSides) + 1;

            numRolls += 1;

            sumCount[(roll1+roll2)] += 1; //counts for two- die roll counts.

            //only calculates the sum if they are not equal
            if (roll1 != roll2) {
                sum += roll1 + roll2;
            }
        }

        //pirints to a file the number of rolls it took for the two die to have
        //the same value, and the sum of the values of the die up until they where
        //the same
        if (numRolls == 1){ // this is for the 0 case, so if they are the same on first roll
            outFS << '1' << ", " << '0' << endl;
        }
        else {
            outFS << numRolls << ", " << sum << endl;
        }
        totalRolls += numRolls;
    }
    outFS.close();

    cout << "Total rolls: " << totalRolls << endl;

    cout << "Counts for two-die roll counts." << endl;
    for (i = 2; i < numSides*2 + 1; ++i){
        cout << sumCount[i] << " ";
    }

    return 0;
}
