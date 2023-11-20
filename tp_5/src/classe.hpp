#pragma once
#include <iostream>

class Classe
{
private:
    double min, max;
    unsigned int qty = 0;

public:
    Classe(double a, double b)
    {
        if (a < b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
    }
    ~Classe() = default;

    double getBorneInf() const
    {
        return min;
    }

    double getBorneSup() const
    {
        return max;
    }

    unsigned int getQuantite() const
    {
        return qty;
    }

    void setBorneInf(double x)
    {
        min = x;
    }

    void setBorneSup(double x)
    {
        max = x;
    }

    void setQuantite(unsigned int n)
    {
        qty = n;
    }

    void ajouter()
    {
        qty++;
    }

    bool operator<(const Classe &c) const
    {
        return min < c.min;
    }

    bool operator>(const Classe &c) const
    {
        return max > c.max;
    }

    friend std::ostream &operator<<(std::ostream &os, const Classe &c)
    {
        os << "[" << c.min << ", " << c.max << "[ - qty:" << c.qty;
        return os;
    }
};

template <typename T>
class ComparateurQuantite
{
public:
    bool operator()(const Classe &c1, const Classe &c2) const
    {
        if(c1.getQuantite() > c2.getQuantite())
            return true;
        else if(c1.getQuantite() == c2.getQuantite())
            return c1 < c2;
        
        return false;
    }
};