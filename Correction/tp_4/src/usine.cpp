// Entetes //---------------------------------------------------------------------------------------
#include <usine.hpp>

// Implementation  U s i n e C a r t e //-----------------------------------------------------------

//------------------------------------------------------------------------------------------GetCarte
std::unique_ptr<Carte> UsineCarte::getCarte() {
 // Version 1
 // std::unique_ptr<Carte> carte;
 //
 // if (compteur_<max_) carte.reset(new Carte(compteur_++));
 //
 // return carte;

 // Version 2
 if (compteur_<max_) return std::unique_ptr<Carte>(new Carte(compteur_++));
 else return std::unique_ptr<Carte>();

 // Remarque: impossible d'utiliser "make_unique" car le constructeur de "Carte" est prive
}

// Fin //-------------------------------------------------------------------------------------------
