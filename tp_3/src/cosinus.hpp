#pragma once
#include <Puissance.hpp>
#include <Factorielle.hpp>

/***************** VERSION INLINE *****************/

// template <int N>
// double inline Cosinus(double x)
// {
//     return ((N%2==0)? 1: -1) * Puissance<2*N>::valeur(x) / Factorielle<2*N>::valeur + Cosinus<N-1>(x);
// }

// template <>
// double inline Cosinus<0>(double x)
// {
//     (void) x;
//     return 1;
// }

/**************************************************/

/***************** VERSION STRUCT *****************/

// template <int N>
// struct Cosinus
// {
//     static double valeur(double x)
//     {
//         return ((N % 2 == 0) ? 1 : -1) * Puissance<2*N>::valeur(x) / Factorielle<2*N>::valeur + Cosinus<N-1>::valeur(x);
//     }
// };

// template <>
// struct Cosinus<0>
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
class Cosinus
{
public:
    static double valeur(double x)
    {
        return ((N % 2 == 0) ? 1 : -1) * Puissance<2 * N>::valeur(x) / Factorielle<2 * N>::valeur + Cosinus<N - 1>::valeur(x);
    }
};

template <>
class Cosinus<0>
{
public:
    static double valeur(double x)
    {
        (void)x;
        return 1;
    }
};

/**************************************************/