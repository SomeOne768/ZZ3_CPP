// Gardien //---------------------------------------------------------------------------------------
#ifndef _CARTE_HPP_
#define _CARTE_HPP_

// Declarations anticipees //-----------------------------------------------------------------------
class UsineCarte;

// Classe  C a r t e //-----------------------------------------------------------------------------
class Carte {
 //---------------------------------------------------------------------------------------------Amis
 friend UsineCarte;

 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned valeur_;

  static unsigned compteur_;

 //---------------------------------------------------------------------------------------Accesseurs
 public:
  unsigned getValeur() const { return valeur_; }

  static unsigned getCompteur() { return compteur_; }

 //---------------------------------------------------------------------Constructeurs & Affectations
 private:
  Carte(unsigned valeur) : valeur_(valeur) { ++compteur_; }

 public:
  Carte(const Carte &) = delete;

  Carte & operator=(const Carte &) = delete;

 //--------------------------------------------------------------------------------------Destructeur
 public:
  ~Carte() { --compteur_; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
