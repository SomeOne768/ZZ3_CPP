#include "Cartesien.hpp"

Cartesien::Cartesien(double x, double y) : x(x), y(y)
{
}

Cartesien::Cartesien(): Cartesien(0, 0)
{
}

std::ostream& Cartesien::afficher(std::ostream &os) const {
    os << "(x=" << x << ";y=" << y << ")";
    return os;
}

double Cartesien::getX() const
{
    return x;
}

double Cartesien::getY() const
{
    return y;
}


void Cartesien::setX(double x)
{
    this->x = x;
}

void Cartesien::setY(double y)
{
    this->y = y;
}