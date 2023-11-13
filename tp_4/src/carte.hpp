#pragma once

class UsineCarte;

class Carte
{
    friend UsineCarte;
    unsigned int value;
    Carte(unsigned int);
public:
    ~Carte() = default;
    Carte(Carte&) = delete;
    auto operator=(Carte&) = delete;

    unsigned int getValeur() const;
};