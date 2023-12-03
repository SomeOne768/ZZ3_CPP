// Entetes //---------------------------------------------------------------------------------------
#include <cmath>
#include <cartesien.hpp>
#include <polaire.hpp>

// Implementation  C a r t e s i e n //-------------------------------------------------------------

//--------------------------------------------------------------------------------------Constructeur
Cartesien::Cartesien(const Polaire & polaire) { polaire.convertir(*this); }

//------------------------------------------------------------------------------------------Afficher
void Cartesien::afficher(std::ostream & flux) const
{ flux << "(x=" << x_ << ";y=" << y_ << ")"; }

//-------------------------------------------------------------------------------------------Charger
void Cartesien::charger(std::istream & flux) {
 flux >> x_;
 flux >> y_;
}

//-----------------------------------------------------------------------------------------Convertir
void Cartesien::convertir(Cartesien & cartesien) const {
 cartesien.x_=x_;
 cartesien.y_=y_;
}

//-----------------------------------------------------------------------------------------Convertir
void Cartesien::convertir(Polaire & polaire) const {
 double distance = std::sqrt(x_*x_+y_*y_);
 double angle;

 if (distance==0) angle=0;

 if (x_==0) {
  if (y_<0) angle=-PI;
  else angle=PI;
 }
 else {
  if (x_>0) angle=std::atan(y_/x_);
  else if (x_<0 && y_>=0) angle=std::atan(y_/x_)+PI;
  else angle=std::atan(y_/x_)-PI;
 }

 polaire.setDistance(distance);
 polaire.setAngle(180.0*angle/PI);
}

// Fin //-------------------------------------------------------------------------------------------
