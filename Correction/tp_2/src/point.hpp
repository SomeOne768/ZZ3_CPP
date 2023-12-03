// Gardien //---------------------------------------------------------------------------------------
#ifndef _POINT_HPP_
#define _POINT_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>

// Declarations anticipees //-----------------------------------------------------------------------
class Point;
class Cartesien;
class Polaire;

// Declarations fonctions //------------------------------------------------------------------------
std::ostream & operator<<(std::ostream &,const Point &);
std::istream & operator>>(std::istream &,Point &);

// Classe  P o i n t //-----------------------------------------------------------------------------
class Point {
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  virtual void afficher(std::ostream &) const = 0;
  virtual void charger(std::istream &) = 0;
  virtual void convertir(Cartesien &) const = 0;
  virtual void convertir(Polaire &) const = 0;
};

// Fin //-------------------------------------------------------------------------------------------
#endif
