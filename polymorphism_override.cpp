#include <cassert>
#include <cmath>
#define PI 3;

class Shape {
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    double Area() const override { return pow(radius_, 2) * PI; } // specified as an override function
    double Perimeter() const override { return 2 * radius_ * PI; } // specified as an override function
    // override keyword is not required but it is best practice to use.
    // It tells the compiler that it should override something.
    // The compiler will give error if something is amiss. Like wrong function name or missing inheritance.
private:
    double radius_;
};

int main(){
    Circle circle(3);
    assert(circle.Area() == 27);
}