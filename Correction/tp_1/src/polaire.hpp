// Gardien //---------------------------------------------------------------------------------------
#ifndef POLAIRE_HPP_e2de9d8bffa542748c65a181aaf7a778
#define POLAIRE_HPP_e2de9d8bffa542748c65a181aaf7a778

// Entetes //---------------------------------------------------------------------------------------
#include <point.hpp>

// Constantes //------------------------------------------------------------------------------------
const double PI = 3.14159265359;

// Classe  P o l a i r e //-------------------------------------------------------------------------
class Polaire : public Point {
 //----------------------------------------------------------------------------------------Attributs
 private:
  double angle_; // en degres
  double distance_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  double getAngle() const { return angle_; }
  double getDistance() const { return distance_; }

  void setAngle(double angle) { angle_=angle; }
  void setDistance(double distance) { distance_=distance; }
 //------------------------------------------------------------------------------------Constructeurs
 public:
  Polaire() : angle_(0.0),distance_(0.0) {}
  Polaire(double angle,double distance) : angle_(angle),distance_(distance) {}
  Polaire(const Cartesien &);
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void afficher(std::ostream &) const override;
  void charger(std::istream &) override;
  void convertir(Cartesien &) const override;
  void convertir(Polaire &) const override;
};

// Fin //-------------------------------------------------------------------------------------------
#endif
