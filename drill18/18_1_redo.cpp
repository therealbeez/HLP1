#include "std_lib_facilities.h"

int factorial(int n);
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };


void f(int* array_ar, int int_ar){
    int la[10];
    for (int i=0; i<10; i++) la[i] = ga[i];
    for (int i=0; i<10; i++) cout << la[i] << endl;
    cout << endl;

    int* p = new int[int_ar];

    
    for (int i = 0; i < int_ar; ++i) p[i] = array_ar[i];
    for (int i = 0; i < int_ar; ++i) cout << p[i] << '\n';
    cout << endl;

    delete[] p;
}

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


int main(){
    f(ga,10);

    int aa[10];
    for (int i=0; i<10; i++) aa[i] = factorial(i+1);
    f(aa,10);

    return 0;
}