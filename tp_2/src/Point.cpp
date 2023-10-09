#include "Point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    return p.afficher(os);
}