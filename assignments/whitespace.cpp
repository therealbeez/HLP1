#include "std_lib_facilities.h"

int main() {
    int sum = 0;
    int number;
    ifstream file("numspace.txt");
    string text;

    while (file >> text) {
        
        istringstream(text) >> number;
        sum += number;
        if (file.fail()){file.clear();}
        else if (file.bad()){exit(1);}
        
    }
    cout << "the shop has "<<sum<<" items"<< endl;

    return 0;
}