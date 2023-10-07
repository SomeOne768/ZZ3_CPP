#ifndef ITERATEUR_CODE_AZ_2023ZZ3
#define ITERATEUR_CODE_AZ_2023ZZ3


template <typename T>
Iterateur<T>::Iterateur(T* ptr)
{
    it = ptr;
}

template <typename T>
Iterateur<T>::~Iterateur()
{
    it = nullptr;
}

template <typename T>
T Iterateur<T>::operator*()
{
    return *it;
}

template <typename T>
Iterateur<T> Iterateur<T>::operator++(int)
{
    it++;

    return *this;
}

template <typename T>
Iterateur<T>& Iterateur<T>::operator++()
{
    it++;

    return *this;
}

template <typename T>
bool Iterateur<T>::operator==(const Iterateur<T>& it) const
{
    return this->it == it.it;
}

#endif