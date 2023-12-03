// Gardien //---------------------------------------------------------------------------------------
#ifndef VECTEUR_HPP_e2de9d8bffa542748c65a181aaf7a778
#define VECTEUR_HPP_e2de9d8bffa542748c65a181aaf7a778

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>

// Declarations anticipees //-----------------------------------------------------------------------
class Iterateur;
class Vecteur;

// Declarations fonctions //------------------------------------------------------------------------
std::ostream & operator<<(std::ostream &,const Vecteur &);
Vecteur        operator+(const Vecteur &,const Vecteur &);
int            operator*(const Vecteur &,const Vecteur &);

// Classe  I t e r a t e u r //---------------------------------------------------------------------
class Iterateur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  int * position_;
 //------------------------------------------------------------------------------------Constructeurs
 public:
  Iterateur(int * p) : position_(p) {}
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  Iterateur & operator++() { ++position_; return (*this); }
  Iterateur   operator++(int) { Iterateur i(position_); ++position_; return i; }

  bool operator==(const Iterateur & i) const { return position_==i.position_; }
  bool operator!=(const Iterateur & i) const { return position_!=i.position_; }

  int operator*() const { return *position_; }
};

// Classe  V e c t e u r //-------------------------------------------------------------------------
class Vecteur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  int * elements_;
  int   taille_;
  int   capacite_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  Iterateur begin() const { return Iterateur(elements_); }
  Iterateur end() const { return Iterateur(elements_+taille_); }

  int getTaille() const { return taille_; }
  int getCapacite() const { return capacite_; }

  int operator[](int i) const { return elements_[i]; }
  int & operator[](int i) { return elements_[i]; }
 //------------------------------------------------------------------------------------Constructeurs
 public:
  explicit Vecteur(int c = 100) : elements_(new int[c]),taille_(0),capacite_(c) {}
  Vecteur(const Vecteur & v) : elements_(0),taille_(0),capacite_(0) { copier(v); }
 //---------------------------------------------------------------------------------Methodes privees
 private:
  void copier(const Vecteur & v);
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  Vecteur & operator=(const Vecteur & v) { copier(v); return (*this); }

  void ajouter(int);
  void retirer() { if (taille_>0) --taille_; }

  ~Vecteur() { delete[] elements_; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
