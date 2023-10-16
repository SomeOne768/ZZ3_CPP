#ifndef POLAIRE_AZ_2023ZZ3
#define POLAIRE_AZ_2023ZZ3
#include "Point.hpp"

class Cartesien;

class Polaire : public Point {
    double _theta; // Angle exprimé en degré non radiant
    double _rayon;

public:
    virtual ~Polaire(){};
    Polaire();
    Polaire(const Cartesien &c);
    Polaire(const Polaire &p);
    Polaire(double theta, double r);
    double getAngle() const;
    double getDistance() const;
    void setAngle(double);
    void setDistance(double);
    virtual std::ostream& afficher(std::ostream&) const;
    virtual void convertir(Cartesien &c) const;
    virtual void convertir(Polaire &p) const;
    Polaire& operator=(const Polaire *p);
    
};

#endif