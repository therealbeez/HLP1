#include "std_lib_facilities.h"

//factorial
int factorial(int n){
    int f = 1;
    for(int i = 1; i <=n; ++i) {
            f *= i;
        }
    return f;
}


//2.1
vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

//2.2
void f(vector<int> v){
    //2.3.a
    vector<int> lv;

    //2.3.b
    lv.reserve(v.size());
    for (auto a:gv){
        lv.push_back(a);
    }

    //2.3.c
    cout << "\nlv:\n";
    for (auto a:lv){
        cout << a << endl;
    }
    //2.3.d
    vector<int> lv2 = v;

    //2.3.e
    cout << "\nlv2:\n";
    for (auto a:lv2){
        cout << a << endl;
    }

}

int main(){


    //2.4.a
    cout << "\nElements GV:\n";
    f(gv);

    //2.4.b
    vector<int> vv;

    //2.4.c
    for (int i=0; i<10; i++){
        vv.push_back(factorial(i+1));
    }

    //2.4.d
    cout << "\nElements VV:\n";
    f(vv);

    return 0;
}