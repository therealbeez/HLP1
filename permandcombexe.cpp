#include "std_lib_facilities.h"

int a,b,ta,tb,choice;
string calcAgain = "y";


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

void doOperation(){
    if((choice==1)||(choice==2)||(choice==3)){
            try
            {
                cout<<a<<" operator "<<b<<endl;
                if(choice == 1){
                    cout<<"Ans = "<<perm(a,b)<<endl;
                    cin.clear();
                    cout << "Do you want to calculate again(y/n): ";
                    cin >> calcAgain;
                }   
                if(choice == 2){
                    cout<<"Ans = "<<comb(a,b)<<endl;
                    cin.clear();
                    cout << "Do you want to calculate again(y/n): ";
                    cin >> calcAgain;
                }
                else if(choice == 3){
                    cout<<"Permutation = "<<perm(a,b)<<", Combination = "<<comb(a,b)<<endl;
                    cin.clear();
                    cout << "Do you want to calculate again(y/n): ";
                    cin >> calcAgain;
                }

                else {
                    error("Input an integer 1,2, or 3");
                    }
                }
            catch(const exception& e){cerr << e.what() << '\n';}
            }
        else{
                cout<<"Input an integer 1,2, or 3"<<endl;
                cin.clear();
                cin.ignore(123,'\n');
                cin>>choice;
                doOperation();
            }
}

bool alessb(int a,int b){
    while (a<b)
        {
            cout<<"a must be greater than b"<<endl;
            
            cout<<"Enter a: ";
            while(!(cin>>a)){
                cout<<"Error: Input an integer "<<endl;
                cin.clear();
                cin.ignore(123,'\n');
                cout<<"Enter a: "<<endl;
                
            }
            ta=a;
            
            cout<<"Enter b: ";
            while(!(cin>>b)){
                cout<<"Error: Input an integer "<<endl;
                cin.clear();
                cin.ignore(123,'\n');  
                cout<<"Enter b: ";
            }
            tb=b;

            alessb(a,b);
            cout<<endl;

            return true;
        }
        return false;
    }




int main() 
{
    

    do
    {
        
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

        
        if(alessb(a,b)==true){
            
            a=ta;
            b=tb;
        }
            
        
        
        
        cout<<"Do you want to:\n1, Permutation\n2, Combination\n3, Both"<<endl;
        cout<<endl;
        cout<<"->";
        cin>>choice;

            if((choice==1)||(choice==2)||(choice==3)){
                try
                {
                    cout<<a<<" operator "<<b<<endl;
                    if(choice == 1){
                        cout<<"Ans = "<<perm(a,b)<<endl;
                        cin.clear();
                        cout << "Do you want to calculate again(y/n): ";
                        cin >> calcAgain;
                    }   
                    if(choice == 2){
                        cout<<"Ans = "<<comb(a,b)<<endl;
                        cin.clear();
                        cout << "Do you want to calculate again(y/n): ";
                        cin >> calcAgain;
                    }
                    else if(choice == 3){
                        cout<<"Permutation = "<<perm(a,b)<<", Combination = "<<comb(a,b)<<endl;
                        cin.clear();
                        cout << "Do you want to calculate again(y/n): ";
                        cin >> calcAgain;
                    }

                    else {
                        error("Input an integer 1,2, or 3");
                        }
                    }
                catch(const exception& e){cerr << e.what() << '\n';}
                }
            else{
                    cout<<"Input an integer 1,2, or 3"<<endl;
                    cin.clear();
                    cin.ignore(123,'\n');
                    cin>>choice;
                    doOperation();
                }
        
    } while (calcAgain == "y");
    

    return 0;
}