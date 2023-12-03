// Entetes //---------------------------------------------------------------------------------------
#include <paquet.hpp>

// Fonctions //-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------Remplir
void remplir(paquet_t & paquet,UsineCarte & usine) {
 std::unique_ptr<Carte> carte;

 while (carte=usine.getCarte()) // Operation de mouvement automatique
  paquet.push_back(std::move(carte)); // Forcer l'operation de mouvement
}

//--------------------------------------------------------------------------------------Operateur <<
std::ostream & operator<<(std::ostream & flux,const paquet_t & paquet) {
 // Version 1: parcours classique avec iterateurs
 // for (paquet_t::const_iterator it = paquet.begin(); it != paquet.end(); ++it)
 //  flux << (*it)->getValeur() << " ";

 // Version 2: parcours avec boucle for simplifiee
 for (const std::unique_ptr<Carte> & carte : paquet) flux << carte->getValeur() << " ";

 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
