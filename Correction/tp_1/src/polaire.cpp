// Entetes //---------------------------------------------------------------------------------------
#include <cmath>
#include <cartesien.hpp>
#include <polaire.hpp>

// Implementation  P o l a i r e //-----------------------------------------------------------------

//--------------------------------------------------------------------------------------Constructeur
Polaire::Polaire(const Cartesien & cartesien) { cartesien.convertir(*this); }

//------------------------------------------------------------------------------------------Afficher
void Polaire::afficher(std::ostream & flux) const
{ flux << "(a=" << angle_ << ";d=" << distance_ << ")"; }

//-------------------------------------------------------------------------------------------Charger
void Polaire::charger(std::istream & flux) {
 flux >> angle_;
 flux >> distance_;
}

//-----------------------------------------------------------------------------------------Convertir
void Polaire::convertir(Cartesien & cartesien) const {
 double angle = angle_*PI/180.;

 cartesien.setX(distance_*cos(angle));
 cartesien.setY(distance_*sin(angle));
}

//-----------------------------------------------------------------------------------------Convertir
void Polaire::convertir(Polaire & polaire) const {
 polaire.angle_=angle_;
 polaire.distance_=distance_;
}

// Fin //-------------------------------------------------------------------------------------------
