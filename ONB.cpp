#include"ONB.h"
#include"mathUtil.h"

#define ONB_EPSILON 0.01f

ONB::ONB():_U(1.0f, .0f, .0f), _V(.0f, 1.0f, .0f), _W(.0f, .0f, 1.0f)
{}

ONB::ONB(const Vector3& v1, const Vector3& v2, const Vector3& v3)
    : _U(v1), _V(v2), _W(v3)
{}

void ONB::initFromU(const Vector3& u)
{
    Vector3 n(1.0f, .0f, .0f);
    Vector3 m(.0f, 1.0f, .0f);
    _U = unitVector(u);
    _V = cross(_U, n);
    if (_V.length() < ONB_EPSILON)
    {
        _V = cross(_U, m);
    }
    _W = cross(_U, _V);
}

void ONB::initFromV(const Vector3& v)
{
    Vector3 n(1.0f, .0f, .0f);
    Vector3 m(.0f, 1.0f, .0f);
    _V = unitVector(v);
    _U = cross(_V, n);
    if (_U.length() < ONB_EPSILON)
    {
        _U = cross(_V, m);
    }
    _W = cross(_U, _V);
}

void ONB::initFromW(const Vector3& w)
{
    Vector3 n(1.0f, .0f, .0f);
    Vector3 m(.0f, 1.0f, .0f);
    _W = unitVector(w);
    _U = cross(_W, n);
    if (_U.length() < ONB_EPSILON)
    {
        _U = cross(_W, m);
    }
    _V = cross(_W, _U);
}

void ONB::set(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
    _U = v1;
    _V = v2;
    _W = v3;
}

void ONB::initFromUV(const Vector3& u, const Vector3& v)
{
    _U = unitVector(u);
    _W = unitVector(cross(u, v));
    _V = cross(_W, _U);
}

void ONB::initFromVU(const Vector3& v, const Vector3& u)
{
    _V = unitVector(v);
    _W = unitVector(cross(u, v));
    _U = cross(_V, _W);
}

void ONB::initFromUW(const Vector3& u, const Vector3& w)
{
    _U = unitVector(u);
    _V = unitVector(cross(_U, _V));
    _U = cross(_V, _W);
}

void ONB::initFromWU(const Vector3& w, const Vector3& u)
{
    _W = unitVector(w);
    _V = unitVector(cross(w, u));
    _U = cross(_V, _W);
}

void ONB::initFromVW(const Vector3& v, const Vector3& w)
{
    _V = unitVector(v);
    _U = unitVector(cross(v, w));
    _W = cross(_U, _V);
}

void ONB::initFromWV(const Vector3& w, const Vector3& v)
{
    _W = unitVector(w);
    _U = unitVector(cross(v, w));
    _V = cross(_W, _U);
}

std::istream& operator>>(std::istream& is, ONB& t)
{
    Vector3 u, v, w;
    is >> u >> v >> w;
    t.set(u, v, w);
    return is;
}

std::ostream& operator<<(std::ostream& os, const ONB& t)
{
    os << t.u() << "\n" << t.v() << "\n" << t.w() << "\n";
    return os;
}

bool operator==(const ONB& o1, const ONB& o2)
{
    Vector3 u = o1.u() - o2.u();
    Vector3 v = o1.v() - o2.v();
    Vector3 w = o1.w() - o2.w();
    return (isZero(u.length(), ONB_EPSILON) 
        && isZero(v.length(), ONB_EPSILON) 
        && isZero(w.length(), ONB_EPSILON));
}

Vector3 ONB::u() const
{
    return _U;
}

Vector3 ONB::v() const
{
    return _V;
}

Vector3 ONB::w() const
{
    return _W;
}