#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <string>

//Problem 1
int rect_area(int length, int width) {
    return length * width;
}

//Problem 2
double circ_area(int radius) {
    return 3.14 * radius * radius;
}

//Problem 3
double cylinder_area(int radius, int height) {
    return (2 * 3.14 * radius * height) + (2 * 3.14 * radius * radius);
}

//Problem 4
double sphere_surface_area(int radius) {
    return 4 * 3.14 * radius * radius;
}

//Problem 5
int sum_double(int a, int b) {
    if (a == b) {
        return (a + b) * 2;
    }
    return a + b;
}

//Problem 6
bool in_range(int num1, int num2) {
    if ((num1 >= 20 && num1 <= 30) && (num2 >= 20 && num2 <= 30)) {
        return true;
    }
    else if ((num1 >= 90 && num1 <= 100) && (num2 >= 90 && num2 <= 100)) {
        return true;
    }

    return false;
}

//Problem 7
double distance(int x, int y) {
    return std::sqrt((std::pow(x, 2) + std::pow(y, 2)));
}

//Problem 8
bool open_gate(bool workday, bool gate_activated, bool gate_up) {
    return workday && gate_activated && !gate_up;
}

//Problem 9
bool has_discount(int age, bool had_accident) {
    return age >= 24 && !had_accident;
}

//Problem 10
bool should_apply(float gpa, int act_score) {
    if (gpa >= 3.9 and act_score > 31) {
        return true;
    }
    else if (gpa >= 4.25 || act_score >= 34) {
        return true;
    }

    return false;
}

//Problem 11
bool oil_light(int miles, int days) {
    if (miles >= 10000 || days > 365) {
        return true;
    }

    return false;
}

//Problem 12
int abs_val(int x) {
    if (x < 0) {
        return x * -1;
    }
    else {
        return x;
    }
}
//End Problem 12

int min_num(int a, int b) {
    if (a < b) {
        return a;
    }
    else if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

//Problem 13
int closest_tens(int a, int b) {
    int a_rem = min_num(a % 10, 10 - (a % 10));
    int b_rem = min_num(b % 10, 10 - (b % 10));

    if (a_rem < b_rem) {
        return a;
    }
    else if (a_rem > b_rem) {
        return b;
    }
    else {
        return a;
    }
}

//Problem 14
float get_ticket_price(int price, bool flying_soon, float open_seat_pct) {
    if (!flying_soon) {
        if (open_seat_pct < 0.25) {
            return 1.25 * price;
        }
        else {
            return price;
        }
    }
    else {
        if (open_seat_pct < 0.10) {
            return price * 1.40;
        }
        else if (open_seat_pct >= 0.50) {
            return 0.85 * price;
        }
        else {
            return price;
        }
    }
}

//Problem 15
bool is_special(int num) {
    int mod10 = num % 10;

    if (mod10 == 2 || mod10 == 4 || mod10 == 8) {
        return true;
    }

    return false;
}

//Problem 16
int rev_num(int n) {
    std::string reversed = "";

    int hundos = n / 100;
    int tens = (n / 10) % 10;
    int ones = n % 10;

    reversed += std::to_string(ones);
    reversed += std::to_string(tens);
    reversed += std::to_string(hundos);

    return std::stoi(reversed);
}

//Problem 17
bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if ((year % 4 == 0) && (year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
}
//End Problem 17

int first_day_help(int year) {
    int q = 1;
    int m = 13;
    int Y = (year - 1) % 100;
    int C = (year - 1) / 100;

    int day = (q + (13 * (m + 1)) / 5 + Y + Y / 4 + C / 4 - 2 * C) % 7;
    day = (day + 6) % 7;
    return day;
}

//Problem 18
std::string first_day(int year) {
    int day = first_day_help(year);

    if (day == 0) {
        return "Sunday";
    }
    else if (day == 1) {
        return "Monday";
    }
    else if (day == 2) {
        return "Tuesday";
    }
    else if (day == 3) {
        return "Wednesday";
    }
    else if (day == 4) {
        return "Thursday";
    }
    else if (day == 5) {
        return "Friday";
    }
    else if (day == 6) {
        return "Saturday";
    }
    else {
        return "n/a";
    }
}

//Problem 19
int day_of_year(int month, int day, int year) {
    int daysBefore = 0;

    if (month > 1) {
        daysBefore += 31;
    }
    if (month > 2) {
        if (is_leap_year(year)) {
            daysBefore += 29;
        }
        else {
            daysBefore += 28;
        }
    }
    if (month > 3) {
        daysBefore += 31;
    }
    if (month > 4) {
        daysBefore += 30;
    }
    if (month > 5) {
        daysBefore += 31;
    }
    if (month > 6) {
        daysBefore += 30;
    }
    if (month > 7) {
        daysBefore += 31;
    }
    if (month > 8) {
        daysBefore += 31;
    }
    if (month > 9) {
        daysBefore += 30;
    }
    if (month > 10) {
        daysBefore += 31;
    }
    if (month > 11) {
        daysBefore += 30;
    }

    return daysBefore + day;
}

//Problem 20
std::string day_of_week(int month, int day, int year) {
    int firstDay = first_day_help(year);
    int dayOfYear = day_of_year(month, day, year);
    int dayNum = (firstDay + (dayOfYear - 1)) % 7;

    if (dayNum == 0) {
        return "Sunday";
    }
    else if (dayNum == 1) {
        return "Monday";
    }
    else if (dayNum == 2) {
        return "Tuesday";
    }
    else if (dayNum == 3) {
        return "Wednesday";
    }
    else if (dayNum == 4) {
        return "Thursday";
    }
    else if (dayNum == 5) {
        return "Friday";
    }
    else if (dayNum == 6) {
        return "Saturday";
    }
    else {
        return "n/a";
    }
}

int main() {
}
