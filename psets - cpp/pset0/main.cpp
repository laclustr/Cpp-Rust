#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <sstream>
#include <iomanip>

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
//End

using IntFunction1 = std::function<int(int)>;
using IntFunction2 = std::function<int(int, int)>;
using DoubleFunction1 = std::function<double(int)>;
using DoubleFunction2 = std::function<double(int, int)>;
using BoolFunction2 = std::function<bool(int, int)>;
using BoolFunction3 = std::function<bool(bool, bool, bool)>;
using FloatFunction3 = std::function<float(int, bool, float)>;
using StringFunction3 = std::function<std::string(int, int, int)>;

// Structure to hold function information
struct FunctionInfo {
    std::string name;
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> parameters;
    std::function<void(void)> executor;
};

// Helper function to get user input
template<typename T>
T getInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again: ";
    }
    return value;
}

// Template specialization for bool input
template<>
bool getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return (input == "1" || input == "true" || input == "yes" || input == "y");
}

// Template specialization for float input
template<>
float getInput(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again: ";
    }
    return value;
}

int main() {
    // Vector to store all function information
    std::vector<FunctionInfo> functions;

    // Register all functions
    functions.push_back({
        "rect_area",
        "int",
        {{"int", "length"}, {"int", "width"}},
        [](){
            int l = getInput<int>("Enter length: ");
            int w = getInput<int>("Enter width: ");
            std::cout << "Result: " << rect_area(l, w) << std::endl;
        }
    });

    functions.push_back({
        "circ_area",
        "double",
        {{"int", "radius"}},
        [](){
            int r = getInput<int>("Enter radius: ");
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << circ_area(r) << std::endl;
        }
    });

    functions.push_back({
        "cylinder_area",
        "double",
        {{"int", "radius"}, {"int", "height"}},
        [](){
            int r = getInput<int>("Enter radius: ");
            int h = getInput<int>("Enter height: ");
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << cylinder_area(r, h) << std::endl;
        }
    });

    functions.push_back({
        "sphere_surface_area",
        "double",
        {{"int", "radius"}},
        [](){
            int r = getInput<int>("Enter radius: ");
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << sphere_surface_area(r) << std::endl;
        }
    });

    functions.push_back({
        "sum_double",
        "int",
        {{"int", "a"}, {"int", "b"}},
        [](){
            int a = getInput<int>("Enter a: ");
            int b = getInput<int>("Enter b: ");
            std::cout << "Result: " << sum_double(a, b) << std::endl;
        }
    });

    functions.push_back({
        "in_range",
        "bool",
        {{"int", "num1"}, {"int", "num2"}},
        [](){
            int n1 = getInput<int>("Enter num1: ");
            int n2 = getInput<int>("Enter num2: ");
            std::cout << "Result: " << (in_range(n1, n2) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "distance",
        "double",
        {{"int", "x"}, {"int", "y"}},
        [](){
            int x = getInput<int>("Enter x: ");
            int y = getInput<int>("Enter y: ");
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << distance(x, y) << std::endl;
        }
    });

    functions.push_back({
        "open_gate",
        "bool",
        {{"bool", "workday"}, {"bool", "gate_activated"}, {"bool", "gate_up"}},
        [](){
            bool wd = getInput<bool>("Enter workday (1/0): ");
            bool ga = getInput<bool>("Enter gate_activated (1/0): ");
            bool gu = getInput<bool>("Enter gate_up (1/0): ");
            std::cout << "Result: " << (open_gate(wd, ga, gu) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "has_discount",
        "bool",
        {{"int", "age"}, {"bool", "had_accident"}},
        [](){
            int age = getInput<int>("Enter age: ");
            bool acc = getInput<bool>("Enter had_accident (1/0): ");
            std::cout << "Result: " << (has_discount(age, acc) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "should_apply",
        "bool",
        {{"float", "gpa"}, {"int", "act_score"}},
        [](){
            float gpa = getInput<float>("Enter GPA: ");
            int act = getInput<int>("Enter ACT score: ");
            std::cout << "Result: " << (should_apply(gpa, act) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "oil_light",
        "bool",
        {{"int", "miles"}, {"int", "days"}},
        [](){
            int miles = getInput<int>("Enter miles: ");
            int days = getInput<int>("Enter days: ");
            std::cout << "Result: " << (oil_light(miles, days) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "abs_val",
        "int",
        {{"int", "x"}},
        [](){
            int x = getInput<int>("Enter x: ");
            std::cout << "Result: " << abs_val(x) << std::endl;
        }
    });

    functions.push_back({
        "closest_tens",
        "int",
        {{"int", "a"}, {"int", "b"}},
        [](){
            int a = getInput<int>("Enter a: ");
            int b = getInput<int>("Enter b: ");
            std::cout << "Result: " << closest_tens(a, b) << std::endl;
        }
    });

    functions.push_back({
        "get_ticket_price",
        "float",
        {{"int", "price"}, {"bool", "flying_soon"}, {"float", "open_seat_pct"}},
        [](){
            int price = getInput<int>("Enter base price: ");
            bool flying_soon = getInput<bool>("Flying soon? (1/0): ");
            float open_seat_pct = getInput<float>("Enter open seat percentage (0.0-1.0): ");
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << get_ticket_price(price, flying_soon, open_seat_pct) << std::endl;
        }
    });

    functions.push_back({
        "is_special",
        "bool",
        {{"int", "num"}},
        [](){
            int num = getInput<int>("Enter number: ");
            std::cout << "Result: " << (is_special(num) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "rev_num",
        "int",
        {{"int", "n"}},
        [](){
            int n = getInput<int>("Enter 3-digit number: ");
            std::cout << "Result: " << rev_num(n) << std::endl;
        }
    });

    functions.push_back({
        "is_leap_year",
        "bool",
        {{"int", "year"}},
        [](){
            int year = getInput<int>("Enter year: ");
            std::cout << "Result: " << (is_leap_year(year) ? "true" : "false") << std::endl;
        }
    });

    functions.push_back({
        "first_day",
        "string",
        {{"int", "year"}},
        [](){
            int year = getInput<int>("Enter year: ");
            std::cout << "Result: " << first_day(year) << std::endl;
        }
    });

    functions.push_back({
        "day_of_year",
        "int",
        {{"int", "month"}, {"int", "day"}, {"int", "year"}},
        [](){
            int month = getInput<int>("Enter month (1-12): ");
            int day = getInput<int>("Enter day: ");
            int year = getInput<int>("Enter year: ");
            std::cout << "Result: " << day_of_year(month, day, year) << std::endl;
        }
    });

    functions.push_back({
        "day_of_week",
        "string",
        {{"int", "month"}, {"int", "day"}, {"int", "year"}},
        [](){
            int month = getInput<int>("Enter month (1-12): ");
            int day = getInput<int>("Enter day: ");
            int year = getInput<int>("Enter year: ");
            std::cout << "Result: " << day_of_week(month, day, year) << std::endl;
        }
    });

    // Main program loop
    while (true) {
        // Display menu
        std::cout << "\nAvailable functions:\n";
        for (size_t i = 0; i < functions.size(); ++i) {
            std::cout << i + 1 << ". " << functions[i].name << "(";
            for (size_t j = 0; j < functions[i].parameters.size(); ++j) {
                if (j > 0) std::cout << ", ";
                std::cout << functions[i].parameters[j].first << " "
                         << functions[i].parameters[j].second;
            }
            std::cout << ") -> " << functions[i].returnType << "\n";
        }

        // Get user choice
        std::cout << "\nSelect a function number (0 to exit): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > static_cast<int>(functions.size())) {
            std::cout << "Invalid selection. Please try again.\n";
            continue;
        }

        // Execute the selected function
        functions[choice - 1].executor();
    }

    return 0;
}
