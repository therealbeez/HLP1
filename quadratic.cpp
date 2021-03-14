#include <iostream>
#include <cmath> 

using namespace std;
int main(){
    
    double a,b,c;
    float discriminant1 = ((b*b) - 4 * a * c);

    cout << "Enter Coefficients: a then b then c"<<endl;
    cin>>a>>b>>c;

    if(a == 0){
        cout << "ERROR: UNDEFINED"<< endl;
        return 1;
    }

    else if (discriminant1 < 0){
        cerr << "No real roots found!\n";
    }
    


    double x1,x2;

    x1 = ((-b + sqrt(discriminant1))/(2*a));
    x2 = ((-b - sqrt(discriminant1))/(2*a));

    cout<<endl<<"Roots:"<<"X1= "<<x1<<" X2= "<<x2<<endl;
    
}