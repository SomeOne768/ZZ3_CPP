// Gardien //---------------------------------------------------------------------------------------
#ifndef _CLASSE_HPP_
#define _CLASSE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>

// Classe  C l a s s e //---------------------------------------------------------------------------
class Classe {
 //----------------------------------------------------------------------------------------Attributs
 private:
  double   borneInf_;
  double   borneSup_;
  unsigned quantite_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  double getBorneInf() const { return borneInf_; }
  double getBorneSup() const { return borneSup_; }
  double getQuantite() const { return quantite_; }

  void setBorneInf(double borne) { borneInf_=borne; }
  void setBorneSup(double borne) { borneSup_=borne; }
  void setQuantite(double quantite) { quantite_=quantite; }
 //------------------------------------------------------------------------------------Constructeurs
 public:
  Classe(double borneInf = 0.0,double borneSup = 0.0)
  : borneInf_(borneInf),borneSup_(borneSup),quantite_(0) {}
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void ajouter() { ++quantite_; }
};

// Fonctions inline //------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------operator <
inline bool operator < (const Classe & classe1,const Classe & classe2) {
 return (classe1.getBorneInf() < classe2.getBorneInf());
}

//----------------------------------------------------------------------------------------operator >
inline bool operator > (const Classe & classe1,const Classe & classe2) {
 return (classe2<classe1);
}

//---------------------------------------------------------------------------------------operator <<
inline std::ostream & operator << (std::ostream & flux,const Classe & classe) {
 flux << "[" << classe.getBorneInf() << ";" << classe.getBorneSup() << "]";
 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
#endif
