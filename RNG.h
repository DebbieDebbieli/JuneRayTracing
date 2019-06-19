#ifndef _RNG_H_
#define _RNG_H_ 1

class RNG
{
public:
    RNG(unsigned long long seed = 7564321ULL);
    float operator()();

public:
    unsigned long long _seed;
    unsigned long long _mult;
    unsigned long long _llong_max;
    float _float_max;
};

#endif