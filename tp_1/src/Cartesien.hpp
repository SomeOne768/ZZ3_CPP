#ifndef CARTESIEN_AZ_2023ZZ3
#define CARTESIEN_AZ_2023ZZ3
#include "Point.hpp"

class Cartesien : public Point{
    
    double x, y;

public:
    Cartesien();
    Cartesien(double, double);
    virtual std::ostream& afficher(std::ostream&) const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);

};

#endif