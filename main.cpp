#include "Curve_class.h"
#include <memory>
#include <algorithm>

int main()
{
    using std::cout, std::endl, std::vector,std::shared_ptr, std::make_shared, std::dynamic_pointer_cast, std::sort;
    srand(time(NULL));

    int const LENGTH = 10;
    double const RANDOM_T = 3.14/4;
    double sum = 0;

    vector<shared_ptr<Curve>> curve_vector;
    vector<shared_ptr<Curve>> circle_vector;

    int random_order;
    double randon_value_one;
    double random_number_two;

    cout << "\nDISPLAYING VECTOR ELEMENTS (LENGTH 10)" << endl;
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

    cout << "OUTPUT OF A CONTAINER STORING ELEMENTS OF THE CIRCLE TYPE (SORTED): " << endl;
    sort(circle_vector.begin(), circle_vector.end(), [] (shared_ptr<Curve> c1, shared_ptr<Curve> c2)
    {
        return *dynamic_cast<Circle*>(c1.get()) < *dynamic_cast<Circle*>(c2.get());
    });

    for (auto circle : circle_vector)
        circle->Show(circle.get(),RANDOM_T);

    for(const auto &circle: circle_vector)
        sum += dynamic_cast<Circle*> (circle.get())->getRadius();

    cout << "\nTHE TOTAL SUM OF ALL THE RADII OF THE CURVES: " << sum << endl;
}