#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.14159;

// Define Line Class
class LineSegment{
public:
    LineSegment(double length): length(length){}
    // Define protected attribute length
    double length;
};

// Define Circle subclass
class Circle{
    // Define public setRadius() and getArea()
public:
    Circle(LineSegment& radius): radius_(radius){}
    void setRadius(LineSegment& radius){
        radius_=radius;
    }
    double Area(){
        return pow(radius_.length, 2) * PI;
    }
private:
    LineSegment& radius_;
};
// Test in main()
int main()
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}