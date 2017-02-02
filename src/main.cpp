

#include <iostream>
#include <typeinfo>
#include <type_traits> 
#include "traits.hpp"

#include <set>
#include <unordered_map>


#include <boost/core/demangle.hpp>
#include <typeinfo>
#include <iostream>

template<class T> struct X
{
};

using namespace testSFML;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using boost::core::demangle;
template<class T>
decltype(auto) foo(T&& t) { return t; }

template < class R, class TT, class U, class Lapin> 
struct b {};

int main() //int argc, char** argv)
{
	is_map<std::map<int,double>> d;
	is_map<std::map<int,int>> dd;
	is_map<std::unordered_map<int,int>> ded;
	
	
	is_map<const std::unordered_map<int,int>> deddfsdf;
	
	is_map<std::unordered_map<int,int> &> dessd;
	is_map<b<int,int,int,int>> qsdf;
	/*
	std::pair<int,int> a, b ;
	
	cout << " compraison de deux paire de int " << ( a == b )<< endl; ;
    cout << endl << endl << " test contain " << endl << endl; 
    
    std::set<int> s = { 1 , 4 , 5, 6 , 5 };
    std::vector<int> v = { 5,  1 };
    std::map<std::string, int> m = { {"d",1} , {"r",5} , { "l", 4 } }; 
    
    cout << typeid(get_value(s.begin(),s)).name() << endl;
    cout << typeid(int).name() << endl;
    cout << std::is_same< std::decay_t<decltype (get_value(s.begin(),s))>,
                          int  >::value << endl;
                          
    cout << " recherche d'un element " << endl;
    cout << "1 : " << contain(v,1) << endl; 
    cout << "0 : " << contain(v,2) << endl; 
    cout << "1 : " << contain(s,6) << endl; 
    cout << "0 : " << contain(s,2) << endl;
    cout << "1 : " << contain(m,5) << endl; 
    cout << "0 : " << contain(m,2) << endl;   
    cout << "recherche d'un conteneur" << endl; 
    
    cout << "1 : " << contain(s,v) << endl; 
    cout << "1 : " << contain(s,m) << endl; 
    cout << "1 : " << contain(m,v) << endl; 
    
    cout << "0 : " << contain(v,s) << endl;
    cout << "0 : " << contain(m,s) << endl;
    cout << "0 : " << contain(v,m) << endl;
    
    cout << " autres tests " << endl;
    
    std::vector<std::string> vs = { "a", "b", "r", "c" };
    cout << "1 : " << contain(vs,std::string("r")) << endl;
    cout << "1 : " << contain (m,std::pair<std::string,int>(std::string("d"),1)) << endl;;
    cout << "1 : " << contain (std::string("(qdsf)"),'s') << endl;
    cout << "0 : " << contain(vs,std::string("h")) << endl;
    cout << "0 : " << contain (m,std::pair<std::string,int>(std::string("h"),1)) << endl;;
    cout << "0 : " << contain (std::string("(qdsf)"),'h') << endl;
    /*
    cout << endl << endl <<  "test is_const " << endl <<  endl;
    struct test {
      
        vector<int> a = { 4, 5 };
        
       void fooconst() const  {
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
                cout << is_const<decltype(get_value(it,a))>::value << endl;
            }
       }
       
       void foo ()  {
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
                cout << is_const<decltype(get_value(it,a))>::value << endl;
            }
       }
    };
    
    test d;
    cout << " non const " << endl;
    d.foo();
    cout << " const " << endl;
    d.fooconst();
    */
    


    return 0;
}
