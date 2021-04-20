#include "std_lib_facilities.h"

//1.1
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//1.4.b
int factorial(int n){
    int fa = 1;
    for(int i = 1; i <= n; ++i) {
            fa *= i;
        }
    return fa;
}

//1.2
void f(int* array_ar, int int_ar){
    //1.3
    int la[10];
    for (int i=0; i<10; i++){
        la[i] = ga[i];
    }

    cout << "\nla[i]:\n";
    for (int i=0; i<10; i++){
        cout << la[i] << endl;
    }

    //1.2d
    int* p = new int[int_ar];
    for (int* i=p; i<p+int_ar; i++){
          *i = array_ar[i-p];
    }

    cout << "\n 1.2d, elements:\n";
    for (int* i=p; i<p+int_ar; i++){
         cout << *i << endl;
    }
    delete[] p;
}

int main(){

    //1.4.a
    cout<<"1.4.a"<<endl;
    f(ga,10);

    int aa[10];
    for (int i=0; i<10; i++){
        aa[i] = factorial(i+1);
    }

    //1.4.c
    cout<<"1.4.c"<<endl;
    f(aa,10);


    return 0;

}