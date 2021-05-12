#include "std_lib_facilities.h"

int fact(int num) 
{
        if(num==1)return 1;
        else {return num * fact(num-1);}
}

int perm(int a,int b){
    int p = fact(a)/fact(a-b);
    return p;
}
int comb(int a,int b){
    int c = (perm(a,b)/fact(b));
    return c;
}

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}



int main() 
{
    int a,b,ta,tb,choice;
    stringstream s;

    cout<<"Enter a: ";
    while(!(cin>>a)){
        cout<<"Error: Input an integer "<<endl;
        cin.clear();
        cin.ignore(123,'\n');
        cout<<"Enter a: "<<endl;
        
    }
    
    cout<<"Enter b: ";
    while(!(cin>>b)){
        cout<<"Error: Input an integer "<<endl;
        cin.clear();
        cin.ignore(123,'\n');  
        cout<<"Enter b: ";
    }
    

    cout<<"Do you want to:\n1, Permutation\n2, Combination\n3, Both"<<endl;
    cout<<endl;
    cout<<"->";
    cin>>choice;

        try
        {
            cout<<a<<" operator "<<b<<endl;
            if(choice == 1){
                cout<<"Ans = "<<perm(a,b)<<endl;
                exit(1);
            }   
            if(choice == 2){
                cout<<"Ans = "<<comb(a,b)<<endl;
                exit(1);
            }
            else if(choice == 3){
                cout<<"Permutation = "<<perm(a,b)<<", Combination = "<<comb(a,b)<<endl;
                exit(1);
            }

            else {
                error("Input an integer 1,2, or 3");
                }
            }
        catch(const exception& e){cerr << e.what() << '\n';}

    return 0;
}
