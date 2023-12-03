// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <comparateur.hpp>
#include <histogramme.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 using histo_tri_defaut_t   = Histogramme<>;
 using histo_tri_quantite_t = Histogramme<ComparateurQuantite<Classe>>;

 Echantillon ech;

 histo_tri_defaut_t h1(0.0,20.0,10);

 std::random_device                     dev;
 std::mt19937                           rng(dev());
 std::uniform_real_distribution<double> dist(0.0,20.0);

 // Remplissage direct
 // for (unsigned i = 0; i<20; ++i) {
 //  double val = dist(rng);
 //  ech.ajouter(Valeur(val));
 // }

 // Remplissage avec "std::generate_n"
 std::generate_n(std::back_inserter(ech),20,[&] () { return dist(rng); });

 std::cout << "Echantillon = " << ech << std::endl;

 h1.ajouter(ech);
 std::cout << std::endl << "Histogramme tri par defaut:" << std::endl << h1;

 histo_tri_quantite_t h2(h1);

 std::cout << std::endl << "Histogramme tri par quantite:" << std::endl << h2;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
