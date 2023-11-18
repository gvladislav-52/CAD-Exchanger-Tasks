#include "Curve_class.h"

int main()
{
    using std::cout, std::endl, std::vector;
    srand(time(NULL));
    vector<Curve*> curve_vector;
    int const LENGTH = 10;
    int random_count;
    double random_number;
    double random_number2;
    double random_t = 3.14/4;
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
                curve_vector.push_back(new Helixe(random_number,random_number2));
                break;
        }
    }

    for(const auto &curve: curve_vector)
    {
        curve->Show(curve, random_t);
    }
}