// Gardien //---------------------------------------------------------------------------------------
#ifndef _MOUCHARD_HPP_
#define _MOUCHARD_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <type_traits>
#include <utility>

// Metafonctions //---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------type_base_t
template <class T>
using type_base_t = typename std::remove_reference<
                              typename std::remove_const<T>::type
                             >::type;

//---------------------------------------------------------------------------------------meme_type_t
template <class T1,class T2>
using meme_type_t = std::is_same< type_base_t<T1>,type_base_t<T2> >;

// Classe  M o u c h a r d //-----------------------------------------------------------------------
template <class T> class Mouchard : public T {
 //----------------------------------------------------------------------------------------Attributs
 private:
  static unsigned long nbAffectation_;
  static unsigned long nbConstruction_;
  static unsigned long nbCopie_;
  static unsigned long nbMouvement_;

 //---------------------------------------------------------------------------------------Accesseurs
 public:
  static unsigned long getNbAffectation(void) { return nbAffectation_; }
  static unsigned long getNbConstruction(void) { return nbConstruction_; }
  static unsigned long getNbCopie(void) { return nbCopie_; }
  static unsigned long getNbMouvement(void) { return nbMouvement_; }

 public:
  //-----------------------------------------------------------------------------Constructeur defaut
  Mouchard(void) { ++nbConstruction_; }

  //------------------------------------------------------------------------------Constructeur copie
  Mouchard(const Mouchard & x) : T(x) {
   ++nbConstruction_;
   ++nbCopie_;
  }

  //--------------------------------------------------------------------------Constructeur mouvement
  Mouchard(Mouchard && x) : T(std::move(x)) {
   ++nbConstruction_;
   ++nbMouvement_;
  }

  //-------------------------------------------------------------------------------Affectation copie
  Mouchard & operator=(const Mouchard & x) {
   ++nbAffectation_;
   ++nbCopie_;
   T::operator=(x);
   return *this;
  }

  //---------------------------------------------------------------------------Affectation mouvement
  Mouchard & operator=(Mouchard && x) {
   ++nbAffectation_;
   ++nbMouvement_;
   T::operator=(std::move(x));
   return *this;
  }

  //-------------------------------------------------------------------------Constructeur quelconque
  template <class X,class... PACK,
            class = typename std::enable_if< !meme_type_t< X,Mouchard<T> >::value>::type
           >
  Mouchard(X && x,PACK &&... pack) : T(std::forward<X>(x),std::forward<PACK...>(pack...)) {
   ++nbConstruction_;
  }

  //--------------------------------------------------------------------------Affectation quelconque
  template <class X,
            class = typename std::enable_if< !meme_type_t< X,Mouchard<T> >::value>::type
           >
  Mouchard & operator=(X && x) {
   ++nbAffectation_;
   T::operator=(std::forward<X>(x));
   return *this;
  }

  //-------------------------------------------------------------------------------------------stats
  static void stats(void) {
   static unsigned n = 0;

   std::cout << "[" << (n++) << "] "
   	     << "affectations = " << nbAffectation_ << " ; "
             << "constructions = " << nbConstruction_ << " ; "
             << "copies = " << nbCopie_ << " ; "
             << "mouvements = " << nbMouvement_ << std::endl;
  }
};

//-------------------------------------------------------------------------------Attributs statiques
template <class T> unsigned long Mouchard<T>::nbAffectation_  = 0;
template <class T> unsigned long Mouchard<T>::nbConstruction_ = 0;
template <class T> unsigned long Mouchard<T>::nbCopie_        = 0;
template <class T> unsigned long Mouchard<T>::nbMouvement_    = 0;

// Fin //-------------------------------------------------------------------------------------------
#endif
