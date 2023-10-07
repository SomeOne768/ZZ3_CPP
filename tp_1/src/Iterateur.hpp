#ifndef ITERATEUR_AZ_2023ZZ3
#define ITERATEUR_AZ_2023ZZ3

template <typename T>
class Vecteur; // Déclaration anticipée de la classe Vecteur

template <typename T>
class Iterateur {
    friend class Vecteur<T>;
    T* it;

public:
    Iterateur(T* ptr);
    ~Iterateur();
    T operator*();
    Iterateur<T> operator++(int);
    Iterateur<T>& operator++();
    bool operator==(const Iterateur<T>&) const;


};

#include "Iterateur.code.hpp"

#endif