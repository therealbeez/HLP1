
#include "std_lib_facilities.h"

//part 1

void print_array10( ostream& os, int* a ) {
    for(int i = 0; i < 10; i++ ) cout << (i + 1)  << " \t = "<< a [i]<<endl;
}

void print_array( ostream& os, int* a, int n ) {
    for( int i = 0; i < n; i++ ) cout << (i + 1) << " \t = "<< a [i]<<endl; 
}

void print_vector ( ostream& os, vector<int*> b, int n ) {
    for(int i = 0; i < b.size(); i++ ) cout << (i + 1) << " \t = " << *b [i] << endl;
    }

int* fill_array ( int n ){

	int* a = new int [n];
    for(int i = 0; i < n; i++ ) a [i] = 100+i;
    return a;

}

vector <int*> fill_vector ( int n ){

	vector < int* > v;
	for( int i = 0; i < n; i++ ) v.push_back( new int { 100+i } );
	return v;

}

int main(){

    int* first_ten_ints  = new int[10];

    for( int i = 0; i < 10; i++ ) cout << (i + 1) << " \t = " << first_ten_ints [i]<< endl;
    cout << endl;

    print_array10( cout, first_ten_ints);
    cout << endl;
	delete[] first_ten_ints;

    int* array10 = fill_array ( 10 );
    print_array ( cout, array10, 10);
    cout << endl;
    delete[] array10;
    
    int* array11 = fill_array ( 11 );
    print_array ( cout, array11, 11);
    cout << endl;
    delete[] array11;

    int* array20 = fill_array ( 20 );
    print_array ( cout, array20, 20);
    cout << endl;
    delete[] array20;

    //vectors
    cout << "Vectors"<<endl;
    cout<<endl;

    vector <int*> vector10 = fill_vector( 10 );
    print_vector( cout, vector10, 10);
    cout<< endl;

    vector <int*> vector11 = fill_vector( 11 );
    print_vector( cout, vector11, 11);
    cout<< endl;

    vector <int*> vector20 = fill_vector( 20 );
    print_vector( cout, vector20, 20);
    cout<< endl;

    

    //Part 2

    
	int integer =7;
	int* p1 = &integer;

    cout << "*p1: "<< *p1 <<" p1: " << p1 << endl;
    cout << endl;

    int arr [7] = { 1, 2, 4, 8, 16, 32, 64};

    int* p2 = arr;

    
    cout << "p2 =" << p2 << endl;
    cout << endl;

    cout << "*p2 =" << endl;
    print_array(cout,p2,7);

    int* p3 = p2;

    p2 = p1;
    p2 = p3;

    cout << "P1 = " << p1 << " *p1 = " << *p1 << endl;
    cout << "P2 = " << p2 << " *p2 = " << *p2 << endl; 


    int arr_10 [10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p1 = arr_10;

    int arr_final[10];    
    p2 = arr_final;

    for (int i=0; i<10; ++i) {
	p2[i] = p1[i];
    }

    vector < int > vec_10 { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int>* p1_v = &vec_10;

    vector<int> vec_final;
    vector<int>* P2_v = &vec_final;
    p2 = p1;


    return 0;

}
