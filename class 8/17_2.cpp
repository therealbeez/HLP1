#include "std_lib_facilities.h"
//drill 17 part2

int loop_int = 0;

int main(){

    //2.1
    int int_value = 7;
	int* p1 = &int_value;

    //2.2
    cout << "value of int: " << int_value << "	\t value of p1: " << p1 << "." << endl << endl;
    
        cout << "----------------------------------------------------------------"                  << endl << endl;

    //2.3
    int arr [ 7 ] = { 1, 2, 4, 8, 16, 32, 64 };
	int* p2 = arr;

    //2.4

    for( loop_int = 0; loop_int < 7; ++loop_int ) {
		cout << (loop_int + 1 ) << " value: " << arr [ loop_int ] 
        << " \t address: " << &arr [ loop_int ]                                                          << endl;
	}

	cout << endl << "value of p2 IS: " << p2 << " ."                                                                       <<endl << endl;

    cout << "-----------------------------------------------------------------------"                               << endl << endl;

    //2.5
    int* p3 = p2;
    //2.6
    p2 = p1;
    //2.7
    p2 = p3;

    //2.8

    cout << "value = " << p1 << ", points to = " << *p1 << "."                                     <<endl;
	cout << "value p2 = " << p2 << ", points to = " << *p2 << "."<< endl <<endl;

    for( loop_int = 0; loop_int < 7; ++loop_int ) {
		cout << (loop_int + 1 ) << " value: " << arr [ loop_int ] 
        << " \t address: " << &arr [ loop_int ]                                              << endl;
	}
        cout << "-------------------------------------------------------"                   << endl << endl;

    //2.10
    int ten_int_array [ 10 ] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	p1 = ten_int_array;

    //2.11
    int ten_int_array_2 [ 10 ] = { 1, 5, 10, 20, 40, 80, 160, 320, 640, 1280 };
	p2 = ten_int_array_2;

    //2.12
    for( loop_int = 0; loop_int < 10; loop_int++ ) {
		p2 [ loop_int ] = p1 [ loop_int ];
    
    }

    //2.13 
    //2.10(vector)
    vector < int > ten_int_vector { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	p1 = &ten_int_vector [ 0 ];

    //2.11(vector)
    vector < int > ten_int_vector_2 { 3, 6, 12, 24, 48, 96, 192, 384, 768, 1536 };
	p2 = &ten_int_vector_2 [ 0 ];

    //2.13(vector)
    for( loop_int = 0; loop_int < 10; loop_int++ ) {
		p2 [ loop_int ] = p1 [ loop_int ];
    }

    return 0;
}


