// Entetes //---------------------------------------------------------------------------------------
#include <nuage.hpp>

// Fonctions //-------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------Barycentre
Cartesien barycentre(const Nuage & nuage) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 // Boucle a l'ancienne
 // for (Nuage::const_iterator i = nuage.begin(); i<nuage.end(); ++i) {
 //  (*i)->convertir(c);
 //  x+=c.getX();
 //  y+=c.getY();
 //  ++n;
 // }

 // Boucle C++ moderne
 for (Point * p : nuage) {
  p->convertir(c);
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 return Cartesien(x/n,y/n);
}

// Fin //-------------------------------------------------------------------------------------------
