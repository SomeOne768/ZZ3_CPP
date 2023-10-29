#pragma once


/***************** VERSION INLINE *****************/
template <int N> inline int Factorielle(void)
{
    return N * Factorielle<N-1>();
}


template <> inline int Factorielle<0>(void)
{
    return 1;
}
/**************************************************/