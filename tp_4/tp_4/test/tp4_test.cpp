// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <sstream>
#include <type_traits>

//#include <carte.hpp>
//#include <usine.hpp>
//#include <paquet.hpp>
//#include <ressource.hpp>
//#include <consommateur.hpp>

// Tests //-----------------------------------------------------------------------------------------

template <typename T,typename = void> struct has_public_constructor : std::false_type {};

template <typename T>
struct has_public_constructor< T,
                               std::enable_if_t<std::is_same<T,decltype(T(1))>::value>
                             > : std::true_type {};

//------------------------------------------------------------------------------------------------ 1
/*TEST_CASE ( "TP4_Carte::Usine52" ) {
 UsineCarte usine;

 for (unsigned i = 0; i<52; ++i) {
  std::unique_ptr<Carte> carte(usine.getCarte());

  REQUIRE ( carte->getValeur() == i );
 }

 REQUIRE ( usine.getCarte() == nullptr );
}*/

//------------------------------------------------------------------------------------------------ 2
/*TEST_CASE ( "TP4_Carte::CarteInterface" ) {
 // Contructeur de copie existe ?
 REQUIRE ( std::is_copy_constructible<Carte>::value == false );

 // Operateur d'affectation par copie existe ?
 REQUIRE ( std::is_copy_assignable<Carte>::value == false );

 // Constructeur ad hoc existe ?
 REQUIRE ( has_public_constructor<Carte>::value == false );
}*/

//------------------------------------------------------------------------------------------------ 3
/*TEST_CASE ( "TP4_Carte::UsineInterface" ) {
 // Contructeur de copie existe ?
 REQUIRE ( std::is_copy_constructible<UsineCarte>::value == false );

 // Operateur d'affectation par copie existe ?
 REQUIRE ( std::is_copy_assignable<UsineCarte>::value == false );
}*/

//------------------------------------------------------------------------------------------------ 4
/*TEST_CASE ( "TP4_Carte::UsineN" ) {
 const unsigned n = 32;

 UsineCarte usine(n);

 for (unsigned i = 0; i<n; ++i) {
  std::unique_ptr<Carte> carte(usine.getCarte());

  REQUIRE ( carte->getValeur() == i );
 }

 REQUIRE ( usine.getCarte() == nullptr );
}*/

//------------------------------------------------------------------------------------------------ 5
/*TEST_CASE ( "TP4_Carte::PaquetRemplir" ) {
 const unsigned n = 27;

 paquet_t paquet;
 UsineCarte usine(n);

 remplir(paquet,usine);

 for (unsigned i = 0; i<n; ++i) {
  REQUIRE ( paquet[i]->getValeur() == i );
 }
}*/

//------------------------------------------------------------------------------------------------ 6
/*TEST_CASE ( "TP4_Carte::PaquetFlux" ) {
 const unsigned n = 27;

 paquet_t paquet;
 UsineCarte usine(n);

 remplir(paquet,usine);

 std::stringstream s1;

 s1 << paquet;

 std::stringstream s2;

 for (unsigned i = 0; i<n; ++i) s2 << paquet[i]->getValeur() << " ";

 REQUIRE (s1.str() == s2.str());
}*/

//------------------------------------------------------------------------------------------------ 7
/*TEST_CASE ( "TP4_Carte::CarteDestruction" ) {
 REQUIRE ( Carte::getCompteur() == 0 );

 {
  const unsigned n = 52;

  UsineCarte usine(n);
  paquet_t paquet;

  REQUIRE ( Carte::getCompteur() == 0 );

  remplir(paquet,usine);

  REQUIRE ( Carte::getCompteur() == n );

  std::cout << paquet << std::endl;

  REQUIRE ( Carte::getCompteur() == n );
 }

 REQUIRE ( Carte::getCompteur() == 0 );
}*/

//------------------------------------------------------------------------------------------------ 8
/*TEST_CASE ( "TP4_Conso::Ressource" ) {
 Ressource r(17);

 REQUIRE ( r.getStock() == 17 );

 r.consommer(6);

 REQUIRE ( r.getStock() == 11 );
}*/

//------------------------------------------------------------------------------------------------ 9
/*TEST_CASE ( "TP4_Conso::Consommateur" ) {
 // std::shared_ptr<Ressource> r(new Ressource(17));
 auto r = std::make_shared<Ressource>(17);
 Consommateur c(3,r);

 REQUIRE ( r->getStock() == 17 );

 c.puiser();

 REQUIRE ( r->getStock() == 14 );
}*/

//----------------------------------------------------------------------------------------------- 10
/*TEST_CASE ( "TP4_Conso::RessoureEpuisee" ) {
 // std::shared_ptr<Ressource> r(new Ressource(5));
 auto r = std::make_shared<Ressource>(5);
 Consommateur c(3,r);

 REQUIRE ( r->getStock() == 5 );
 REQUIRE ( r.use_count() == 2 );

 c.puiser();

 REQUIRE ( r->getStock() == 2 );
 REQUIRE ( r.use_count() == 2 );

 c.puiser();

 REQUIRE ( r->getStock() == 0 );
 REQUIRE ( r.use_count() == 1 );
}*/

//----------------------------------------------------------------------------------------------- 11
/*TEST_CASE ( "TP4_Conso::SurveillanceRessources" ) {
 // std::shared_ptr<Ressource> r1(new Ressource(14));
 // std::shared_ptr<Ressource> r2(new Ressource(7));
 // std::shared_ptr<Ressource> r3(new Ressource(13));
 // std::shared_ptr<Ressource> r4(new Ressource(25));
 auto r1 = std::make_shared<Ressource>(14);
 auto r2 = std::make_shared<Ressource>(7);
 auto r3 = std::make_shared<Ressource>(13);
 auto r4 = std::make_shared<Ressource>(25);

 ressources_t ressources;

 ressources.push_back(r1);
 ressources.push_back(r2);
 ressources.push_back(r3);
 ressources.push_back(r4);

 std::vector<Consommateur> consommateurs;

 consommateurs.push_back(Consommateur(3,r1));
 consommateurs.push_back(Consommateur(2,r2));
 consommateurs.push_back(Consommateur(1,r1));
 consommateurs.push_back(Consommateur(4,r4));
 consommateurs.push_back(Consommateur(2,r3));
 consommateurs.push_back(Consommateur(2,r4));

 r1=nullptr;
 r2=nullptr;
 r3=nullptr;
 r4=nullptr;

 REQUIRE ( ressources[0].use_count() == 2 );
 REQUIRE ( ressources[1].use_count() == 1 );
 REQUIRE ( ressources[2].use_count() == 1 );
 REQUIRE ( ressources[3].use_count() == 2 );

 std::vector<std::string> etats = { "14 7 13 25 ",
                                    "10 5 11 19 ",
                                    "6 3 9 13 ",
                                    "2 1 7 7 ",
                                    "- - 5 1 ",
                                    "- - 3 - ",
                                    "- - 1 - ",
                                    "- - - - " };

 for (unsigned i = 0; i<etats.size(); ++i) {
  std::stringstream s;

  s << ressources;

  REQUIRE ( s.str() == etats[i] );

  for (unsigned j = 0; j<consommateurs.size(); ++j) consommateurs[j].puiser();
 }

 for (unsigned i = 0; i<4; ++i) {
  REQUIRE ( ressources[i].use_count() == 0 );
 }
}*/

// Fin //-------------------------------------------------------------------------------------------
