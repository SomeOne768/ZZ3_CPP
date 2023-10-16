#include "Polaire.hpp"
#include "Cartesien.hpp"
#include <cmath>

Polaire::Polaire(double theta, double r) : _theta(theta), _rayon(r)
{

}

Polaire::Polaire() : Polaire(0, 0)
{
}

Polaire::Polaire(const Cartesien &c)
{    
    _theta = c.getX() == 0? 0:atan(c.getY() / c.getX()) * 180 / M_PI;
    _rayon = sqrt(c.getX()*c.getX() + c.getY()*c.getY());
}


Polaire::Polaire(const Polaire &p) : _theta(p._theta), _rayon(p._rayon)
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

void Polaire::convertir(Cartesien &c) const
{
    double  x = _rayon * cos(_theta * M_PI / 180),
            y = _rayon * sin(_theta * M_PI / 180);
    
    c.setX(x);
    c.setY(y);
}


void Polaire::convertir(Polaire &p) const
{
    p.setAngle(_theta);
    p.setDistance(_rayon);
}


Polaire& Polaire::operator=(const Polaire *p)
{
    //V1
    *this = Polaire(*p);

    // V2
    // _rayon = p->_rayon;
    // _theta = p->_theta;

    return *this;
}

