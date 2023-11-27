#include <cstdlib>
#include <thread>
#include <vector>
#include "nombre.hpp"

unsigned compteur = 0;

// Thread 1 : for (unsigned i = 0; i<taille/4; ++i) a[i] = ++compteur;
// Thread 2 : for (unsigned i = taille/4; i<2*taille/4; ++i) a[i] = ++compteur;
// Thread 3 : for (unsigned i = 2*taille/4; i<3*taille/4; ++i) a[i] = ++compteur;
// Thread 4 (principal) : for (unsigned i = 3*taille/4; i<taille; ++i) a[i] = ++compteur;

template <typename Callable>
void for_sequentiel(int x, int y, Callable c)
{
    for (int i = x; i < y; i++)
    {
        c(i);
    }
}


template <int N,typename Callable>
void for_parallele(int debut, int fin, Callable c)
{
    std::thread t[N];
    int taille = fin-debut;
    for(int i=0; i<N; i++)
    {
        t[i] = std::thread(for_sequentiel<Callable>, i*taille/4, (i+1)*taille/4, c);
        // t[i] = std::thread([&](int debut, int fin, Callable c)
        //     {
        //         for(int i=debut; i<fin; i++)
        //             a[i] = ++compteur;                
        //     }            
        //     , debut + i*taille/4, debut + (i+1)*taille/4, c);
    }

    for(auto &thread : t)
        thread.join();
}

int main()
{
    const unsigned taille = 24;

    std::vector<Nombre> a(taille);
    std::vector<Nombre> b(taille);
    std::vector<Nombre> c(taille);

    for_parallele<4>(0, taille, [&](unsigned i){a[i] = ++compteur;});

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "compteur = " << compteur << std::endl;

    for_sequentiel(0, taille, [&](unsigned i)
                   { a[i] = c[i] = a[i] * b[i]; });

    std::cout << "c = " << c << std::endl;

    return EXIT_SUCCESS;
}
