#ifndef CARTESIEN_AZ_2023ZZ3
#define CARTESIEN_AZ_2023ZZ3
#include "Point.hpp"


class Polaire;

class Cartesien : public Point{
    
    double _x, _y;

public:
    virtual ~Cartesien(){};
    Cartesien();
    Cartesien(double, double);
    Cartesien(const Polaire &p);
    virtual std::ostream& afficher(std::ostream&) const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    virtual void convertir(Polaire &p) const;
    virtual void convertir(Cartesien &c) const;
    virtual void convertir(Point &p) const;
};

#endif