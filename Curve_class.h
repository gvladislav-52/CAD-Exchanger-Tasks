#ifndef INC_3D_CURVES_HIERARCHY_CURVE_CLASS_H
#define INC_3D_CURVES_HIERARCHY_CURVE_CLASS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

class Curve
{
public:
    struct Point_3D
    {
        double x,y,z;
    };
    struct Vector_3D
    {
        double x,y,z;
    };
    virtual Point_3D get3dPoint(double) const = 0;
    virtual Vector_3D getFirstDerivative(double) const = 0;
    virtual void Show(const Curve* const, double t) const = 0;
    virtual ~Curve() {}
};

class Circle : public Curve
{
private:
    double radius;
public:
    Circle(double r):radius(r) {}
    Point_3D get3dPoint (double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const circle, double t) const override;
    bool operator<(const Circle& other) const { return radius < other.radius;}
    double getRadius() {return radius;}
};

class Ellipse: public Curve
{
private:
    double a,b;
public:
    Ellipse(double first, double second): a(first),b(second) {}
    Point_3D get3dPoint (double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const ellipse, double t) const override;
};

class Helixe:public Curve
{
private:
    double radius;
    double height;
public:
    Helixe(double radius_temp, double height_temp):radius(radius_temp),height(height_temp) {}
    Point_3D get3dPoint (double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const helixe, double t) const override;
};


#endif //INC_3D_CURVES_HIERARCHY_CURVE_CLASS_H
