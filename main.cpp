#include <cassert>
#include <iostream>

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

// Test in main
int main()
{
    Date date(8,29,1981);
    assert(date.Day() == 8);
    assert(date.Month() != 29);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}
