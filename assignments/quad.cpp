#include "std_lib_facilities.h"


float a, b, c, x1, x2;
void printroots(int a, int b, int c);


int main() {

    cout << "input a: ";
    cin >> a;
    cout << "input b: ";
    cin >> b;
    cout << "input c: ";
    cin >> c;

    printroots(a,b,c);

    return 0;
}

void printroots(int a, int b, int c){

    float disc, img, real;

    disc = b*b - 4*a*c;
    
    if (disc > 0) {     
        x1 = (-b + sqrt(disc)) / (2*a);
        x2 = (-b - sqrt(disc)) / (2*a);

        cout << "x1 = " << x1 <<" x2 = " << x2 <<endl;
    }
    
    else if (disc == 0) {
        x1 = -b/(2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else {
        cout<<"no real roots";
    }
}


