#include <cassert>
#include <iostream>
#include <string>

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
    if(day >= 1 && day <= 31)
        Date::day = day;
}

void Date::Month(int month) {
    if(month >= 1 && month <= 12)
        Date::month = month;
}

void Date::Year(int year) { Date::year = year; }

class Person{
    public:
        Person(std::string n): name(n){};
        std::string name;
};

// Can also use struct here.
//struct Person{ // struct members are public by default.
//    Person(std::string n): name(n){};
//    std::string name;
//};

class Birthday {
    public:
        Birthday(int day, int month, int year) : day(day), month(month), year(year){}
        void Print(){
            std::cout << day << "/" << month << "/" << year << "\n";
        }
    private:
        int const day;
        int const month;
        int const year;
};

// Test in main
int main()
{
    Person Ali = Person("Ali");
    std::cout << Ali.name << "\n";
    Date date(8,29,1981);
    Birthday bday(8, 7, 1986);
    assert(date.Day() == 8);
    assert(date.Month() != 29);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
    bday.Print();
}
