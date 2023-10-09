#ifndef POLAIRE_AZ_2023ZZ3
#define POLAIRE_AZ_2023ZZ3
#include "Point.hpp"

class Cartesien;

class Polaire : public Point {
    double _theta; // Angle exprimé en degré non radiant
    double _rayon;

public:
    Polaire(); // Si on autorise theta != 0 et r=0 alors preferer val. par defaut dans l'autre constructeur
    Polaire(const Cartesien &c);
    Polaire(double theta, double r);
    double getAngle() const;
    double getDistance() const;
    void setAngle(double);
    void setDistance(double);
    std::ostream& afficher(std::ostream&) const override;
    virtual void convertir(Cartesien &c) const;
    virtual void convertir(Polaire &p) const;
};

#endif