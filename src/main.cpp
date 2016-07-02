

#include <iostream>
#include <typeinfo>
#include <type_traits> 
#include "traits.hpp"
#include "fonction_conteneur.hpp"


using namespace testSFML;
using std::cout;
using std::endl;
using std::map;
using std::vector;

template<class T>
decltype(auto) foo(T&& t) { return t; }

int main() //int argc, char** argv)
{
	cout << "test " << endl;
 
    struct test {
      
        vector<int> a = { 4, 5 };
        
        void foo ()   {
            cout << "for range" << endl;
            for (auto & v : a )
            {
                cout << is_const<decltype(v)> ::value << endl;
            } 
             cout << "for it" << endl;
            for (auto it = a.begin() ; it != a.end() ; it ++)
            {
                cout << " same const it " << std::is_same< vector<int>::const_iterator , decltype(it) >::value <<endl;
                cout << " check const " << is_const< decltype(*it) >::value << endl;
                cout << is_const<decltype(get_value<vector<int>>(it))>::value << endl;;
            }
        }
    };
    
    test d;
    d.foo();
    
    int a = 4;
    const int& b = a;
    int& c = a ;

    cout << typeid(a).name() << " " << typeid(foo(a)).name()<< endl;
    cout << typeid(b).name() << " " << typeid(foo(b)).name()<< endl;
    cout << typeid(c).name() << " " << typeid(foo(c)).name()<< endl;

    return 0;
}
