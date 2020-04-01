#include <iostream>

struct Date {
    public:
        int Day(){ return day; } // getter -- Accessor function
        void Day(int d) {day = d;} //setter -- Mutator function
    int month{1};
    int year{1970};
    private:
        int day{1}; // Private member
};

int main() {
    Date date;

    date.Day(29);

    std::cout << date.Day() << "/" << date.month << "/" << date.year << std::endl;
    return 0;
}
