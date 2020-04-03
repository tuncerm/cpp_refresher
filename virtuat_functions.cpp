#include <iostream>

using namespace std;

class Animal{
    virtual void Talk() const = 0;
};

class Human: public Animal{
public:
    void Talk() const {
        cout << "Hello!\n";
    }
};

int main(){
    Human human;
    human.Talk();
}