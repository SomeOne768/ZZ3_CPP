#pragma once
#include <Puissance.hpp>
#include <Factorielle.hpp>

/***************** VERSION INLINE *****************/
// template <int N>
// double inline Exponentielle(double x)
// {
//     return Puissance<N>::valeur(x) / Factorielle<N>::valeur + Exponentielle<N-1>(x);
// }

// template<>
// double inline Exponentielle<0>(double x)
// {
//     (void) x;
//     return 1;
// }
/**************************************************/

/***************** VERSION STRUCT *****************/
// template <int N>
// struct Exponentielle
// {
//     static double valeur(double x)
//     {
//         return Puissance<N>::valeur(x) / Factorielle<N>::valeur + Exponentielle<N - 1>::valeur(x);
//     }
// };

// template<>
// struct Exponentielle<0>
// {
//     static double valeur(double x)
//     {
//         (void) x;
//         return 1;
//     }
// };
/**************************************************/

/***************** VERSION CLASSE *****************/
template <int N>
class Exponentielle
{
public:
    static double valeur(double x)
    {
        return Puissance<N>::valeur(x) / Factorielle<N>::valeur + Exponentielle<N - 1>::valeur(x);
    }
};

template <>
class Exponentielle<0>
{
public:
    static double valeur(double x)
    {
        (void)x;
        return 1;
    }
};
/**************************************************/