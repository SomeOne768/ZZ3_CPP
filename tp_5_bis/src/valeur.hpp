#ifndef __VALEUR_HPP__
#define __VALEUR_HPP__
#include <string>

class Valeur
{

    double _value;
    std::string name;

public:
    Valeur(const double a = 0, std::string s = "inconnu") : _value(a), name(s) {}

    double getNombre() const { return _value; }
    void setNombre(const double a) { _value = a; }
    bool operator<(const Valeur &v) const
    {
        return _value < v._value;
    }

    double getNote() const
    {
        return _value;
    }

    const std::string &getEtudiant() const
    {
        return name;
    }

    void setNote(double n)
    {
        _value = n;
    }
    
    void setEtudiant(std::string s)
    {
        name = s;
    }
};

#endif