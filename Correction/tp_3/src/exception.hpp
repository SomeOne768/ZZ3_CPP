// Gardien //---------------------------------------------------------------------------------------
#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <exception>
#include <demangle.hpp>

// Class  E x c e p t i o n C h a i n e //----------------------------------------------------------
class ExceptionChaine : public std::exception {
 //----------------------------------------------------------------------------------------Attributs
 private:
  std::string message_;

 //-------------------------------------------------------------------------------------Constructeur
 public:
  ExceptionChaine(const std::string & type)
  : message_("Conversion en chaine impossible pour '" + demangle(type) + "'") {}

  // Constructeur template (question subsidiaire)
  // template <class T> ExceptionChaine(const T &)
  // : message_("Conversion en chaine impossible pour '" + demangle(typeid(T).name()) + "'") {}

 //---------------------------------------------------------------------------------------------What
 public:
  const char * what() const noexcept override { return message_.c_str(); }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
