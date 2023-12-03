// Gardien //---------------------------------------------------------------------------------------
#ifndef _USINE_HPP_
#define _USINE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <memory>
#include <carte.hpp>

// Classe  U s i n e C a r t e //-------------------------------------------------------------------
class UsineCarte {
 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned compteur_;
  unsigned max_;

 //---------------------------------------------------------------------Constructeurs & Affectations
 public:
  UsineCarte(unsigned max = 52) : compteur_(),max_(max) {}

  UsineCarte(const UsineCarte &) = delete;

  UsineCarte & operator=(const UsineCarte &) = delete;

 //-------------------------------------------------------------------------------Methodes publiques
 public:
  std::unique_ptr<Carte> getCarte();
};

// Fin //-------------------------------------------------------------------------------------------
#endif
