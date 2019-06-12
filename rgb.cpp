#include "rgb.h"
#include <math.h>

const float TOL = 1e-6;
bool isZero(float val, float tol = TOL)
{
    return fabs(val - TOL) < 0.0f;
}

rgb::rgb():_r(0), _g(0), _b(0)
{}

rgb::rgb(float red, float green, float blue):_r(red), _g(green), _b(blue)
{
    clamp();
}

rgb::rgb(const rgb & original):_r(original.r()), _g(original.g()), _b(original.b())
{}

void rgb::setRed(float red)
{
    _r = red;
}

void rgb::setGreen(float green)
{
    _g = green;
}

void rgb::setBlue(float blue)
{
    _b = blue;
}

rgb& rgb::operator=(const rgb & rightOp)
{
    _r = rightOp.r();
    _g = rightOp.g();
    _b = rightOp.b();
    return *this;
}

rgb& rgb::operator+=(const rgb & rightOp)
{
    _r += rightOp.r();
    _g += rightOp.g();
    _b += rightOp.b();
    return *this;
}

rgb& rgb::operator*=(const rgb & rightOp)
{
    _r *= rightOp.r();
    _g *= rightOp.g();
    _b *= rightOp.b();
    return *this;
}

rgb& rgb::operator/=(const rgb & rightOp)
{
    if (!isZero(rightOp.r()))
    {
        _r /= rightOp.r();
    }
    if (!isZero(rightOp.g()))
    {
        _g /= rightOp.g();
    }
    if (!isZero(rightOp.b()))
    {
        _b /= rightOp.b();
    }
    return *this;
}

rgb& rgb::operator*=(float rightOp)
{
    _r *= rightOp;
    _g *= rightOp;
    _b *= rightOp;
    return *this;
}

rgb& rgb::operator/=(float rightOp)
{
    if (!isZero(rightOp))
    {
        _r /= rightOp;
        _g /= rightOp;
        _b /= rightOp;
    }
    return *this;
}

rgb rgb::operator+() const
{
    return *this;
}

rgb rgb::operator-() const
{
    return rgb(-_r, -_g, -_b);
}

float rgb::r() const
{
    return _r;
}

float rgb::g() const
{
    return _g;
}

float rgb::b() const
{
    return _b;
}

void rgb::clamp()
{
    if (_r - 1.0f > TOL)
    {
        _r = 1.0f;
    }
    if (_g - 1.0f > TOL)
    {
        _g = 1.0f;
    }
    if (_b - 1.0f > TOL)
    {
        _b = 1.0f;
    }
    
    if (_r < TOL)
    {
        _r = 0.0f;
    }
    if (_g < TOL)
    {
        _g = 0.0f;
    }
    if (_b < TOL)
    {
        _b = 0.0f;
    }
}

std::ostream& operator<<(std::ostream & out, const rgb & theRgb)
{
    out << theRgb.r() << ' ' << theRgb.g() << ' ' << theRgb.b() << ' ';
    return out;
}

rgb operator*(const rgb & rgbOp, float val)
{
    return rgb(rgbOp.r()*val, rgbOp.g()*val, rgbOp.b()*val);
}

rgb operator*(float val, const rgb & rgbOp)
{
    return rgb(rgbOp.r()*val, rgbOp.g()*val, rgbOp.b()*val);
}

rgb operator/(const rgb & rgbOp, float val)
{
    if (!isZero(val))
    {
        return rgb(rgbOp.r()/val, rgbOp.g()/val, rgbOp.b()/val);
    }
    return rgbOp;
}

rgb operator*(const rgb & c1, const rgb & c2)
{
    return rgb(c1.r()*c2.r(), c1.g()*c2.g(), c1.b()*c2.b());
}

rgb operator/(const rgb & c1, const rgb & c2)
{
    float valR = isZero(c2.r()) ? c1.r() : c1.r()/c2.r();
    float valG = isZero(c2.g()) ? c1.g() : c1.g()/c2.g();
    float valB = isZero(c2.b()) ? c1.b() : c1.b()/c2.b();
    return rgb(valR, valG, valB);
}

rgb operator+(const rgb & c1, const rgb & c2)
{
    return rgb(c1.r()+c2.r(), c1.g()+c2.g(), c1.b()+c2.b());
}