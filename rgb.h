#ifndef _RGB_H_
#define _RGB_H_ 1

#include <iostream>

class rgb{
public:
    rgb();
    rgb(float red, float green, float blue);
    rgb(const rgb & original);

    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);

    //no clamping
    rgb& operator=(const rgb & rightOp);
    rgb& operator+=(const rgb & rightOp);
    rgb& operator*=(const rgb & rightOp);
    rgb& operator/=(const rgb & rightOp);
    rgb& operator*=(float rightOp);
    rgb& operator/=(float rightOp);

    rgb operator+() const;
    rgb operator-() const;

    float r() const;
    float g() const;
    float b() const;

    void clamp();

    friend std::ostream& operator<<(std::ostream & out, const rgb & theRgb);
    friend rgb operator*(const rgb & rgbOp, float val);
    friend rgb operator*(float val, const rgb & rgbOp);
    friend rgb operator/(const rgb & rgbOp, float val);
    friend rgb operator*(const rgb & c1, const rgb & c2);
    friend rgb operator/(const rgb & c1, const rgb & c2);
    friend rgb operator+(const rgb & c1, const rgb & c2);
    
public:
    float _r;
    float _g;
    float _b;
};

#endif