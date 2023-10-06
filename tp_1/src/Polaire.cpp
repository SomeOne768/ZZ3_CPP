#include "Polaire.hpp"

Polaire::Polaire(double r, double theta) : _rayon(r), _theta(theta)
{

}

Polaire::Polaire() : Polaire(0, 0)
{
}


double Polaire::getAngle() const
{
    return _theta;
}

double Polaire::getDistance() const
{
    return _rayon;
}

void Polaire::setAngle(double a)
{
    _theta = a;
}

void Polaire::setDistance(double r)
{
    _rayon = r;
}

std::ostream& Polaire::afficher(std::ostream &os) const {
    os << "(a=" << _theta << ";d=" << _rayon << ")";
    return os;
}