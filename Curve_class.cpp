#include "Curve_class.h"

    Circle::Point_3D Circle::get3dPoint (double t) const
    {
    Circle::Point_3D temp;
        temp.x = cos(t)*radius;
        temp.y = sin(t)*radius;
        temp.z = NULL;
        return temp;
    }

    Circle::Vector_3D Circle::getFirstDerivative(double t) const
    {
        Vector_3D temp;
        temp.x = -sin(t)*radius;
        temp.y = cos(t)*radius;
        temp.z = NULL;
        return temp;
    }

    void Circle::Show(const Curve* const circle, double t) const
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = circle->get3dPoint(t);
        Curve::Vector_3D vector_temp = circle->getFirstDerivative(t);

        cout << "Circle:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }

    Ellipse::Point_3D Ellipse::get3dPoint (double t) const
    {
        Point_3D temp;
        temp.x = a*cos(t);
        temp.y = b*sin(t);
        temp.z = NULL;
        return temp;
    }

    Ellipse::Vector_3D Ellipse::getFirstDerivative(double t) const
    {
        Vector_3D temp;
        temp.x = a*(-sin(t));
        temp.y = cos(t) * b;
        temp.z = NULL;
        return temp;
    }

    void Ellipse::Show(const Curve* const ellipse, double t) const
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = ellipse->get3dPoint(t);
        Curve::Vector_3D vector_temp = ellipse->getFirstDerivative(t);

        cout << "Ellipse:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }

    Helixe::Point_3D Helixe::get3dPoint (double t) const
    {
        Point_3D temp;
        temp.x = radius*cos(t);
        temp.y = radius*sin(t);
        temp.z = height*t;
        return temp;
    }

    Helixe::Vector_3D Helixe::getFirstDerivative(double t) const
    {
        Vector_3D temp;
        temp.x = -sin(t)*radius;
        temp.y = radius*cos(t);
        temp.z = height;
        return temp;
    }

    void Helixe::Show(const Curve* const helixe, double t) const
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = helixe->get3dPoint(t);
        Curve::Vector_3D vector_temp = helixe->getFirstDerivative(t);

        cout << "Helixe:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }