// Gardien //---------------------------------------------------------------------------------------
#ifndef _NUAGE_HPP_
#define _NUAGE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

// Declarations anticipees //-----------------------------------------------------------------------
template <typename T> class Nuage;

// Declarations fonctions //------------------------------------------------------------------------
template <typename T> T                      barycentre_v1(const Nuage<T> &);
template <typename C> typename C::value_type barycentre_v2(const C &);

// Classe  N u a g e //-----------------------------------------------------------------------------
template <typename T> class Nuage {
 //--------------------------------------------------------------------------------------------Types
 public:
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;
  using value_type = typename std::vector<T>::value_type;
 //----------------------------------------------------------------------------------------Attributs
 private:
  std::vector<T> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  std::size_t size() const { return points_.size(); }

  const_iterator begin() const { return points_.begin(); }
  const_iterator end() const { return points_.end(); }

  iterator begin() { return points_.begin(); }
  iterator end() { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void ajouter(const T & point) { points_.push_back(point); }
};

// Implementation fonctions //----------------------------------------------------------------------

//----------------------------------------------------------------------------------Barycentre_v1<T>
template <typename T> T barycentre_v1(const Nuage<T> & nuage) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 // Boucle a l'ancienne
 // for (typename Nuage<T>::const_iterator i = nuage.begin(); i!=nuage.end(); ++i) {
 //  // i->convertir(c); // Methode virtuelle
 //  c=Cartesien(*i); // Methode concrete
 //  x+=c.getX();
 //  y+=c.getY();
 //  ++n;
 // }

 // Boucle C++ moderne
 for (const T & p : nuage) {
  // p.convertir(c); // Methode virtuelle
  c=Cartesien(p); // Methode concrete
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 return (n==0 ? T() : T(Cartesien(x/n,y/n)));
}

//----------------------------------------------------------------------------Barycentre_v1<Polaire>
template <> Polaire barycentre_v1<Polaire>(const Nuage<Polaire> & nuage) {
 double a = 0.0;
 double d = 0.0;
 int n = 0;

 // Boucle a l'ancienne
 // for (Nuage<Polaire>::const_iterator i = nuage.begin(); i!=nuage.end(); ++i) {
 //  a+=i->getAngle();
 //  d+=i->getDistance();
 //  ++n;
 // }

 // Boucle C++ moderne
 for (const Polaire & p : nuage) {
  a+=p.getAngle();
  d+=p.getDistance();
  ++n;
 }

 return (n==0 ? Polaire() : Polaire(a/n,d/n)); // Formule fausse bien entendu !
}

//----------------------------------------------------------------------------------Barycentre_v2<T>
template <typename C> typename C::value_type barycentre_v2(const C & container) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 // Boucle a l'ancienne
 // for (typename C::const_iterator i = container.begin(); i!=container.end(); ++i) {
 //  c=Cartesien(*i);
 //  x+=c.getX();
 //  y+=c.getY();
 //  ++n;
 // }

 using point_t = typename C::value_type;

 // Boucle C++ moderne
 for (const point_t & p : container) {
  c=Cartesien(p);
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 return (n==0 ? point_t() : point_t(Cartesien(x/n,y/n)));
}

// Fin //-------------------------------------------------------------------------------------------
#endif
