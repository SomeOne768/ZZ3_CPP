#include "Cartesien.hpp"
#include "Polaire.hpp"
#include <cmath>

Cartesien::Cartesien(double x, double y) : _x(x), _y(y)
{
}

Cartesien::Cartesien(): Cartesien(0, 0)
{
}

Cartesien::Cartesien(const Polaire &p)
{
    double  x = p.getDistance() * cos(p.getAngle() * M_PI / 180),
            y = p.getDistance() * sin(p.getAngle() * M_PI / 180);
    
    _x = x;
    _y = y;
}


std::ostream& Cartesien::afficher(std::ostream &os) const {
    os << "(x=" << _x << ";y=" << _y << ")";
    return os;
}

double Cartesien::getX() const
{
    return _x;
}

double Cartesien::getY() const
{
    return _y;
}


void Cartesien::setX(double x)
{
    this->_x = x;
}

void Cartesien::setY(double y)
{
    this->_y = y;
}


void Cartesien::convertir(Polaire &p) const
{
    // float theta = acos( x / (y*y + x*x) );
    double distance = sqrt(_y*_y + _x*_x);
    double theta = atan( _y / _x ) * 180 / M_PI;
    
    p.setAngle(theta);
    p.setDistance(distance); 
}

void Cartesien::convertir(Cartesien &c) const
{
    c.setX(_x);
    c.setY(_y);
}

void Cartesien::convertir(Point &p) const
{
    
}