#include <iostream>
using namespace std;

//allow numMoves to be accessed by everything
int numMoves=0;

//initializing move_discs
void move_discs(int, char, char, char, int &);

//the recursive function that moves each of the discs
void move_discs(int numDiscs, char Tower1, char Tower2, char Tower3, int &numMoves)
{
    //base case, when there is only one disc
    if (numDiscs == 1) {
        cout << "Move disc 1 from " << Tower1 <<" to "<< Tower2 <<endl;
        numMoves++;
        return;
    }

    //first recursive call that is the intermediary step that moves everything possible off the first tower
    move_discs(numDiscs - 1, Tower1, Tower3, Tower2, numMoves);

    cout<<"Move disc "<< numDiscs <<" from "<< Tower1 <<" to "<< Tower2 <<endl;

    //second recursive call that moves to tower 3
    move_discs(numDiscs - 1, Tower3, Tower2, Tower1, numMoves);

    //keeps track of the number of moves
    numMoves++;
}


int main()
{
    int numDiscs;

    cout << "Number of discs: "<<endl;
    cin>>numDiscs;

    //calls the recursive function
    move_discs(numDiscs, 'A', 'B', 'C', numMoves);

    //outputs the number of moves
    cout<<"Number of moves: "<< numMoves << endl;

    return 0;

}


