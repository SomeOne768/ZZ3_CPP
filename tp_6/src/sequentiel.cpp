// Entetes //---------------------------------------------------------------------------------------
#include <nombre.hpp>

// Variables globales //----------------------------------------------------------------------------
unsigned compteur = 0;

template <typename Callable>
void for_sequentiel(int x, int y, Callable c)
{
    for (auto i = x; i < y; i++)
    {
        c(i);
    }
}

// Fonction principale //---------------------------------------------------------------------------
int main()
{
    const unsigned taille = 24;

    std::vector<Nombre> a(taille);
    std::vector<Nombre> b(taille);
    std::vector<Nombre> c(taille);

    for_sequentiel(0, taille, [&](unsigned i)
                   { a[i] = ++compteur; });
    for_sequentiel(0, taille, [&](unsigned i)
                   { b[i] = ++compteur; });

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "compteur = " << compteur << std::endl;

    for_sequentiel(0, taille, [&](unsigned i)
                   { a[i] = c[i] = a[i] * b[i]; });

    std::cout << "c = " << c << std::endl;

    return 0;
}

// Fin //-------------------------------------------------------------------------------------------
