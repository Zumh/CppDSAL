#include <iostream>
#include <cmath>
using namespace std;
const double pi = atan(1.0) * 4.0;
class Circle {
    private:
    int radius;
    public:
    // construct the Circle
    Circle(int radius){this->radius = radius;}
    ~Circle(void){}

    int getRadius(void) const { return radius;}


};

class Utility {
    public:
    double calculateArea(const Circle& currentCircle){
        double radius = static_cast<double> (currentCircle.getRadius());
        return pow(radius, 2) * pi;

    }
};


int main(void){
    
    cout << "Create circle" << endl;

    Circle *c1 = new Circle(10);
    Utility area;
    cout << "c1 radius " << c1->getRadius() << endl;
    cout << "Circle's Area " << area.calculateArea(*c1) << endl;
    delete c1;
    return (0);
}