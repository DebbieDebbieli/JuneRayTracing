#ifndef _VECTOR3_H_
#define _VECTOR3_H_ 1

#include<iostream>

class Vector3
{
public:
    Vector3();
    Vector3(float e1, float e2, float e3);
    Vector3(const Vector3 & val);

    float x() const;
    float y() const;
    float z() const;

    const Vector3& operator+() const;
    Vector3 operator-() const;
    float operator[](int i) const;

    float length() const;
    float squaredLength() const;

    void makeUnitVector();

    void setX(float val);
    void setY(float val);
    void setZ(float val);
    float minComponent() const;
    float maxComponent() const;
    float maxAbsComponent() const;
    float minAbsComponent() const;
    int indexOfMinComponent() const;
    int indexOfMinAbsComponent() const;
    int indexOfMaxComponent() const;
    int indexOfMaxAbsComponent() const;

    friend bool operator==(const Vector3& v1, const Vector3& v2);
    friend bool operator!=(const Vector3& v1, const Vector3& v2);

    friend std::istream & operator>>(std::istream & is, Vector3& val);
    friend std::ostream & operator<<(std::ostream & os, const Vector3& val);

    friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
    friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
    friend Vector3 operator/(const Vector3& v1, float scalar);
    friend Vector3 operator*(const Vector3& vec, float scalar);
    friend Vector3 operator*(float scalar, const Vector3& vec);

    Vector3& operator=(const Vector3& vec);
    Vector3& operator+=(const Vector3& vec);
    Vector3& operator-=(const Vector3& vec);
    Vector3& operator*=(float val);
    Vector3& operator/(float val);

    friend Vector3 unitVector(const Vector3& vec);
    friend Vector3 minVec(const Vector3& v1, const Vector3& v2);
    friend Vector3 maxVec(const Vector3& v1, const Vector3& v2);
    friend Vector3 cross(const Vector3& v1, const Vector3& v2);
    friend float dot(const Vector3& v1, const Vector3& v2);
    friend float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3);

public:
    float _e[3];
};

#endif