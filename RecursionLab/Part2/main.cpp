//Jack Weissenberger Recursive lab Part 2
// Merge two vectors using recursion, each should be in numerical order

#include <iostream>
#include <vector>
using namespace std;

void q_merge (vector <int> &vec1, vector <int> &vec2, vector <int> &vecNew);

void q_merge (vector <int> &vec1, vector <int> &vec2, vector <int> &vecNew){

    //base case, when both vectors have no more values
    if(vec1.empty() && vec2.empty()){
        return;
    }

    //if vec2 has no more values fill the merge vector with values from vec1
    else if (vec2.size() == 0){
        vecNew.push_back((int)vec1.at(0));
        vec1.erase(vec1.begin());
    }

    //if vector 2 is larger, input vector 1
    else if(vec1.at(0)<vec2.at(0)){
        vecNew.push_back((int)vec1.at(0));
        vec1.erase(vec1.begin());
    }

    //if vec1 has no more values, fill the merge vector with values from vec2
    else if(vec1.size()== 0){
        vecNew.push_back((int)vec2.at(0));
        vec2.erase(vec2.begin());
    }

    //this is the case that vector1 is larger, so the value from vector2 is inputted
    else{
        vecNew.push_back((int)vec2.at(0));
        vec2.erase(vec2.begin());
    }
    q_merge(vec1, vec2, vecNew);

    return;
}

int main() {

    vector <int> vecA;
    vector <int> vecB;
    vector <int> vMerge;
    unsigned int sizeA, sizeB, userIn, i;


    cout << "Input the size of A" << endl;
    cin >> sizeA;

    cout << "Input the size of B" << endl;
    cin >> sizeB;

    //fill the values of vector A
    cout << "Input values into A" << endl;
    for ( i=0; i<sizeA;++i) {
        cin >> userIn;
        vecA.push_back((int)userIn);
    }

    cout << "Input values into B" << endl;
    //Fill the values of vectorB
    for (i=0; i<sizeB;++i) {
        cin >> userIn;
        vecB.push_back((int)userIn);
    }
    q_merge (vecA, vecB, vMerge);

    // print the newly merged vector
    for (i=0; i<vMerge.size(); ++i) {
        cout << vMerge.at(i) << " ";
    }
    cout << endl;

    return 0;
}

