#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;

class BankAccount {

private:
    std::string account_number;
    std::string owner_name;
    double available_funds;

public:
    void PrintInfo();

    BankAccount(std::string account_number,
                std::string owner_name,
                double available_funds) :
            account_number(account_number),
            owner_name(owner_name),
            available_funds(available_funds) {};
    // TODO: declare getters
};

// TODO: implement setters
void BankAccount::PrintInfo() {
    std::cout << "_______INFO_______\n";
    std::cout << "ID: " << account_number << "\n";
    std::cout << "Name: " << owner_name << "\n";
    std::cout << "Funds: $" << available_funds << "\n";
    std::cout << "_______ENDINFO____\n";
}

class Date {
public:
    Date(int d, int m, int y);

    int Day() { return day; }

    void Day(int d);

    int Month() { return month; }

    void Month(int m);

    int Year() { return year; }

    void Year(int y);

private:
    int day{1};
    int month{1};
    int year{0};
};

Date::Date(int day, int month, int year) : year(year) {
    Day(day);
    Month(month);
}

void Date::Day(int day) {
    if (day >= 1 && day <= 31)
        Date::day = day;
}

void Date::Month(int month) {
    if (month >= 1 && month <= 12)
        Date::month = month;
}

void Date::Year(int year) { Date::year = year; }

//class Person{
//    public:
//        Person(std::string n): name(n){};
//        std::string name;
//};
class Person {
public:
    Person(std::string const &n) : name(n) {}; // if used to initialize, the reference should also be a const.
    std::string const name;
};

// Can also use struct here.
//struct Person{ // struct members are public by default.
//    Person(std::string n): name(n){};
//    std::string name;
//};

class Birthday {
public:
    Birthday(int day, int month, int year) : day(day), month(month), year(year) {}

    void Print() {
        std::cout << day << "/" << month << "/" << year << "\n";
    }

private:
    int const day;
    int const month;
    int const year;
};


class Car {
    // TODO: Declare private attributes
private:
    char *brand;
    // TODO: Declare getter and setter for brand
public:
    void SetBrand(std::string);
    std::string GetBrand() const;
    float horsepower{0};
    float weight{0};
};

// Define setters
void Car::SetBrand(std::string brand_name){
    Car::brand = new char[brand_name.length() + 1];
    strcpy(Car::brand, brand_name.c_str());
}
// Define getters
std::string Car::GetBrand() const{
    std::string result = "Brand name: ";
    // Specifying string for output of brand name
    result += Car::brand;
    return result;
}

class Pyramid{
public:
    Pyramid(int length, int width, int height):
            length_(length), width_(width), height_(height){
        Validate();
    }
    int Length(){return length_;}
    int Width(){return width_;}
    int Height(){return height_;}
    void Length(int);
    void Width(int);
    void Height(int);
    int Volume();
private:
    int length_, width_, height_;
    bool Check(double d){return d > 0;}
    void Validate() {
        if (length_ <= 0 || width_ <= 0 || height_ <= 0)
            throw std::invalid_argument("negative dimension");
    }
};

void Pyramid::Length(int d){
    if(Check(d)){
        length_ = d;
    }
}
void Pyramid::Width(int d){
    if(Check(d)){
        width_ = d;
    }
}
void Pyramid::Height(int d){
    if(Check(d)){
        height_ = d;
    }
}
int Pyramid::Volume(){
    return (width_ * height_ * length_) / 3;
}

class Student {
public:
    // constructor
    Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) {
        Validate();
    }
    // accessors
    string Name() const {
        return name_;
    }
    int Grade() const {
        return grade_;
    }
    float GPA() const {
        return gpa_;
    }

    // mutators
    void Name(string name) {
        name_ = name;
        Validate();
    }
    void Grade(int grade) {
        grade_ = grade;
        Validate();
    }
    void GPA(float gpa) {
        gpa_ = gpa;
        Validate();
    }

private:
    string name_;
    int grade_;
    float gpa_;
    void Validate() {
        if(Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
            throw std::invalid_argument("argument out of bounds");
    }
};

// Test in main
int main() {
    Person Ali = Person("Ali");
    std::cout << Ali.name << "\n";
    Date date(8, 29, 1981);
    Birthday bday(8, 7, 1986);
    assert(date.Day() == 8);
    assert(date.Month() != 29);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
    bday.Print();

    BankAccount account("12312313", "Pikachu", 99.99);
    account.PrintInfo();

    Car car;
    car.SetBrand("Peugeot");
    std::cout << car.GetBrand() << "\n";

    Pyramid pyramid(4, 5, 6);
    assert(pyramid.Length() == 4);
    assert(pyramid.Width() == 5);
    assert(pyramid.Height() == 6);
    assert(pyramid.Volume() == 40);

    bool caught{false};
    try {
        Pyramid invalid(-1, 2, 3);
    } catch (...) {
        caught = true;
    }
    assert(caught);


    Student david("David Silver", 10, 4.0);
    assert(david.Name() == "David Silver");
    assert(david.Grade() == 10);
    assert(david.GPA() == 4.0);

    caught = false;
    try {
        david.Grade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
}