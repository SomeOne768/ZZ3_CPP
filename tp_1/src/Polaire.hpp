#ifndef POLAIRE_AZ_2023ZZ3
#define POLAIRE_AZ_2023ZZ3
#include "Point.hpp"

class Polaire : public Point {
    double _rayon;
    double _theta;

public:
    Polaire();
    Polaire(double r, double theta);
    double getAngle() const;
    double getDistance() const;
    void setAngle(double);
    void setDistance(double);
    virtual std::ostream& afficher(std::ostream&) const;   
};

#endif