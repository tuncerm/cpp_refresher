#include <string>
#include <iostream>

using namespace std;

// Define base class Animal
class Animal{
public:
    string color, name;
    int age;
};

// Declare derived class Snake
class Snake: public Animal{
public:
    int length;
    void MakeSound(){
        cout << "Hiss\n";
    }
};
// Declare derived class Cat
class Cat: public Animal{
public:
    int height;
    void MakeSound(){
        cout << "Meow\n";
    }
};
// Test in main()
int main(){
    Cat cat;
    cat.height = 3;
    Snake snake;
    snake.length = 6;
    cat.MakeSound();
    snake.MakeSound();
}