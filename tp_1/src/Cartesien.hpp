#ifndef CARTESIEN_AZ_2023ZZ3
#define CARTESIEN_AZ_2023ZZ3
#include "Point.hpp"


class Polaire;

class Cartesien : public Point{
    
    double _x, _y;

public:
    Cartesien(); // Si on autorise x!= 0 et y=0 alors preferer val. par defaut dans l'autre constructeur
    Cartesien(double x, double y);
    Cartesien(const Polaire &p);
    std::ostream& afficher(std::ostream&) const override;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    virtual void convertir(Polaire &p) const;
    virtual void convertir(Cartesien &c) const;
    virtual void convertir(Point &p) const;
};

#endif