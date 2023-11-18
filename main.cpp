#include "Curve_class.h"
#include <memory>

int main()
{
    using std::cout, std::endl, std::vector,std::shared_ptr, std::make_shared, std::dynamic_pointer_cast;
    srand(time(NULL));

    int const LENGTH = 10;
    double const RANDOM_T = 3.14/4;

    vector<shared_ptr<Curve>> curve_vector;
    vector<shared_ptr<Curve>> circle_vector;

    int random_order;
    double randon_value_one;
    double random_number_two;

    for(int i = 0; i < LENGTH; i++)
    {
        random_order = rand()%3+1;
        switch(random_order)
        {
            case 1:
                randon_value_one = rand()%10;
                curve_vector.push_back(make_shared<Circle>(randon_value_one));
                break;
            case 2:
                randon_value_one = rand()%10;
                random_number_two = rand()%5;
                curve_vector.push_back(make_shared<Ellipse>(randon_value_one,random_number_two));
                break;
            case 3:
                randon_value_one = rand()%10;
                random_number_two = rand()%5;
                curve_vector.push_back(make_shared<Helixe>(randon_value_one,random_number_two));
                break;
        }
    }

    for(auto &curve: curve_vector)
        curve->Show(curve.get(), RANDOM_T);

    cout << endl;
    for (shared_ptr<Curve> curve : curve_vector)
    {
        shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(curve);
        if (circle)
            circle_vector.push_back(circle);
    }

    for (auto circle : circle_vector)
        circle->Show(circle.get(),RANDOM_T);

}