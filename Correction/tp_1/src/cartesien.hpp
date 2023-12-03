// Gardien //---------------------------------------------------------------------------------------
#ifndef CARTESIEN_HPP_e2de9d8bffa542748c65a181aaf7a778
#define CARTESIEN_HPP_e2de9d8bffa542748c65a181aaf7a778

// Entetes //---------------------------------------------------------------------------------------
#include <point.hpp>

// Classe  C a r t e s i e n //---------------------------------------------------------------------
class Cartesien : public Point {
 //----------------------------------------------------------------------------------------Attributs
 private:
  double x_;
  double y_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  double getX() const { return x_; }
  double getY() const { return y_; }

  void setX(double x) { x_=x; }
  void setY(double y) { y_=y; }
 //------------------------------------------------------------------------------------Constructeurs
 public:
  Cartesien() : x_(0.0),y_(0.0) {}
  Cartesien(double x,double y) : x_(x),y_(y) {}
  Cartesien(const Polaire &);
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void afficher(std::ostream &) const override;
  void charger(std::istream &) override;
  void convertir(Cartesien &) const override;
  void convertir(Polaire &) const override;
};

// Fin //-------------------------------------------------------------------------------------------
#endif
