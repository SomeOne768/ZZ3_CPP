// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <ressource.hpp>

// Fonctions //-------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------Operateur <<
std::ostream & operator<<(std::ostream & flux,const ressources_t & ressources) {
 for (const std::weak_ptr<Ressource> & ressource : ressources) {
  if (!ressource.expired())
   flux << (ressource.lock())->getStock() << " ";
  else
   flux << "- ";
 }

 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
