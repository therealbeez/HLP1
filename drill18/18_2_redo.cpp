#include "std_lib_facilities.h"

int factorial(int n);
vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> arr_v){

    vector<int> lv;

    lv.reserve(arr_v.size());
    for (auto a:gv) lv.push_back(a);
    for (auto a:lv) cout << a << endl;
    cout << endl;
    
    vector<int> lv2;
    lv2 = arr_v;
    for (auto a:lv2) cout << a << endl;
    cout << endl;
}

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main(){
    cout << "\ngv:\n";
    f(gv);
    vector<int> vv;
    for (int i=0; i<10; i++) vv.push_back(factorial(i+1));
    cout << "\nvv:\n";
    f(vv);
    return 0;
}