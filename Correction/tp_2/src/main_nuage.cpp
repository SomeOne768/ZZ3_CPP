// Entetes //---------------------------------------------------------------------------------------
#include <nuage.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 Nuage<Cartesien> n1;
 Nuage<Polaire> n2;

 n1.ajouter(Cartesien(12,34));
 n1.ajouter(Cartesien(56,78));
 n1.ajouter(Cartesien(90,12));
 n1.ajouter(Cartesien(34,56));

 n2.ajouter(Cartesien(45,45));
 n2.ajouter(Cartesien(0,90));
 n2.ajouter(Cartesien(45,135));
 n2.ajouter(Cartesien(35,90));

 std::cout << "barycentre1(nuage1) = " << barycentre_v1(n1) << std::endl;
 std::cout << "barycentre1(nuage2) = " << barycentre_v1(n2) << std::endl;
 std::cout << "barycentre2(nuage1) = " << barycentre_v2(n1) << std::endl;
 std::cout << "barycentre2(nuage2) = " << barycentre_v2(n2) << std::endl;

 std::vector<Cartesien> v;

 v.push_back(Cartesien(12,34));
 v.push_back(Cartesien(56,78));
 v.push_back(Cartesien(90,12));
 v.push_back(Cartesien(34,56));

 std::cout << "barycentre2(vecteur) = " << barycentre_v2(v) << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
