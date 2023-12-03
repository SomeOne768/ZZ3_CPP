// Gardien //---------------------------------------------------------------------------------------
#ifndef POINT_HPP_e2de9d8bffa542748c65a181aaf7a778
#define POINT_HPP_e2de9d8bffa542748c65a181aaf7a778

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
