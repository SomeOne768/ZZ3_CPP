// Gardien //---------------------------------------------------------------------------------------
#ifndef _DEMANGLE_HPP_
#define _DEMANGLE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <string>

// Fonction "demangle" pour GCC //------------------------------------------------------------------
#ifdef __GNUC__
 #include <cstdlib>
 #include <cxxabi.h>

 inline std::string demangle(const std::string & name) {
  int status = -4;
  char * decoded = abi::__cxa_demangle(name.c_str(),0,0,&status);
  std::string result = (status==0 ? decoded : name.c_str());

  free(decoded);
  return result;
 }

// Fonction "demangle" par defaut (ne fait rien) //-------------------------------------------------
#else
 inline std::string naw_demangle(const std::string & name) { return name; }
#endif

// Fin //-------------------------------------------------------------------------------------------
#endif
