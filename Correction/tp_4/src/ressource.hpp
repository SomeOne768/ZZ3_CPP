// Gardien //---------------------------------------------------------------------------------------
#ifndef _RESSOURCE_HPP_
#define _RESSOURCE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <memory>

// Classe  R e s s o u r c e //---------------------------------------------------------------------
class Ressource {
 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned stock_;

 //---------------------------------------------------------------------------------------Accesseurs
 public:
  unsigned getStock() const { return stock_; }

 //------------------------------------------------------------------------------------Constructeurs
 public:
  Ressource(unsigned stock) : stock_(stock) {}

 //-------------------------------------------------------------------------------Méthodes publiques
 public:
  void consommer(unsigned quantite) { stock_ = (stock_<quantite ? 0 : stock_-quantite); }
};

// Declarations types //----------------------------------------------------------------------------
using ressources_t = std::vector<std::weak_ptr<Ressource>>;

// Declarations fonctions //------------------------------------------------------------------------
std::ostream & operator<<(std::ostream &,const ressources_t &);

// Fin //-------------------------------------------------------------------------------------------
#endif
