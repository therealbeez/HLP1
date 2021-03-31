#include "std_lib_facilities.h"

int main() {

    int sum=0, number;
    vector<int> numbers;

    string text;
    fstream file;

    file.open("intputdata.txt", fstream::in);

    while (true) {
        file >> number;
        
        if (file.eof()) {
            numbers.push_back(number);
            break;
        }

        else if (file.fail()) { 
            file.clear();
            file >> text;
        }

        else if (file.bad()){
            error("Error while reading file");
            exit(1);
        }
        else numbers.push_back(number);
    }

    //sum of the numbers
    for (int i=0 ; i<numbers.size(); i++){
		sum +=numbers[i];
	}
    
    //output
    cout << "total sum of white spaced numbers:" << sum << "\n";

return 0;
}
