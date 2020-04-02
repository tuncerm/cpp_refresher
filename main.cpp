#include <cassert>
#include <iostream>
#include <string>

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
}
