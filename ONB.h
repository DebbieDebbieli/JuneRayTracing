#ifndef _ONB_H_
#define _ONB_H_ 1

#include"Vector3.h"

class ONB
{
public:
    ONB();
    ONB(const Vector3& v1, const Vector3& v2, const Vector3& v3);

    void initFromU(const Vector3& u);
    void initFromV(const Vector3& v);
    void initFromW(const Vector3& w);

    void set(const Vector3& v1, const Vector3& v2, const Vector3& v3);

    void initFromUV(const Vector3& u, const Vector3& v);
    void initFromVU(const Vector3& v, const Vector3& u);
    void initFromUW(const Vector3& u, const Vector3& w);
    void initFromWU(const Vector3& w, const Vector3& u);
    void initFromVW(const Vector3& v, const Vector3& w);
    void initFromWV(const Vector3& w, const Vector3& v);

    friend std::istream& operator>>(std::istream& is, ONB& t);
    friend std::ostream& operator<<(std::ostream& os, const ONB& t);
    friend bool operator==(const ONB& o1, const ONB& o2);

    Vector3 u() const;
    Vector3 v() const;
    Vector3 w() const;

public:
    Vector3 _U;
    Vector3 _V;
    Vector3 _W;
};
#endif