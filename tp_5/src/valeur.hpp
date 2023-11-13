
#pragma once

class Valeur
{
    float v;

public:
    Valeur() : v(0) {}
    Valeur(float x) : v(x) {}

    float getNombre() const
    {
        return v;
    }

    void setNombre(float x)
    {
        v = x;
    }

    bool operator<(const Valeur &v2) const
    {
        return v < v2.v;
    }
};