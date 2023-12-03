// Gardien //---------------------------------------------------------------------------------------
#ifndef _EXPONENTIELLE_HPP_
#define _EXPONENTIELLE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <factorielle.hpp>
#include <puissance.hpp>

// Classe  E x p o n e n t i e l l e //-------------------------------------------------------------
template <int N> struct Exponentielle {
 static double valeur(double x)
 { return (Puissance<N>::valeur(x)/Factorielle<N>::valeur + Exponentielle<N-1>::valeur(x)); }
};

template <> struct Exponentielle<0> {
 static double valeur(double) { return 1; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
