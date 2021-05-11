#include "std_lib_facilities.h"

//generic print function for lists and vectors
template<typename T> void printtype(const T& t)
{
    for (const auto& a : t){cout << a <<endl;}
    cout << endl;
}


struct Item{
    
    string name;
    int iid;
    double value;

    friend istream& operator >> (istream& input, Item& item){
        input >> item.name >> item.iid >> item.value;
        return input;
    }

    friend ostream& operator << (ostream& output, const Item& item){
        output << item.name << " " << item.iid << " " << item.value;
        return output;
    }

};

//functions for name
struct find_by_name{
    string name;
    find_by_name(const string& n) : name(n) { }
    bool operator()(const Item& a) const { return a.name == name; }
};
struct Cmp_by_name{bool operator()(const Item &a, const Item &b) const{return a.name < b.name;}};

//functions for iid
struct find_by_iid{
    int iid;
    find_by_iid(int i) : iid(i) { }
    bool operator()(const Item& a) const { return a.iid == iid; }
};
struct Cmp_by_iid{bool operator()(const Item &a, const Item &b) const{return a.iid < b.iid;}};

//functions for value
struct find_by_value{
    double value;
    find_by_value(double v) : value(v) { }
    bool operator()(const Item& a) const { return a.value == value; }
};
//descending
struct Cmp_by_value{bool operator()(const Item &a, const Item &b) const{return a.value > b.value;}};


int main(){

    vector<Item> vi;
    list<Item> list_item;

    Item fileinput;
    ifstream file("inputfile.txt");

    while(file >> fileinput){

        vi.push_back(fileinput);
        list_item.push_back(fileinput);
    }


    
    //with vectors
    cout<<endl;
    cout<<"Vectors"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Deafult"<<endl;
    printtype(vi);

    sort(vi.begin(), vi.end(), Cmp_by_name());
    cout<<"By name:"<<endl;
    printtype(vi);

    sort(vi.begin(), vi.end(), Cmp_by_iid());
    cout<<"By iid:"<<endl;
    printtype(vi);

    sort(vi.begin(), vi.end(), Cmp_by_value());
    cout<<"By descending value:"<<endl;
    printtype(vi);

    Item horse = {"horse shoe",99,12.34}; 
    Item canon = {"Canon S400", 9988,499.95};
    vi.push_back(horse);
    vi.push_back(canon);
    cout<<"With new values:"<<endl;
    printtype(vi);

    vi.erase(find_if(vi.begin(), vi.end(), find_by_name("pig")));
    vi.erase(find_if(vi.begin(), vi.end(), find_by_name("dig")));
    cout<<"After removal by name :"<<endl;
    printtype(vi);

    vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(6)));
    vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(7)));
    cout<<"After removal by iid :"<<endl;
    printtype(vi);


    //with lists

    cout<<endl;
    cout<<"Lists"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Deafult"<<endl;
    printtype(list_item);

    list_item.sort(Cmp_by_name());
    cout<<"By name:"<<endl;
    printtype(list_item);

    list_item.sort(Cmp_by_iid());
    cout<<"By iid:"<<endl;
    printtype(list_item);

    list_item.sort(Cmp_by_value());
    cout<<"By descending value:"<<endl;
    printtype(list_item);

    Item horse2 = {"horse shoe",99,12.34}; 
    Item canon2 = {"Canon S400", 9988,499.95};
    list_item.push_back(horse2);
    list_item.push_back(canon2);
    cout<<"With new values:"<<endl;
    printtype(list_item);

    list_item.erase(find_if(list_item.begin(), list_item.end(), find_by_name("pig")));
    list_item.erase(find_if(list_item.begin(), list_item.end(), find_by_name("dig")));
    cout<<"After removal by name :"<<endl;
    printtype(list_item);

    list_item.erase(find_if(list_item.begin(), list_item.end(), find_by_iid(6)));
    list_item.erase(find_if(list_item.begin(), list_item.end(), find_by_iid(7)));
    cout<<"After removal by iid :"<<endl;
    printtype(list_item);

    return 0;
}
