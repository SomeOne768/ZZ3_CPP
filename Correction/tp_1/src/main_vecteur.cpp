// Entetes //---------------------------------------------------------------------------------------
#include <vecteur.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main() {
 Vecteur v(1);

 v.ajouter(45);
 std::cout << "capacite = " << v.getCapacite() << std::endl;
 v.ajouter(90);
 std::cout << "capacite = " << v.getCapacite() << std::endl;
 v.ajouter(135);
 std::cout << "capacite = " << v.getCapacite() << std::endl;
 v.ajouter(180);
 std::cout << "capacite = " << v.getCapacite() << std::endl;

 std::cout << std::endl;
 std::cout << "vecteur = " << v << std::endl;

 std::cout << "vecteur = ";
 for (int i=0; i<v.getTaille(); ++i) std::cout << v[i] << " ";
 std::cout << std::endl;

 v[1]=91;
 std::cout << std::endl;
 std::cout << "vecteur = " << v << std::endl;

 v.retirer();
 std::cout << "vecteur = " << v << std::endl;

 Vecteur v2 = v;

 std::cout << std::endl;
 std::cout << "copie = " << v2 << std::endl;
 std::cout << "capacite = " << v2.getCapacite() << std::endl;

 Vecteur v3(3);
 Vecteur v4(3);

 v3.ajouter(1); v3.ajouter(2); v3.ajouter(3);
 v4.ajouter(4); v4.ajouter(5); v4.ajouter(6);

 std::cout << std::endl;
 std::cout << "concatenation = " << (v3+v4) << std::endl;
 std::cout << "scalaire = " << (v3*v4) << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
