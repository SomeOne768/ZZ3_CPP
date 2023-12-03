// Gardien //---------------------------------------------------------------------------------------
#ifndef _CONSOMMATEUR_HPP_
#define _CONSOMMATEUR_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <memory>
#include <ressource.hpp>

// Classe  C o n s o m m a t e u r //---------------------------------------------------------------
class Consommateur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned                   besoin_;
  std::shared_ptr<Ressource> ressource_;

 //------------------------------------------------------------------------------------Constructeurs
 public:
  Consommateur(unsigned besoin,std::shared_ptr<Ressource> ressource)
  : besoin_(besoin),ressource_(ressource) {}

 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void puiser() {
   if (ressource_) {
    ressource_->consommer(besoin_);

    if (ressource_->getStock()==0) ressource_=nullptr;
   }
  }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
