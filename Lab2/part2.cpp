#include <iostream>
#include <vector>

using namespace std;

// Jack Weissenberger Lab 2: Vecotors and Merging

// Input is a series of lines each with a name, stored in que1 and que2, the text ENDQ indicates the end of input for
// each layer, the names must be inputed in alphabetical order for each vector
// These two vectors are merged alphabetically into que_merge
// Also print out a vector of the merged two vectors that does not have any duplicates and counts the number of times
// that name was duplicated in the initial merged vector

//**NOTE** the first letter of each input must ALL be uppercase or ALL be lowercase

int main() {

    //initialize vectors to be 100 long
    vector<string> que1(100);
    vector<string> que2(100);
    string name = "Jack";
    unsigned int i = 0, j = 0;

    cout << "Enter queues: " << endl;

    //input names into que1
    while (name != "ENDQ"){
        getline(cin, name);
        if (name != "ENDQ") {
            que1.at(i) = name;
        }
        ++i;
    }

    que1.resize(i-1);

    name = "Jack";

    //input names into que2
    while (name != "ENDQ"){
        getline(cin, name);
        if (name != "ENDQ") {
            que2.at(j) = name;
        }
        ++j;
    }

    que2.resize(j-1);

    cout << endl << "que1 :" << que1.size() << endl;
    for (i = 0; i<que1.size(); ++i){
        cout << que1.at(i) << endl;
    }

    cout << endl << "que2 :" << que2.size() << endl;
    for (i = 0; i<que2.size(); ++i){
        cout << que2.at(i) << endl;
    }

    vector<string> que_merge;
    i = 0;
    j = 0;

    while(i>=0){
        if ((i <= (que1.size()-1)) && (j <= (que2.size()-1))){
            if (que1.at(i) < que2.at(j)){
                que_merge.push_back(que1.at(i));
                ++i;
            }
            else if (que2.at(j) < que1.at(i)){
                que_merge.push_back(que2.at(j));
                ++j;
            }
            else if (que2.at(j) == que1.at(i)){
                que_merge.push_back(que2.at(j));
                que_merge.push_back(que1.at(i));
                ++j;
                ++i;
            }


        }


        else if ((i <= (que1.size()-1)) && (j == (que2.size()))){
            while(i <= que1.size()-1){
                que_merge.push_back(que1.at(i));
                ++i;
            }
        }

        else if ((i == (que1.size())) && (j <= (que2.size()-1))){
            while(j <= que2.size()-1){
                que_merge.push_back(que2.at(j));
                ++j;
            }
        }

        else{break;}
    }

    cout << endl << "que_merge :" << que_merge.size() << endl;
    for (i = 0; i<que_merge.size(); ++i){
        cout << que_merge.at(i) << endl;
    }

    //check to see if any of the values in que_merge are the same and counts the number of times it appeared
    vector<string> que_merge_no_dup;
    que_merge_no_dup = que_merge;
    vector<int> que_count;

    for (i=0; i<que_merge_no_dup.size(); ++i){
        que_count.push_back(1);
        for (j = 0;  j<que_merge_no_dup.size() ; ++j) {
           if((i != j) && (que_merge_no_dup.at(i) == que_merge_no_dup.at(j))){
               que_merge_no_dup.erase(que_merge_no_dup.begin()+j);
               que_count.at(i) += 1;
           }
        }
    }

    cout << endl << "que_merge_no_dup :" << que_merge_no_dup.size() << endl;
    for (i = 0; i<que_merge_no_dup.size(); ++i){
        cout << que_merge_no_dup.at(i) << " " << que_count.at(i) << endl;
    }

    return 0;
}
