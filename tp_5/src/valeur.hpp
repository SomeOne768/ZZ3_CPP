#pragma once
#include <string>

class Valeur
{
    double v;
    std::string name;

public:
    Valeur() : v(0), name("inconnu") {}
    Valeur(double x) : v(x) {}
    Valeur(double x, std::string s) : v(x), name(s) {}

    double getNombre() const
    {
        return v;
    }

    void setNombre(double x)
    {
        v = x;
    }

    bool operator<(const Valeur &v2) const
    {
        return v < v2.v;
    }

    const std::string& getEtudiant() const
    {
        return name;
    }

    double getNote() const
    {
        return v;
    }
    
    void setNote(double a)
    {
        v =a ;
    }
    
    void setEtudiant(std::string name)
    {
        this->name = name;
    }
};