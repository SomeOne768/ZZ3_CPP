#ifndef POINT_AZ_2023ZZ3
#define POINT_AZ_2023ZZ3
#include <iostream>


class Point{

public:
    virtual std::ostream& afficher(std::ostream&) const = 0;
    // friend void operator<<(std::ostream &os, const Point &p); 
    // {
    //      p.afficher(os);
    // }
};

#endif