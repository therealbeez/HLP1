#include "std_lib_facilities.h"

//Drill 17

int loop_int = 0;

void print_10_array ( ostream& os, int* a ) {

   

void print_10_array_2 ( ostream& os, int* a ) {
//1.5
    cout << "1.5" <<endl;
    for( loop_int = 0; loop_int < 10; loop_int++ ){
		cout << (loop_int + 1) << " \t value: " << a [ loop_int ]; 
        cout << " \t address: " << &a [ loop_int ]                                 << endl;

        
    }
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

}
	
 //1.4
    cout << "1.4" <<endl;
    
    for( loop_int = 0; loop_int < 10; loop_int++ ) {
		cout << (loop_int + 1) << " \t value: " << a [ loop_int ]; 
        cout << " \t address: " << &a [ loop_int ]                                                 << endl;

        
    }
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

}



void print_11_array ( ostream& os, int* a, int n ) {

//1.7
    cout << "1.7" <<endl;
    for( loop_int = 0; loop_int < n; loop_int++ ){
		cout << (loop_int + 1) << " \t value: " << a [ loop_int ]; 
        cout << " \t address: " << &a [ loop_int ]                                 << endl;

    }
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;


}

void print_20_array ( ostream& os, int* a, int n ) {

//1.8
    cout << "1.7" <<endl;
    
    for( loop_int = 0; loop_int < n; loop_int++ ){
		cout << (loop_int + 1) << " \t value: " << a [ loop_int ]; 
        cout << " \t address: " << &a [ loop_int ]                                                  << endl;
    }

    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;
}

// allocation to array
int* array_value_allocation ( int n ){

	int* Array_Copy = new int [ n ];

	int Initalizer = 100;

    // storage in array
	for( loop_int = 0; loop_int < n; loop_int++ ) {
		Array_Copy [ loop_int ] = Initalizer++;
    }

	return Array_Copy;
}

// allocation to vector
vector <int*> vector_value_allocation ( int n ){

	vector < int* > Vector_Copy;

	int Initalizer = 100;

    // storage in vector
	for( loop_int = 0; loop_int < n; loop_int++ ) {
		Vector_Copy.push_back( new int { Initalizer++ } );
    }

	return Vector_Copy;
}


int main(){
    
    //1.1
    
	    int Length_Of_An_Array = 10;
	    int* ten_int_array = new int [ Length_Of_An_Array ];

    //1.2
    cout << "1.2" <<endl;

        for( loop_int = 0; loop_int < 10; loop_int++ ){
		    cout << (loop_int + 1) << " \t value: " << ten_int_array [ loop_int ]; 
            cout << " \t address: " << &ten_int_array [ loop_int ]                                 << endl;
            
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    //1.4
    cout << "1.4" <<endl;
    print_10_array ( cout, ten_int_array);
	    delete[] ten_int_array;
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;
    
    //1.5
    int* ten_int_array_2 = array_value_allocation ( 10 );

    cout << "1.5" <<endl;
    print_10_array_2 ( cout, ten_int_array_2 );
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;
	delete[] ten_int_array_2;

    //1.6

    int* eleven_int_array = array_value_allocation ( 11 );
    cout << "1.6" <<endl;

    for( loop_int = 0; loop_int < 11; loop_int++ ) {
		    cout << (loop_int + 1) << " \t value: " << eleven_int_array [ loop_int ]; 
            cout << " \t address: " << &eleven_int_array [ loop_int ]                             << endl;
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    delete[] eleven_int_array;

    //1.7
    int* eleven_int_array_2 = array_value_allocation ( 11 );

    cout << "1.7" <<endl;
    print_11_array ( cout, eleven_int_array, 11);
    delete[] eleven_int_array_2;
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    //1.8
    cout << "1.8" <<endl;
    int* twenty_int_array = array_value_allocation ( 20 );
    print_20_array ( cout, twenty_int_array, 20 );
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    //1.9
    delete[] twenty_int_array;

    //1.10
    //VECTOR VERSIONS

    //1.5(vector)
    vector <int*> ten_int_vector = vector_value_allocation ( 10 );
    cout << "1.10.5" <<endl;
    for( loop_int = 0; loop_int < ten_int_vector.size(); loop_int++ ){
		    cout << (loop_int + 1) << " \t value: " << *ten_int_vector [ loop_int ]; 
            cout << " \t address: " << &ten_int_vector [ loop_int ]                                 << endl;
        }
        cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    for( loop_int = 0; loop_int < ten_int_vector.size(); loop_int++ ) {
    	    delete ten_int_vector [ loop_int ];
        }

    //1.6(vector)
    vector <int*> eleven_int_vector = vector_value_allocation ( 11 );
    cout << "1.10.6" <<endl;
    for( loop_int = 0; loop_int < eleven_int_vector.size(); loop_int++ ) {
		    cout << (loop_int + 1) << " \t value: " << *eleven_int_vector [ loop_int ]; 
            cout << " \t address: " << &eleven_int_vector [ loop_int ]                              << endl;
        }
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;
    
    for( loop_int = 0; loop_int < eleven_int_vector.size(); loop_int++ ) {
    	    delete eleven_int_vector [ loop_int ];
        }
    
    //1.8(vector)

    vector < int* > twenty_int_vector = vector_value_allocation ( 20 );
    
    cout << "1.10.6" <<endl;
    for( loop_int = 0; loop_int < twenty_int_vector.size(); loop_int++ ) {
		    cout << (loop_int + 1) << " \t value: " << *twenty_int_vector [ loop_int ]; 
            cout << " \t address: " << &twenty_int_vector [ loop_int ]                              << endl;
        }
    cout << endl << "-----------------------------------------------------------------------------------" << endl << endl;

    for( loop_int = 0; loop_int < twenty_int_vector.size(); loop_int++ ) {
    	    delete twenty_int_vector [ loop_int ];
        }
    
    return 0;

}

