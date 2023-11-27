// Entetes //---------------------------------------------------------------------------------------
#include <nombre.hpp>

// Variables globales //----------------------------------------------------------------------------
unsigned compteur = 0;

// Fonction principale //---------------------------------------------------------------------------
int main() {
 const unsigned taille = 24;

 std::vector<Nombre> a(taille);
 std::vector<Nombre> b(taille);
 std::vector<Nombre> c(taille);

 for (unsigned i = 0; i<taille; ++i) a[i] = ++compteur;
 for (unsigned i = 0; i<taille; ++i) b[i] = ++compteur;

 std::cout << "a = " << a << std::endl;
 std::cout << "b = " << b << std::endl;
 std::cout << "compteur = " << compteur << std::endl;

 for (unsigned i = 0; i<taille; ++i) c[i] = a[i]*b[i];

 std::cout << "c = " << c << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
