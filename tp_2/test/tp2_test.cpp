// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"
#include <cmath>
#include <Nuage.hpp>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE("TP2_Nuage::Ajout")
{
   Nuage<Cartesien> n;

   REQUIRE(n.size() == 0u);

   n.ajouter(Cartesien(12, 34));
   n.ajouter(Cartesien(56, 78));
   n.ajouter(Cartesien(90, 12));
   n.ajouter(Cartesien(34, 56));

   REQUIRE(n.size() == 4u);
}

//------------------------------------------------------------------------------------------------ 2
TEST_CASE("TP2_Nuage::Iterateurs")
{
    Polaire p1(12,34);
    Polaire p2(56,78);
    Polaire p3(90,12);
    Polaire p4(34,56);

    Nuage<Polaire> n;

    n.ajouter(p1);
    n.ajouter(p2);
    n.ajouter(p3);
    n.ajouter(p4);

    Polaire t[4];
    unsigned i = 0;
    Nuage<Polaire>::const_iterator it = n.begin();
    while (it!=n.end()) t[i++]=*(it++);

    REQUIRE ( t[0].getAngle() == Approx(p1.getAngle()) );
    REQUIRE ( t[0].getDistance() == Approx(p1.getDistance()) );
    REQUIRE ( t[1].getAngle() == Approx(p2.getAngle()) );
    REQUIRE ( t[1].getDistance() == Approx(p2.getDistance()) );
    REQUIRE ( t[2].getAngle() == Approx(p3.getAngle()) );
    REQUIRE ( t[2].getDistance() == Approx(p3.getDistance()) );
    REQUIRE ( t[3].getAngle() == Approx(p4.getAngle()) );
    REQUIRE ( t[3].getDistance() == Approx(p4.getDistance()) );
}

//------------------------------------------------------------------------------------------------ 3
TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V1" ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v1(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v1(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v1(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}

//----------------------------------------------------------------------------------------------- 4a
// TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
//  Nuage<Polaire> n;

//  Polaire p1(12,34);
//  Polaire p2(56,78);
//  Polaire p3(90,12);
//  Polaire p4(34,56);

//  Polaire b1 = barycentre_v1(n);

//  REQUIRE ( b1.getAngle() == Approx(0.0) );
//  REQUIRE ( b1.getDistance() == Approx(0.0) );

//  n.ajouter(p1);

//  Polaire b2 = barycentre_v1(n);

//  REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
//  REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

//  n.ajouter(p2);
//  n.ajouter(p3);
//  n.ajouter(p4);

//  Polaire b3 = barycentre_v1(n);

//  REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
//  REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
// }

//----------------------------------------------------------------------------------------------- 4b
TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
 Nuage<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v1(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.ajouter(p1);

 Polaire b2 = barycentre_v1(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire b3 = barycentre_v1(n);

 REQUIRE ( b3.getAngle() == Approx((p1.getAngle()+p2.getAngle()
                                   +p3.getAngle()+p4.getAngle())/4) );

 REQUIRE ( b3.getDistance() == Approx((p1.getDistance()+p2.getDistance()
                                      +p3.getDistance()+p4.getDistance())/4) );
}

//------------------------------------------------------------------------------------------------ 5
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V2" ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 6
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesienVecteur" ) {
 std::vector<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.push_back(p1);

 Cartesien b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Cartesien b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 7
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V2" ) {
 std::vector<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v2(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.push_back(p1);

 Polaire b2 = barycentre_v2(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Polaire b3 = barycentre_v2(n);

 REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
 REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
}*/

// Fin //-------------------------------------------------------------------------------------------
