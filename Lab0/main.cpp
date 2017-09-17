#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vctr;
    int input = 0;
    int max_int = -20000000;
    int min_int = 20000000;
    int i = 0;
    double total = 0.0;
    double mean = 0.0;
    int num_ints = 0;

    //intput values into the vector
    while (input >= 0){
        cin >> input;
        vctr.push_back(input);
    }


    //iterate through the vector backwards and calculate the min and max
    for (unsigned i = vctr.size()-1; i-- > 0; ){
        cout << vctr.at(i) << endl;

        if (vctr.at(i) > max_int){
            max_int = vctr.at(i);
        }

        if (vctr.at(i) < min_int){
            min_int = vctr.at(i);
        }
    }


    //calculates the values needed for the mean
    for (unsigned i = vctr.size()-1; i-- > 0; ){
        if (vctr.at(i) != min_int){
            total+= vctr.at(i);
            num_ints +=1;
        }

    }




    cout << "Max: " << max_int << endl;
    cout << "Min: " << min_int << endl;

    //only outpus the mean if it is defined
    if (num_ints == 0){
        cout << "Mean: Undefined."  << endl;
    }
    else {
        mean = total/num_ints;
        cout << "Mean: " << mean << endl;
    }

    return 0;
}
