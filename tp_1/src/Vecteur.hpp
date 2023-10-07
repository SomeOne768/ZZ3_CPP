#ifndef VECTEUR_AZ_2023ZZ3
#define VECTEUR_AZ_2023ZZ3
#include <iostream>
#include "Iterateur.hpp"

template <typename T>
class Vecteur{

    T *tab;
    unsigned int _taille;
public:
    Vecteur();
    ~Vecteur();
    Vecteur(const Vecteur<T>&);
    Vecteur<T>& operator=(const Vecteur<T>&);
    unsigned int size() const;
    // void add(T);
    void increaseTab(unsigned int);

    const T& operator[](unsigned int) const;
    T& operator[](unsigned int);
    std::ostream& operator<<(std::ostream &oss);
    Vecteur<T>& operator+(const Vecteur<T>v);
    T operator*(const Vecteur<T> &v);

    Iterateur<T> begin();
    Iterateur<T> end();
};

#include "Vecteur.code.hpp"

#endif