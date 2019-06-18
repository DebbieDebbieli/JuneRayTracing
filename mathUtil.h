#include <math.h>

static const float TOL = 1e-6;

static bool isZero(float val, float tol = TOL)
{
    return std::fabs(val - TOL) < 0.0f;
}