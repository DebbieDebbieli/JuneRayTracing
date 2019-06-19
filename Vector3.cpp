#include"Vector3.h"
#include<assert.h>
#include"mathUtil.h"

Vector3::Vector3()
{
    _e[0] = _e[1] = _e[2] = 0.0f;
}

Vector3::Vector3(float e1, float e2, float e3)
{
    _e[0] = e1;
    _e[1] = e2;
    _e[2] = e3;
}

Vector3::Vector3(const Vector3 & val)
{
    _e[0] = val.x();
    _e[1] = val.y();
    _e[2] = val.z();
}

float Vector3::x() const
{
    return _e[0];
}

float Vector3::y() const
{
    return _e[1];
}

float Vector3::z() const
{
    return _e[2];
}

const Vector3& Vector3::operator+() const
{
    return *this;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-_e[0], -_e[1], -_e[2]);
}

float Vector3::operator[](int i) const
{
    assert(i >=0 && i < 3);
    return _e[i];
}

float Vector3::length() const
{
    return sqrt(_e[0]*_e[0] + _e[1]*_e[1] + _e[2]*_e[2]);
}

float Vector3::squaredLength() const
{
    return _e[0]*_e[0] + _e[1]*_e[1] + _e[2]*_e[2];
}

void Vector3::makeUnitVector()
{
    float len = length();
    if (!isZero(len))
    {
        _e[0] /= len;
        _e[1] /= len;
        _e[2] /= len;
    }
}

void Vector3::setX(float val)
{
    _e[0] = val;
}

void Vector3::setY(float val)
{
    _e[1] = val;
}

void Vector3::setZ(float val)
{
    _e[2] = val;
}

float Vector3::minComponent() const
{
    float minCom = (_e[0] - _e[1] < TOL ? _e[0] : _e[1]);
    if (_e[2] - minCom < TOL)
    {
        minCom = _e[2];
    }
    return minCom;
}

float Vector3::maxComponent() const
{
    float maxCom = (_e[0] - _e[1] > TOL ? _e[0] : _e[1]);
    if (_e[2] - maxCom > TOL)
    {
        maxCom = _e[2];
    }
    return maxCom;
}

float Vector3::maxAbsComponent() const
{
    float maxCom = (fabs(_e[0]) - fabs(_e[1]) > TOL ? fabs(_e[0]) : fabs(_e[1]));
    if (fabs(_e[2]) - maxCom > TOL)
    {
        maxCom = fabs(_e[2]);
    }
    return maxCom;
}

float Vector3::minAbsComponent() const
{
    float minCom = (fabs(_e[0]) - fabs(_e[1]) < TOL ? fabs(_e[0]) : fabs(_e[1]));
    if (fabs(_e[2]) - minCom < TOL)
    {
        minCom = fabs(_e[2]);
    }
    return minCom;
}

int Vector3::indexOfMinComponent() const
{
    int minCom = (_e[0] - _e[1] < TOL ? 0 : 1);
    if (_e[2] - minCom < TOL)
    {
        minCom = 2;
    }
    return minCom;
}

int Vector3::indexOfMinAbsComponent() const
{
    int minCom = (fabs(_e[0]) - fabs(_e[1]) < TOL ? 0 : 1);
    if (fabs(_e[2]) - minCom < TOL)
    {
        minCom = 2;
    }
    return minCom;
}

int Vector3::indexOfMaxComponent() const
{
    int maxCom = (_e[0] - _e[1] > TOL ? 0 : 1);
    if (_e[2] - maxCom > TOL)
    {
        maxCom = 2;
    }
    return maxCom;
}

int Vector3::indexOfMaxAbsComponent() const
{
    int maxCom = (fabs(_e[0]) - fabs(_e[1]) > TOL ? 0 : 1);
    if (fabs(_e[2]) - maxCom > TOL)
    {
        maxCom = 2;
    }
    return maxCom;
}

bool operator==(const Vector3& v1, const Vector3& v2)
{
    return (isZero(v1.x() - v2.x()) && isZero(v1.y() - v2.y()) && isZero(v1.z() - v2.z()));
}

bool operator!=(const Vector3& v1, const Vector3& v2)
{
    return (!isZero(v1.x() - v2.x()) || !isZero(v1.y() - v2.y()) || !isZero(v1.z() - v2.z()));
}

std::istream & operator>>(std::istream & is, Vector3& vec)
{
    float val = 0.0f;
    is >> val;
    vec.setX(val);
    is >> val;
    vec.setY(val);
    is >> val;
    vec.setZ(val);
    return is;
}

std::ostream & operator<<(std::ostream & os, const Vector3& vec)
{
    os << '(' << vec.x() << " " << vec.y() << " " << vec.z() << ")";
    return os;
}

Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
    return Vector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
    return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

Vector3 operator/(const Vector3& vec, float scalar)
{
    if (!isZero(scalar))
    {
        return Vector3(vec[0]/scalar, vec[1]/scalar, vec[2]/scalar);
    }
    return vec;
}

Vector3 operator*(const Vector3& vec, float scalar)
{
    return Vector3(vec[0] * scalar, vec[1] * scalar, vec[2] * scalar);
}

Vector3 operator*(float scalar, const Vector3& vec)
{
    return Vector3(vec[0] * scalar, vec[1] * scalar, vec[2] * scalar);
}

Vector3& Vector3::operator=(const Vector3& vec)
{
    _e[0] = vec[0];
    _e[1] = vec[1];
    _e[2] = vec[2];
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& vec)
{
    _e[0] += vec[0];
    _e[1] += vec[1];
    _e[2] += vec[2];
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& vec)
{
    _e[0] -= vec[0];
    _e[1] -= vec[1];
    _e[2] -= vec[2];
    return *this;
}

Vector3& Vector3::operator*=(float val)
{
    _e[0] *= val;
    _e[1] *= val;
    _e[2] *= val;
    return *this;
}

Vector3& Vector3::operator/(float val)
{
    if (!isZero(val))
    {
        _e[0] /= val;
        _e[1] /= val;
        _e[2] /= val;
    }
    return *this;
}

Vector3 unitVector(const Vector3& vec)
{
    float len = vec.length();
    if (!isZero(len))
    {
        return Vector3(vec[0]/len, vec[1]/len, vec[2]/len);
    }
    return vec;
}

Vector3 minVec(const Vector3& v1, const Vector3& v2)
{
    float dx = v1[0], dy = v1[1], dz = v1[2];
    if (v2[0] - dx < TOL)
    {
        dx = v2[0];
    }
    if (v2[1] - dy < TOL)
    {
        dy = v2[1];
    }
    if (v2[2] - dz < TOL)
    {
        dz = v2[2];
    }
    return Vector3(dx, dy, dz);    
}

Vector3 maxVec(const Vector3& v1, const Vector3& v2)
{
    float dx = v1[0], dy = v1[1], dz = v1[2];
    if (v2[0] - dx > TOL)
    {
        dx = v2[0];
    }
    if (v2[1] - dy > TOL)
    {
        dy = v2[1];
    }
    if (v2[2] - dz > TOL)
    {
        dz = v2[2];
    }
    return Vector3(dx, dy, dz);  
}

Vector3 cross(const Vector3& v1, const Vector3& v2)
{
    float dx = v1.y() * v2.z() - v1.z() * v2.y();
    float dy = v1.z() * v2.x() - v1.x() * v2.z();
    float dz = v1.x() * v2.y() - v1.y() * v2.x();
    return Vector3(dx, dy, dz); 
}

float dot(const Vector3& v1, const Vector3& v2)
{
    return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
    return dot(cross(v1, v2), v3);
}
