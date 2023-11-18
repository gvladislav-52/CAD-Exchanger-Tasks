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

    void Show(const Curve* const circle, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = circle->get3dPoint(t);
        Curve::Vector_3D vector_temp = circle->getFirstDerivative(t);

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

    void Show(const Curve* const ellipse, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = ellipse->get3dPoint(t);
        Curve::Vector_3D vector_temp = ellipse->getFirstDerivative(t);

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

    void Show(const Curve* const helixe, double t) const override
    {
        using std::cout, std::endl;
        Curve::Point_3D point_temp = helixe->get3dPoint(t);
        Curve::Vector_3D vector_temp = helixe->getFirstDerivative(t);

        cout << "Helixe:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
        cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    }
};

int main()
{
    using std::cout, std::endl, std::vector;
    srand(time(NULL));
    vector<Curve*> curve_vector;
    int const LENGTH = 10;
    int random_count;
    double random_number;
    double random_number2;
    double random_t;
    for(int i = 0; i < LENGTH; i++)
    {
        random_count = rand()%3+1;
        switch(random_count)
        {
            case 1:
                random_number = rand()%10;
                curve_vector.push_back(new Circle(random_number));
                break;
            case 2:
                random_number = rand()%10;
                random_number2 = rand()%5;
                curve_vector.push_back(new Ellipse(random_number,random_number2));
                break;
            case 3:
                random_number = rand()%10;
                random_number2 = rand()%5;
                curve_vector.push_back(new Ellipse(random_number,random_number2));
                break;
        }
    }

    for(const auto &curve: curve_vector)
    {
        random_t = rand()%10;
        curve->Show(curve, random_t);
    }
}