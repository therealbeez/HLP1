#include "std_lib_facilities.h"

//Error Handling
class InvalidChoice{};
class InvalidInput{};

//Functions
int Factorial(int);
void Permutation(int, int);
void Combination(int, int);

int main(){
    int choice,a,b;

    cout << "PERMUTATION AND COMBINATION CALCULATOR"<<endl;
    cout << "1-Permutation" << endl;
    cout << "2-Combination" << endl;
    cout << "3-Both" << endl;

    try{
        cout << "Enter your choice!" << endl;
        cin >> choice;
        if (choice < 1|| choice > 3){throw InvalidChoice{};}
    }
    catch(InvalidChoice){
        cout << "Your choice is invalid!";
        return 1;
    }

    //input and checks for 'a'

    try{
        cout << "Input value of a:" << endl;
        cin >> a;

        if(a == 0){throw InvalidInput{};}

    }
    catch(InvalidInput){
        cout << "The value of a can't be zero!" << endl;
        return 2;
    }

    //input for 'b'

    cout << "Input value of b" <<endl;
    cin >> b;

    try{
        if(a < b){throw InvalidInput{};}}
    catch (InvalidInput){
        cout << "a can't be less than b" << endl;
        return 3;
    }
    //calculation
    
    if(choice == 1){Permutation(a,b);}
    else if (choice == 1){Combination(a,b);}
    else{
        Permutation(a,b);
        Combination(a,b);
    }
    return 0;
}

int Factorial(int x){
    if(x <= 1){return 1;}
    return x*Factorial(x-1);
}

void Permutation(int x, int y){
    int Permutation;
    Permutation = (Factorial(x) / Factorial(x - y));
    cout << x << "P" << y << ": " << Permutation << endl;
}

void Combination(int x, int y){
    int Permutation, Combination;
    Permutation = (Factorial(x) / Factorial(x - y));
    Combination = Permutation / Factorial(y); 
    cout << x << "C" << y << ": " << Combination << endl;
}
