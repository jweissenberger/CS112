#include <iostream>
#include <vector>
using namespace std;

void q_merge (vector <int> &a, vector <int> &b, vector <int> &c);

void q_merge (vector <int> &a, vector <int> &b, vector <int> &c){
    if(a.size() == 0 && b.size() == 0){
        return;
    }
    else if (b.size() == 0){
        c.push_back((int)a.at(0));
        a.erase(a.begin());
    }
    else if(a.size()== 0){
        c.push_back((int)b.at(0));
        b.erase(b.begin());
    }
    else if(a.at(0)<b.at(0)){
        c.push_back((int)a.at(0));
        a.erase(a.begin());
    }
    else{
        c.push_back((int)b.at(0));
        b.erase(b.begin());
    }
    q_merge(a, b, c);

    return;
}

int main() {
    vector <int> vect_A, vect_B, vect_C;
    unsigned int size_A, size_B, inInt, i;



    cin >> size_A;

    cin >> size_B;
    for ( i=0; i<size_A;++i) {
        cin >> inInt;
        vect_A.push_back((int)inInt);
    }
    for (i=0; i<size_B;++i) {
        cin >> inInt;
        vect_B.push_back((int)inInt);
    }
    q_merge (vect_A, vect_B, vect_C);

    // Output the merged vector
    for (i=0; i<vect_C.size(); ++i) {
        cout << vect_C.at(i) << " ";
    }
    cout << endl;

    return 0;
}
