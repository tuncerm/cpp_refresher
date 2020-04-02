#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
public:
    Sphere(int radius) {
        Radius(radius);
    }

    int Radius() const { return radius_; }
    int Volume() const { return volume_; }

    void Radius(int radius){
        Check(radius);
    }
    
    //Static method / member function
    static float Volume(int radius) {
        return pi_ * 4 / 3 * pow(radius, 3);
    }

private:
    static float constexpr pi_{3.14159}; // If initialized outside the class, const can be used. Otherwise use constexpr
    int radius_;
    float volume_;
    void Check(int r){
        if (r <= 0) throw std::invalid_argument("radius must be positive");
        radius_ = r;
        volume_ = pi_ * 4 / 3 * pow(radius_, 3);
    }
};

//float const Sphere::pi_{3.14159}; // If initialized outside the class, const can be used.

// Test
int main(void) {
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.Radius(3);
    assert(sphere.Radius() == 3);
    assert(abs(sphere.Volume() - 113.1) < 1);
    assert(abs(Sphere::Volume(5) - 523.6) < 1);
    bool caught{false};
    try {
        sphere.Radius(-1);
    } catch (...) {
        caught = true;
    }
    assert(caught);
}