#include <cstdlib>
#include "Vecteur.hpp"
#include <cstdio>
#include <iostream>
#include "Iterateur.hpp"

int main() {

    using T = int;
    Vecteur<T> v{}, v2{};

    for(auto i=0; i<10; i++)
    {
        v[i] = i;
        v2[i] = -i;
    }

    v = v + v2;
    std::cout << v;

    std::cout << "scalar: " << v*v2 << "\n";


    Iterateur<T> it = v.begin();
    it++;
    ++it;
    std::cout << "iterateur ok ?:" << *it << "\n";

    std::cout << (it == (++v.begin()++)) << std::endl;

 return EXIT_SUCCESS;
}
