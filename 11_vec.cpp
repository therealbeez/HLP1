#include "std_lib_facilities.h"


template<typename T, typename A>
struct vector_base {
	A alloc; 			                            	  
	T* elem; 				                               
	int sz; 				                               	
	int space; 				                          	   	
	vector_base() :elem{ nullptr }, space{ 0 }, sz{ 0 } {};	
	vector_base(const A& a, int n)
		: alloc{ a }, elem{ alloc.allocate(n) }, sz{ n }, space{ n }{ }

	~vector_base() { alloc.deallocate(elem, space); }
};


template<typename T, typename A = allocator<T>>

class our_vector : private vector_base<T, A> {

	
public:
	
    our_vector() :vector_base<T, A>() {};				//Default Constructor
    
    explicit our_vector(size_t s) :vector_base<T, A>(this->alloc, s)//normal
	{
		for (T* p = this->elem; p != this->elem + s; p++)
			this->alloc.construct(p, T());
	}

    our_vector(const our_vector<T, A>& vec): vector_base<T, A>{ vec.alloc, vec.size() }{ //copy constructor
        copy(vec.elem, vec.elem + vec->sz, this->elem);
    }

    our_vector(our_vector<T, A>&& vec){   //move constructor
        this->sz = vec.sz;
	    this->elem = vec.elem;
	    this->space = vec.space;
        vec.sz = 0;
        vec.elem = nullptr;
    }

    our_vector<T, A>& operator=(const our_vector<T, A>& vec){     //copy assignment
        
        if (this == &vec)
		return *this;

        if (vec.sz <= this->space) {								
            copy(vec.elem, vec.elem + vec.sz, this->elem);
            for (int i = vec.sz; i < this->sz; ++i) 
                this->alloc.destroy(&this->elem[i]);
            this->sz = vec.sz;
            return *this;
        }
        
        //vector_base<T, A> b(this->alloc, newalloc);
        vector_base<T, A> b(this->alloc, vec);
        copy(vec.elem, vec.elem + vec.sz, b);


        for (int i = 0; i < this->sz; ++i) 						
			this->alloc.destroy(&this->elem[i]);
		this->~vector_base<T, A>();

        swap<vector_base<T, A>>(*this, b);
        return *this;

    }

    our_vector<T, A>& operator=(our_vector<T, A>&& a){     //move assignment
        for (int i = 0; i < this->sz; ++i) 						
			this->alloc.destroy(&this->elem[i]);
		this->~vector_base<T, A>();

        this->elem = a.elem;
        this->sz = a.sz;
        this->space = a.space;
        a.elem = nullptr;
        a.sz = 0;
        return *this;
    }


    void reserve(int newalloc){
        if(newalloc <= this->space) return;
        vector_base<T, A> b(this->alloc, newalloc);

        uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);
        
        for (int i = 0; i < this->sz; ++i) 						
			this->alloc.destroy(&this->elem[i]);
		swap<vector_base<T, A>>(*this, b);

    }

    void resize(int newsize, T val){
        reserve (newsize);
        for(int i = this->sz; i < newsize; i++)
            this->alloc.construct(&this->elem[i], val);

        for(int i = newsize; i <this-> sz; i++)
            this->alloc.destroy(&this->elem[i]);
        this->sz = newsize;
    }

    void push_back(T t){
        if (this->space == 0)
            reserve(8);
        else if(this->sz == this->space)
            reserve(2*this->space);
        this->alloc.construct(&this->elem[this->sz], t);
        ++this->sz;
        
    }

    

	int size() const { return this->sz; };

    int capacity() const {return this->space;};


	~our_vector() {                     //destructor 
		for (int i = 0; i < this->sz; ++i) 						
			this->alloc.destroy(&this->elem[i]);
		this->~vector_base<T, A>();
	}

    // void reserve(int newalloc);
    // void resize(int newsize);
    // void push_back(double d);



    T& operator[](int n){return this->elem[n];} //unchecked access


    T at(int n){           //checked access
        if(n<0||n>=this->sz)
            throw out_of_range("Out of range access");
        return this->elem[n];
    }

	void print() {
		for (int i = 0; i < this->sz; i++) {
			cout << this->elem[i] << " ";
		}
		cout << endl;
	}
};


/*bool is_palindrome(const string& s) {
    int first = 0;
    int last = s.length() - 1;

    while(first<last){
        if(s[first] != s[last])
            return false;
        first++;
        last--;
    }

    return true;

}*/

int main() {

    try
    {
        our_vector<string> p(2);
        p[0] = "first";
        p[1] = "second";

        cout<<p.at(1)<<endl;

    }
    catch(out_of_range e)
    {
        cout << e.what() << '\n';
    }
    
    

    


	return 0;
}