#include <iostream>
#include <cmath>

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
    virtual void Show(const Curve& curve, double t) const = 0;
    virtual ~Curve() {}
};

class Circle : public Curve
{
private:
    double radius;
public:
    Circle(double r):radius(r) {}
    Point_3D get3dPoint (double t) const override
    {
        Point_3D temp;
        temp.x = cos(t)*radius;
        temp.y = sin(t)*radius;
        temp.z = NULL;
        return temp;
    }

    Vector_3D getFirstDerivative(double t) const override
    {
        Vector_3D temp;
        temp.x = -sin(t)*radius;
        temp.y = cos(t)*radius;
        temp.z = NULL;
        return temp;
    }

    void Show(const Curve& circle, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = circle.get3dPoint(t);
        Curve::Vector_3D vector_temp = circle.getFirstDerivative(t);

        cout << "Circle:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }
};

class Ellipse: public Curve
{
private:
    double a,b;
public:
    Ellipse(double first, double second): a(first),b(second) {}
    Point_3D get3dPoint (double t) const override
    {
        Point_3D temp;
        temp.x = a*cos(t);
        temp.y = b*sin(t);
        temp.z = NULL;
        return temp;
    }

    Vector_3D getFirstDerivative(double t) const override
    {
        Vector_3D temp;
        temp.x = a*(-sin(t));
        temp.y = cos(t) * b;
        temp.z = NULL;
        return temp;
    }

    void Show(const Curve& Ellipse, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = Ellipse.get3dPoint(t);
        Curve::Vector_3D vector_temp = Ellipse.getFirstDerivative(t);

        cout << "Ellipse:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }
};

class Helixe:public Curve
{
private:
    double radius;
    double height;
public:
    Helixe(double radius_temp, double height_temp):radius(radius_temp),height(height_temp) {}
    Point_3D get3dPoint (double t) const override
    {
        Point_3D temp;
        temp.x = radius*cos(t);
        temp.y = radius*sin(t);
        temp.z = height*t;
        return temp;
    }

    Vector_3D getFirstDerivative(double t) const override
    {
        Vector_3D temp;
        temp.x = -sin(t)*radius;
        temp.y = radius*cos(t);
        temp.z = height;
        return temp;
    }

    void Show(const Curve& Helixe, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = Helixe.get3dPoint(t);
        Curve::Vector_3D vector_temp = Helixe.getFirstDerivative(t);

        cout << "Helixe:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }
};

int main()
{
    using std::cout, std::endl;
    Circle circle_forms(5.0);
    circle_forms.Show(circle_forms,1.0);
    cout << endl;
    Ellipse ellipse_forms(3.0,2.0);
    ellipse_forms.Show(ellipse_forms,0.5);
    cout << endl;
    Helixe helixe_forms(3.0,1.0);
    helixe_forms.Show(helixe_forms,2.0);
}