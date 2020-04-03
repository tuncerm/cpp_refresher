#include <cassert>
#include <string>
#include <iostream>

template<typename Type>
Type Max(Type a, Type b){
    return a > b ? a : b;
}

template <typename Type>
Type Product(Type t1, Type t2){return t1 * t2;}

template <typename Type> Type Sum(Type a, Type b) { return a + b; }

// TODO: Declare a generic, templatized average function
template<typename Type>
Type average(Type a, Type b){
    return (a + b) / 2;
}

int main(){
    assert(Max<int>(2, 8) == 8);
    assert(Max<double>(2.9, 1.8) == 2.9);
    assert(Max<char>('a', 'z') == 'z');

    std::cout << Sum<double>(20.0, 13.7) << "\n";

    std::cout << Sum<char>('a', 'b') << "\n";

    assert(Product<int>(10, 2) == 20);

    assert(average(2.0,5.0) == 3.5);    // deduction, the parameter type of the function is deduced.

    std::cout << average('a', 'z') << "\n"; // same here...
}