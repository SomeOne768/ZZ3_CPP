#ifndef POINT_AZ_2023ZZ3
#define POINT_AZ_2023ZZ3
#include <iostream>


class Cartesien;
class Polaire;

class Point{

public:
    virtual ~Point(){};
    virtual std::ostream& afficher(std::ostream&) const = 0;
    // friend void operator<<(std::ostream &os, const Point &p); 
    // {
    //      p.afficher(os);
    // }
    virtual void convertir(Cartesien &c) const = 0;
    virtual void convertir(Polaire &p) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif