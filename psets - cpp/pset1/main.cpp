#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

//Problem 1
int count_e(std::string string){
    int ecount = 0;
    
    for (char i : string) {
        if (i == 'e' || i == 'E') {
            ecount++;
        }
    }
    
    return ecount;
}

//Problem 2
bool ends_with(std::string string, std::string substring) {
    std::string::size_type diff = string.size() - substring.size();
    
    for (std::string::size_type i = 0; i < substring.size(); i++) {
        if (string[diff + i] != substring[i]) {
            return false;
        }
    }
    return true;
    
}

//Problem 3
std::string reverse_string(std::string string) {
    std::string result = "";
    
    for (std::string::size_type i = string.size(); i > 0; i--) {
        result += string[i - 1];
    }
    
    return result;
}

//Problem 4
int sum_between(int a, int b) {
    int sum = 0;
    
    for (int i = a; i <= b; i++) {
        sum += i;
    }
    
    return sum;
}

//Problem 5
int index_of(std::string string, std::string substring) {
    if (substring.size() == 0 || string.size() == 0 || substring.size() > string.size()) {
            return -1;
        }
    
    for (int i = 0; i <= string.size() - substring.size(); i++) {
    bool match = true;
        for (int j = 0; j < substring.size(); j++) {
            if (string[i + j] != substring[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    
    return -1;
}

//Problem 6
int count_long_char(std::string string) {
    int max_len = 1;
    int curr_len = 1;
    
    for (int i = 1; i < string.size(); i++) {
        if (string[i] == string[i - 1]) {
            curr_len++;
            if (curr_len > max_len) {
                max_len = curr_len;
            }
        }
        else {
            curr_len = 1;
        }
    }
    
    return max_len;
}

//Problem 7
bool is_good_password(std::string password) {
    if (password.size() < 10) {
        return false;
    }
    
    bool caps = false;
    bool lower = false;
    bool special = false;
    
    for (char i : password) {
        if (i >= 'A' && i <= 'Z') {
            caps = true;
        }
        if (i >= 'a' && i <= 'z') {
            lower = true;
        }
        if ((i >= '!' && i <= '/') || (i >= ':' && i <= '@') || (i >= '[' && i <= '`') || (i >= '{' && i <= '~')) {
            special = true;
        }
    }
    return caps && lower && special;
}

//Problem 8
int harshad_numbers(int n) {
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        int lnum = 0;
        int tnum = i;
        
        while (tnum > 0) {
            lnum += tnum % 10;
            tnum /= 10;
        }
        
        if (i % lnum == 0) {
            count++;
        }
    }
    
    return count;
}

//Problem 9
int count_digits(int n) {
    int count = 0;
    
    if (n < 0) {
        n *= -1;
    }
    if (n < 10) {
        return 1;
    }
    
    while (n > 0) {
        n /= 10;
        count++;
    }
    
    return count;
}

//Problem 10
std::string upper_string(std::string string) {
    std::string result = "";
    
    for (char i : string) {
        if (i >= 'a' && i <= 'z') {
            result += (i - 'a' + 'A');
        }
        else {
            result += i;
        }
    }
    
    return result;
}

//Problem 11
std::string caesar_encrypt(std::string string, int n) {
    string = upper_string(string);
    std::string result = "";
    n %= 26;
    
    for (char i : string) {
        if (i >= 'A' && i <= 'Z') {
            int shift = i + n;
            if (shift > 'Z') {
                shift = (shift - '[') + 'A';
            }
            result += shift;
        }
        else {
            result += i;
        }
    }
    
    return result;
}

//Problem 12
std::string caesar_decrypt(std::string string, int n) {
    string = upper_string(string);
    std::string result = "";
    n %= 26;
    
    for (char i : string) {
        if (i >= 'A' && i <= 'Z') {
            int shift = i - n;
            
            if (shift < 'A') {
                shift += 26;
            }
            
            result += shift;
        }
        else {
            result += i;
        }
    }
    
    return result;
}

//Problem 13
int my_pow(int x, int a) {
    int result = 1;
    
    while (a > 0) {
        result *= x;
        a--;
    }
    
    return result;
}

//Problem 14
int my_factorial(int n) {
    int result = 1;
    
    if (n == 0) {
        return result;
    }
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

//Problem 15
int double_factorial(int n) {
    int result = 1;
    if (n == 0 || n == 1) {
        return result;
    }
    
    for (int i = n; i > 0; i -= 2) {
        result *= i;
    }
    
    return result;
}

//Problem 16
bool is_palindrome(std::string string) {
    if (reverse_string(string) == string) {
        return true;
    }
    
    return false;
}

//Problem 17
double my_sqrt(auto x) {
    double t = x;
    
    while (std::abs(t * t - x) > 1e-15) {
        t = (t + x / t) / 2;
    }
    
    return t;
}

//Problem 18
std::string find_and_replace(std::string string, std::string target, std::string replacement) {
    std::string result = "";
    int i = 0;
    while (i < string.size()) {
        if (string.substr(i, target.size()) == target) {
            result += replacement;
            i += target.size();
        }
        else {
            result += string[i];
            i++;
        }
    }
    
    return result;
}

//Problem 19
int fib(int n) {
    if (n == 1) {
        return 1;
    }
    
    int num1 = 0;
    int num2 = 1;
    
    int i = 2;
    
    while (i <= n) {
        int temp = num2;
        num2 += num1;
        num1 = temp;
        
        i++;
    }
    
    return num2;
}

//Problem 20
std::string run_length_encode(std::string string) {
    std::string result = "";
    int count = 1;
    
    for (int i = 1; i < string.size(); i++) {
        if (string[i] == string[i - 1]) {
            count += 1;
        }
        else {
            result += string[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    result += string[string.size() - 1] + std::to_string(count);
    
    return result;
}

//Problem 21
std::string run_length_decode(std::string string) {
    std::string result = "";
    
    for (int i = 0; i < string.size(); i += 2) {
        int count = string[i + 1] - '0';
        char rpc = string[i];
        
        for (int j = 0; j < count; j++) {
            result += rpc;
        }
    }
    
    return result;
}

//Problem 22
bool are_anagram(std::string string1, std::string string2) {
    if (string1.size() != string2.size()) {
        return false;
    }
    
    std::string pstring1 = string1;
    std::string pstring2 = string2;
    
    for (char i : string1) {
        int index1 = index_of(pstring1, std::string(1, i));
        int index2 = index_of(pstring2, std::string(1, i));
        
        if (index1 >= 0) {
            pstring1 = find_and_replace(pstring1, std::string(1, i), "");
        } else {
            return false;
        }
        
        if (index2 >= 0) {
            pstring2 = find_and_replace(pstring2, std::string(1, i), "");
        } else {
            return false;
        }
    }
        
    
    return true;
}

//Problem 23
std::string remove_duplicates(std::string string) {
    
    std::string seen = "";
    std::string result = "";
    
    for (char i : string) {
        if (index_of(seen, std::string(1, i)) == -1) {
            seen += i;
            result += i;
        }
    }
    
    return result;
    
}

//Problem 24
double my_exp(int x) {
    double result = 1;
    double term = 1;
    int iterations = 1;
    
    while (std::abs(term) >= 1e-15) {
        double powxk = 1;
        double factk = 1;
        
        for (int i = 1; i <= iterations; i++) {
            powxk *= x;
            factk *= i;
        }
        
        term = powxk / factk;
        result += term;
        iterations += 1;
    }
    
    return result;
}
//End Problem 24

std::string multiply_string(std::string str, int n) {
    std::string result = "";
    
    if (n <= 0 || str.size() == 0) {
        return "";
    }
    
    for (int i = 0; i < n; i++) {
        result += str;
    }
    
    return result;
}

//Problem 25
std::string make_squares(int n) {
    bool firstOrlast = true;
    int iterations = n;
    std::string result = "";
    
    while (iterations > 1) {
        if (firstOrlast) {
            result += multiply_string("*", n) + " " + multiply_string("*", n) + "\n";
            
            firstOrlast = false;
        } else {
            result += multiply_string("*", n) + " " + "*" + multiply_string(" ", n - 2) + "*" + "\n";
        }
        iterations -= 1;
    }
    
    result += multiply_string("*", n) + " " + multiply_string("*", n);
    
    return result;
}

//Problem 26
std::string make_hollow_diamond(int n) {
    std::string result = "";
    int iterations = n;
    
    for (int i = 0; i < iterations; i++) {
        std::string row = multiply_string(" ", iterations - i - 1);
        
        if (i == 0) {
            row += "*";
        } else {
            row += "*" + multiply_string(" ", 2 * i - 1)  + "*";
        }
        
        result += row + "\n";
    }
    
    for (int i = iterations - 2; i > -1; i--) {
        std::string row = multiply_string(" ", iterations - i - 1);
        
        if (i == 0) {
            row += "*";
        } else {
            row += "*" + multiply_string(" ", 2 * i - 1) + "*";
        }
        result += row + "\n";
    }
    
    return result;
}

//Problem 27
std::string make_diamond(int n) {
    std::string result = "";
    int iterations = n;
    
    for (int i = 0; i < iterations; i++) {
        std::string row = multiply_string(" ", iterations - i - 1);
        row += multiply_string("*", 2 * i + 1);
        result += row + "\n";
    }
    
    for (int i = iterations - 2; i > -1; i--) {
        std::string row = multiply_string(" ", iterations - i - 1);
        row += multiply_string("*", 2 * i + 1);
        result += row + "\n";
    }
    
    return result;
}

//Problem MC1
double k_consecutive(float p, int n, int k) {
    int simulations = 10000000;
    int successes = 0;
    
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < simulations; i++) {
        int heads = 0;
        bool enoughHeads = false;
        
        for (int j = 0; j < n; j++) {
            double r = (double)rand() / RAND_MAX;
            if (r < p) {
                heads += 1;
                if (heads >= k) {
                    enoughHeads = true;
                }
            } else {
                heads = 0;
            }
        }
        if (enoughHeads) {
            successes++;
        }
    }
    
    return (double)successes / simulations;
}

//Problem MC2
double p_unfair_coin(int n, int g, float p, int n_heads, int n_flips) {
    int simulations = 1000;
    int biCoins = n - g;
    float probHead = 0.5;

    int biCounter = 0;
    int tCounter = 0;
    
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < simulations; i++) {
        bool biased = ((double)rand() / RAND_MAX) < ((double)biCoins / n);
        float currentProbHead;
        
        if (biased) {
            currentProbHead = p;
        } else {
            currentProbHead = probHead;
        }
        
        int headCount = 0;
        for (int j = 0; j < n_flips; j++) {
            if (((double)rand() / RAND_MAX) < probHead) {
                headCount++;
            }
        }
        
        if (headCount == n_heads) {
            tCounter++;
            
            if (biased) {
                biCounter++;
            }
        }
    }
    
    if (tCounter == 0) {
        return 0.0;
    }
    
    return (double)biCounter / tCounter;
}

//Problem MC3
double draw_all_good_cards(int n, int g, int turn){
    int simulations = 100000;
    int successes = 0;
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < simulations; i++) {
        int bCards = n - g;
        int gCards = g;
        
        int gCardDraws = 0;
        
        for (int j = 0; j < turn; j++) {
            if (((double)rand() / RAND_MAX) < (double)gCards / (gCards + bCards)) {
                gCardDraws++;
                gCards--;
            } else {
                bCards--;
            }
        }
        
        if (gCardDraws == g) {
            successes++;
        }
    }
    return (double)successes / simulations;
}

//End

std::string get_string_input(const std::string& param_name) {
    std::string input;
    std::cout << "Enter " << param_name << ": ";
    std::getline(std::cin, input);
    return input;
}

int get_int_input(const std::string& param_name) {
    int input;
    std::cout << "Enter " << param_name << " (integer): ";
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

float get_float_input(const std::string& param_name) {
    float input;
    std::cout << "Enter " << param_name << " (float): ";
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

int main() {
    std::vector<std::string> functions = {
        "1. count_e(string)",
        "2. ends_with(string, substring)",
        "3. reverse_string(string)",
        "4. sum_between(a, b)",
        "5. index_of(string, substring)",
        "6. count_long_char(string)",
        "7. is_good_password(password)",
        "8. harshad_numbers(n)",
        "9. count_digits(n)",
        "10. upper_string(string)",
        "11. caesar_encrypt(string, n)",
        "12. caesar_decrypt(string, n)",
        "13. my_pow(x, a)",
        "14. my_factorial(n)",
        "15. double_factorial(n)",
        "16. is_palindrome(string)",
        "17. my_sqrt(x)",
        "18. find_and_replace(string, target, replacement)",
        "19. fib(n)",
        "20. run_length_encode(string)",
        "21. run_length_decode(string)",
        "22. are_anagram(string1, string2)",
        "23. remove_duplicates(string)",
        "24. my_exp(x)",
        "25. make_squares(n)",
        "26. make_hollow_diamond(n)",
        "27. make_diamond(n)",
        "28. k_consecutive(p, n, k)",
        "29. p_unfair_coin(n, g, p, n_heads, n_flips)",
        "30. draw_all_good_cards(n, g, turn)"
    };

    while (true) {
        std::cout << "\nAvailable functions:\n";
        for (const auto& func : functions) {
            std::cout << func << "\n";
        }

        std::cout << "\nEnter function number (0 to exit): ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (choice == 0) break;
        if (choice < 1 || choice > functions.size()) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << count_e(str) << std::endl;
                break;
            }
            case 2: {
                std::string str = get_string_input("string");
                std::string substr = get_string_input("substring");
                std::cout << "Result: " << (ends_with(str, substr) ? "true" : "false") << std::endl;
                break;
            }
            case 3: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << reverse_string(str) << std::endl;
                break;
            }
            case 4: {
                int a = get_int_input("a");
                int b = get_int_input("b");
                std::cout << "Result: " << sum_between(a, b) << std::endl;
                break;
            }
            case 5: {
                std::string str = get_string_input("string");
                std::string substr = get_string_input("substring");
                std::cout << "Result: " << index_of(str, substr) << std::endl;
                break;
            }
            case 6: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << count_long_char(str) << std::endl;
                break;
            }
            case 7: {
                std::string pwd = get_string_input("password");
                std::cout << "Result: " << (is_good_password(pwd) ? "true" : "false") << std::endl;
                break;
            }
            case 8: {
                int n = get_int_input("n");
                std::cout << "Result: " << harshad_numbers(n) << std::endl;
                break;
            }
            case 9: {
                int n = get_int_input("n");
                std::cout << "Result: " << count_digits(n) << std::endl;
                break;
            }
            case 10: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << upper_string(str) << std::endl;
                break;
            }
            case 11: {
                std::string str = get_string_input("string");
                int n = get_int_input("n");
                std::cout << "Result: " << caesar_encrypt(str, n) << std::endl;
                break;
            }
            case 12: {
                std::string str = get_string_input("string");
                int n = get_int_input("n");
                std::cout << "Result: " << caesar_decrypt(str, n) << std::endl;
                break;
            }
            case 13: {
                int x = get_int_input("x");
                int a = get_int_input("a");
                std::cout << "Result: " << my_pow(x, a) << std::endl;
                break;
            }
            case 14: {
                int n = get_int_input("n");
                std::cout << "Result: " << my_factorial(n) << std::endl;
                break;
            }
            case 15: {
                int n = get_int_input("n");
                std::cout << "Result: " << double_factorial(n) << std::endl;
                break;
            }
            case 16: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << (is_palindrome(str) ? "true" : "false") << std::endl;
                break;
            }
            case 17: {
                double x = get_float_input("x");
                std::cout << "Result: " << my_sqrt(x) << std::endl;
                break;
            }
            case 18: {
                std::string str = get_string_input("string");
                std::string target = get_string_input("target");
                std::string replacement = get_string_input("replacement");
                std::cout << "Result: " << find_and_replace(str, target, replacement) << std::endl;
                break;
            }
            case 19: {
                int n = get_int_input("n");
                std::cout << "Result: " << fib(n) << std::endl;
                break;
            }
            case 20: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << run_length_encode(str) << std::endl;
                break;
            }
            case 21: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << run_length_decode(str) << std::endl;
                break;
            }
            case 22: {
                std::string str1 = get_string_input("string1");
                std::string str2 = get_string_input("string2");
                std::cout << "Result: " << (are_anagram(str1, str2) ? "true" : "false") << std::endl;
                break;
            }
            case 23: {
                std::string str = get_string_input("string");
                std::cout << "Result: " << remove_duplicates(str) << std::endl;
                break;
            }
            case 24: {
                int x = get_int_input("x");
                std::cout << "Result: " << my_exp(x) << std::endl;
                break;
            }
            case 25: {
                int n = get_int_input("n");
                std::cout << "Result:\n" << make_squares(n) << std::endl;
                break;
            }
            case 26: {
                int n = get_int_input("n");
                std::cout << "Result:\n" << make_hollow_diamond(n) << std::endl;
                break;
            }
            case 27: {
                int n = get_int_input("n");
                std::cout << "Result:\n" << make_diamond(n) << std::endl;
                break;
            }
            case 28: {
                float p = get_float_input("p");
                int n = get_int_input("n");
                int k = get_int_input("k");
                std::cout << "Result: " << k_consecutive(p, n, k) << std::endl;
                break;
            }
            case 29: {
                int n = get_int_input("n");
                int g = get_int_input("g");
                float p = get_float_input("p");
                int n_heads = get_int_input("n_heads");
                int n_flips = get_int_input("n_flips");
                std::cout << "Result: " << p_unfair_coin(n, g, p, n_heads, n_flips) << std::endl;
                break;
            }
            case 30: {
                int n = get_int_input("n");
                int g = get_int_input("g");
                int turn = get_int_input("turn");
                std::cout << "Result: " << draw_all_good_cards(n, g, turn) << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
