#include <string>
#include <iostream>
using namespace std;

class Human{};
class Cat{};
class Pokemon{};

// TODO: Write hello() function
void hello(){
    cout << "...\n";
}
// TODO: Overload hello() three times
void hello(Human human){
    cout << "Hello\n";
}
void hello(Cat cat){
    cout << "Meow\n";
}
void hello(Pokemon pokemon){
    cout << "Pika!\n";
}
// TODO: Call hello() from main()
int main(){
    hello();
    hello(Human());
    hello(Cat());
    hello(Pokemon());
}