// Gardien //---------------------------------------------------------------------------------------
#ifndef _CHAINE_HPP_
#define _CHAINE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <sstream>
#include <string>
#include <typeinfo>
#include <exception.hpp>

// Prototypes //------------------------------------------------------------------------------------
template <typename T>
inline std::string chaine(const T &);

inline const std::string & chaine(const std::string &);
inline std::string chaine(int);
inline std::string chaine(double);

// template <typename... ARGS>
// inline std::string chaine(const ARGS &...); // Version variadic #1

template <typename PREMS,typename... RESTE>
inline std::string chaine(const PREMS &,const RESTE &...); // Version variadic #2

template <typename... ARGS>
inline std::string chaine(const std::tuple<ARGS...> &);

// Fonction "chaine" //-----------------------------------------------------------------------------

//----------------------------------------------------------------------------------Version primaire
template <typename T> inline std::string chaine(const T & /*x*/) {
 throw ExceptionChaine(typeid(T).name());
 // throw ExceptionChaine(x); // Appel constructeur template
}

//----------------------------------------------------------------------------------Version "string"
inline const std::string & chaine(const std::string & x) { return x; }

// Specialisation possible, mais a eviter (car copie du retour)
// template <> inline std::string chaine<std::string>(const std::string & x) { return x; }

//-------------------------------------------------------------------------------------Version "int"
inline std::string chaine(int x) {
 // Version qui fonctionne avec tout type ou l'operateur de flux existe
 std::stringstream s;
 s << x;
 return s.str();

 // Version pour les nombres
 // return std::to_string(x);
}

//----------------------------------------------------------------------------------Version "double"
inline std::string chaine(double x) {
 return std::to_string(x);
}

//----------------------------------------------------------------------------------Version variadic
// Version #1
// template <typename... ARGS>
// inline std::string chaine(const ARGS &... args) {
//  return ((chaine(args)+" ")+...); // = chaine(arg0)+chaine(arg1)+...+chaine(argn)
// }

// Version #2 (question subsidiaire)
template <typename PREMS,typename... RESTE>
inline std::string chaine(const PREMS & arg0,const RESTE &... args) {
 return chaine(arg0)+((" "+chaine(args))+...);
}

//-------------------------------------------------------------------------------------Version tuple
template <typename T,size_t... Is>
inline std::string chaine_bis(const T & t,std::index_sequence<Is...>) {
 return chaine(std::get<Is>(t)...);
}

template <typename... ARGS>
inline std::string chaine(const std::tuple<ARGS...> & t) {
 return chaine_bis(t,std::make_index_sequence<sizeof...(ARGS)>()); // = chaine_bis(t,seq<0,1,...,N-1>)
}

// Fin //-------------------------------------------------------------------------------------------
#endif
