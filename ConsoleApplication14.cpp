#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

    void incrementDay() {
        ++day;
    }

    Date operator++() {
        incrementDay();
        return *this;
    }

    Date operator--() {
        --day;
        return *this;
    }

    bool operator!=(const Date& other) const {
        return !(day == other.day && month == other.month && year == other.year);
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator>(const Date& other) const {
        if (year != other.year) {
            return year > other.year;
        }
        else if (month != other.month) {
            return month > other.month;
        }
        else {
            return day > other.day;
        }
    }

    bool operator<(const Date& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        else if (month != other.month) {
            return month < other.month;
        }
        else {
            return day < other.day;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    friend std::istream& operator>>(std::istream& is, Date& date);

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date& operator+=(int days) {
        day += days;
        return *this;
    }

    Date& operator-=(int days) {
        day -= days;
        return *this;
    }

    int operator()() const {
        return day;
    }
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << '/' << date.month << '/' << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

int main() {
    Date currentDate(1, 1, 2023);
    std::cout << "Current Date: " << currentDate << std::endl;

    ++currentDate;
    std::cout << "After incrementing day: " << currentDate << std::endl;

    Date newDate(2, 1, 2023);
    if (currentDate != newDate) {
        std::cout << "Dates are not equal." << std::endl;
    }
    else {
        std::cout << "Dates are equal." << std::endl;
    }

    currentDate += 5;
    std::cout << "After adding 5 days: " << currentDate << std::endl;

    int day = currentDate();
    std::cout << "Day of the current date: " << day << std::endl;

    return 0;
}
