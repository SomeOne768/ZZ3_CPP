// Gardien //---------------------------------------------------------------------------------------
#ifndef _PUISSANCE_HPP_
#define _PUISSANCE_HPP_

// Classe  P u i s s a n c e //---------------------------------------------------------------------
template <int N> struct Puissance {
 static double valeur(double x) { return x*Puissance<N-1>::valeur(x); }
};

template <> struct Puissance<0> {
 static double valeur(double) { return 1; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
