#ifndef OUITLS_HPP
#define OUITLS_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <utility>
#include <fstream>

#include "traits.hpp"

namespace testSFML 
{

        
    template < 	bool is_map , 
				class T>
	struct get_value_s
	{
		auto& get_value (const T& ite) { return *ite; }
		//const auto& get_value (const T& ite) { return *ite; }
	};
	
	template <class T>
	struct get_value_s < true, T >
	{
		auto& get_value (const T& ite) { return ite->second;; }
		//const auto& get_value (const T& ite) { return ite->second;; }
	};
	
	
    template<class U , class T>
	auto& get_value (const T& ite)
	{
        get_value_s<is_map<U>::value,T> gvs;
        return gvs.get_value(ite);
	}
	
	template<class U, class T>
	auto& get_value (const T& ite,const U&)
	{
        get_value_s<is_map<U>::value,T> gvs;
        return gvs.get_value(ite);
	}

	
	

    //
    // TODO : decltype de is_same devrait etre sur le get_value
    // la version ou U et T contiennent le meme type
    template <	class Conteneur1, class Conteneur2 > 
    auto contain (const Conteneur1& conteneur1,  const Conteneur2& conteneur2) 
         ->  last_t <  enable_if_all_t <is_container, Conteneur1, Conteneur2 >,
                       std::enable_if_t<
                                          std::is_same < std::decay_t<decltype ( get_value<Conteneur1>(std::declval<Conteneur1>().begin() ))>,
                                                         std::decay_t<decltype ( get_value<Conteneur2>(std::declval<Conteneur2>().begin() ))>
                                                        >::value
                                        >,
                       bool>
                       
    {
        if ( conteneur1.size() < conteneur2.size() ) { return false;}
        bool ok = true;
        
        for ( auto it = conteneur2.begin() ; it != conteneur2.end() && ok ; it = std::next(it) )
        {
            // je ne peux pas utiliser find_if + get_val car find_if passe la valeur
            // et pas l'itérateur 
            // je dois donc faire la boucle à la main
            auto it1 = conteneur1.begin();
            bool fini = false;
            while ( ok and not fini) 
            {
                if ( it1 == conteneur1.end() )
                {
                    ok = false;
                }
                else
                {
                    if ( get_value<Conteneur1>(it1) == get_value<Conteneur2>(it) )
                    {
                        fini = true;
                    }
                }
                it1 = std::next(it1);
            }          
        }
        return ok;
    }
    
    // TODO faire une version generic map ou pas 
    template < class Conteneur1,
			   class U> 
	auto contain (const Conteneur1& conteneur1 , const U& value)
         -> last_t <    std::enable_if_t <is_container<Conteneur1>::value>,
                       std::enable_if_t<
                                          std::is_same < std::decay_t<decltype (get_value<Conteneur1>(std::declval<Conteneur1>().begin()))>,
                                                         std::decay_t<U>
                                                        >::value
                                        >,
                       bool>
	{
        auto it1 = conteneur1.begin();
        bool trouve = false;
        while ( not trouve and (it1 != conteneur1.end()) ) 
        {
            if ( get_value<Conteneur1>(it1) == value )
            {
                trouve = true;
            }
            it1 = std::next(it1);
        }      

        return trouve;
	}
    
    
    
    


}
#endif

