#include "RNG.h"

RNG::RNG(unsigned long long seed)
    : _seed(seed)
    , _mult(62089911ULL)
    , _llong_max(4294967295ULL)
    , _float_max(4294967295.0f)
{
}

float RNG::operator()()
{
    _seed = _mult * _seed;
    return float(_seed % _llong_max) / _float_max;
}
