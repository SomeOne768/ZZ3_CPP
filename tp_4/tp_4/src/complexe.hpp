// Gardien //---------------------------------------------------------------------------------------
#ifndef _COMPLEXE_HPP_
#define _COMPLEXE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <mouchard.hpp>

// Classe  C o m p l e x e //-----------------------------------------------------------------------
struct Complexe {
 double reel;
 double imaginaire;

 Complexe(double r = 0.0,double i = 0.0) : reel(r),imaginaire(i) {}
};

// Mouchard ? //------------------------------------------------------------------------------------
using complexe_t = Mouchard<Complexe>;
//using complexe_t = Complexe;

// Surcharge opérateurs //--------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------operator+
inline complexe_t operator+(const complexe_t & a,const complexe_t & b) {
 return complexe_t(a.reel+b.reel,a.imaginaire+b.imaginaire);
}

//-----------------------------------------------------------------------------------------operator*
inline complexe_t operator*(const complexe_t & a,const complexe_t & b) {
 return complexe_t(a.reel*b.reel-a.imaginaire*b.imaginaire,
                   a.reel*b.imaginaire+a.imaginaire*b.reel);
}

//----------------------------------------------------------------------------------------operator<<
inline std::ostream & operator<<(std::ostream & flux,const complexe_t & c) {
 flux << "(" << c.reel << ";" << c.imaginaire << ")";
 return flux;
}

// Classe  C o m p a r a t e u r C o m p l e x e //-------------------------------------------------
struct ComparateurComplexe {
 bool operator() (const complexe_t & a,const complexe_t & b) const {
  return (a.reel<b.reel || (a.reel==b.reel && a.imaginaire<b.imaginaire));
 }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
