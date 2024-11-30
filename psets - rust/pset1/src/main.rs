#![allow(dead_code)]
#![allow(non_snake_case)]


//Problem 1
fn count_e(string: String) -> u32 {
    let mut counter: u32 = 0;

    for i in string.chars() {
        if i == 'e' || i == 'E' {
            counter += 1;
        }
    }
    counter
}

//Problem 2
fn ends_with(string: &str, substring: &str) -> bool {
    let diff: usize = string.len() - substring.len();

    if &string[diff..] == substring {
        return true;
    }
    return false;
}

//Problem 3
fn reverse_string(string: &str) -> String {
    let mut result: String = String::new();

    for i in string.chars() {
        result = i.to_string() + &result;
    }
    return result;
}

//Problem 4
fn sum_between(a: i32, b: i32) -> i32 {
    let mut sum: i32 = 0;

    for i in a..b + 1 {
        sum += i;
    }

    return sum;
}

//Problem 5
fn index_of(string: &str, substring: &str) -> i32 {
    if substring.len() > string.len() {
            return -1;
    }

    for i in 0..string.len() - substring.len() + 1 {
        if &string[i..i + substring.len()] == substring {
            return i as i32;
        }
    }
    return -1;
}

//Problem 6
fn count_long_char(string: &str) -> u32 {
    let mut max_len: u32 = 1;
	let mut curr_len: u32 = 1;
	let chars: Vec<char> = string.chars().collect();

    for i in 1..chars.len() {
        if chars[i] == chars[i - 1] {
			curr_len += 1;
			if curr_len > max_len {
				max_len = curr_len;
			}
        } else {
			curr_len = 1;
        }
    }

	return max_len;
}

//Problem 7
fn is_good_password(password: &str) -> bool {
    let mut caps = false;
    let mut lower = false;
    let mut special = false;

    for i in password.chars() {
        let asc = i as u8;

        if asc >= 65 && asc <= 90 {
			caps = true;
        } else if asc >= 97 && asc <= 122 {
			lower = true;
        } else if (asc >= 33 && asc <= 47)
			|| (asc >= 58 && asc <= 64)
			|| (asc >= 91 && asc <= 96)
			|| (asc >= 123 && asc <= 126) {
			special = true;
		}

		if special && caps && lower {
		    return true;
		}
    }
    return false;
}

//Problem 8
fn harshad_numbers(n: i32) -> i32 {
    let mut count: i32 = 0;

	for i in 1..n + 1 {
		let mut lnum: i32 = 0;
		let mut tnum: i32 = i;

		while tnum > 0 {
			lnum += tnum % 10;
			tnum /= 10;
		}

		if i % lnum == 0 {
			count += 1;
		}
	}
	return count;
}

//Problem 9
fn count_digits(mut n: i32) -> i32 {
    if n < 0 {
		n = n * -1;
    }

	if n < 10 {
		return 1;
	}

	let mut count = 0;

	while n > 0 {
		n = n / 10;
		count += 1;
	}

	return count;
}

//Problem 10
fn upper_string(string: &str) -> String {
    let mut result = String::new();

    for i in string.chars() {
        let asc = i as u8;
        if !(asc >= 97 && asc <= 122) {
            result += &i.to_string();
        } else {
            result += &((asc - 32) as char).to_string();
        }
    }

    return result;
}

//Problem 11
fn caesar_encrypt(string: &str, n: u8) -> String {
    let string = String::from(upper_string(string));
    let mut result = String::new();

    for i in string.chars() {
        let asc = i as u8;
		if !(asc >= 65 && asc <= 90) {
			result += &i.to_string();
		} else {
			let mut shift = asc + n;
			if shift > 90 {
				shift = (shift - 91) + 65;
			}
			result += &(shift as char).to_string();
		}
	}
	return result;
}

//Problem 12
fn caesar_decrypt(string: &str, n: u8) -> String {
    let string = String::from(upper_string(string));
    let mut result = String::new();

    for i in string.chars() {
        let asc = i as u8;
		if !(asc >= 65 && asc <= 90) {
			result += &i.to_string();
		} else {
			let mut shift = asc - n;
			if shift < 65 {
				shift += 26;
			}
			result += &(shift as char).to_string();
		}
	}
	return result;
}

//Problem 13
fn my_pow(x: i32, mut a: i32) -> i32 {
	let mut result = 1;
	while a > 0 {
		result *= x;
		a -= 1;
	}
	return result;
}

//Problem 14
fn my_factorial(n: i32) -> i32 {
    let mut result = 1;

	if n == 0 {
		return result;
	}

	for i in 1..n + 1 {
		result *= i;
	}

	return result;
}

//Problem 15
fn double_factorial(n: i32) -> i32 {
	let mut result = 1;

	if n == 0 || n == 1 {
		return result;
	}

	for i in (n..0).rev().step_by(2) {
		result *= i;
	}

	return result;
}

//Problem 16
fn is_palindrome(string: &str) -> bool {
    return &reverse_string(string) == string;
}

//Problem 17
fn my_sqrt(x: i32) -> f64 {
    let x = x as f64;
    let mut t: f64 = x;

    while (t * t - x).abs() > 1e-15 {
		t = (t + x / t) / 2.0;
    }

    return t;
}

//Problem 18
fn find_and_replace(string: &str, target: &str, replacement: &str) -> String {
    let mut result = String::new();
    let string: Vec<char> = string.chars().collect();
    let target: Vec<char> = target.chars().collect();

    let mut i = 0;
    while i < string.len() {
        let mut fmatch = true;

        for j in 0..target.len() {
            if i + j >= string.len() || string[i + j] != target[j] {
                fmatch = false;
                break;
            }
        }

        if fmatch {
            result += replacement;
            i += target.len();
        } else {
            result += &string[i].to_string();
            i += 1;
        }
    }

	return result;
}

//Problem 19
fn fib(n: u32) -> u32{
    if n == 1 {
		return 1;
    }

	let mut num1 = 0;
	let mut num2 = 1;

	let mut i = 2;

	while i <= n {
		let temp = num2;
		num2 += num1;
		num1 = temp;

		i += 1;
	}

	return num2;
}

//Problem 20
fn run_length_encode(string: &str) -> String {
    let string: Vec<char> = string.chars().collect();
	let mut result = String::new();
	let mut count = 1;

	for i in 1..string.len() {
		if string[i] == string[i - 1] {
			count += 1;
		} else {
			result += &string[i - 1].to_string();
			result += &count.to_string();
			count = 1;
		}
	}

	result += &string[string.len() - 1].to_string();
	result += &count.to_string();

	return result;
}

//Problem 21
fn run_length_decode(string: &str) -> String {
    let string: Vec<char> = string.chars().collect();
	let mut result = String::new();

	for i in (0..string.len()).step_by(2) {
	    for _ in 0..string[i + 1].to_digit(10).unwrap() {
			result += &string[i].to_string()
		}
	}
	return result;
}

//Problem 22
fn are_anagrams(string1: &str, string2: &str) -> bool {
    if string1.len() != string2.len() {
        return false;
    }

    let mut string1 = string1.to_string();
    let mut string2 = string2.to_string();

    let chars: Vec<char> = string1.chars().collect();

    for i in chars {

		if index_of(&string1, &i.to_string()) >= 0 {
			string1 = find_and_replace(&string1, &i.to_string(), "");
			if index_of(&string2, &i.to_string()) >= 0 {
				string2 = find_and_replace(&string2, &i.to_string(), "");
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	return true;
}

//Problem 23
fn remove_duplicates(string: &str) -> String {
    let mut seen = String::new();
	let mut result = String::new();

	for i in string.chars() {
		if index_of(&seen, &i.to_string()) == -1 {
			seen += &i.to_string();
			result += &i.to_string();
		}
	}

	return result
}

//Problem 24
fn my_exp(x: i32) -> f64 {
    let x = x as f64;
    let mut result: f64 = 1.0;
	let mut term: f64 = 1.0;
	let mut iterations: u32 = 1;

	while term.abs() >= 10e-15 {
		let mut powxk: f64 = 1.0;
		let mut factk: f64 = 1.0;

		for j in 1..iterations + 1 {
		    let i = j as f64;
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

fn strmul(string: &str, n: u32) -> String {
    let mut result = String::new();
    for _ in 0..n {
        result += string;
    }
    return result;
}

//Problem 25
fn make_squares(n: u32) -> String {
    let mut first = true;
	let mut iterations = n;
	let mut result = String::new();

	while iterations > 1 {
		if first {
			result += &(strmul("*", n) + " " + &strmul("*", n) + "\n");
			first = false;
		} else {
			result += &(strmul("*", n) + " " + "*" + &strmul(" ", n - 2) + "*" + "\n");
		}
		iterations -= 1;
	}

	result += &(strmul("*", n) + " " + &strmul("*", n));
	return result;
}

//Problem 26
fn make_hollow_diamond(n: u32) -> String {
	let mut result = String::new();
	let iterations: u32 = n;

	for i in 0..iterations {
		let mut row = strmul(" ", iterations - i - 1);

		if i == 0 {
			row += "*";
		} else {
			row += &("*".to_owned() + &strmul(" ", 2 * i - 1) + "*");
		}

		result += &(row.to_string() + "\n");
	}

	for i in (0..iterations - 1).rev() {
		let mut row = strmul(" ", iterations - i - 1);

		if i == 0 {
			row += "*";
		} else {
			row += &("*".to_owned() + &strmul(" ", 2 * i - 1) + "*");
		}

		result += &(row + "\n");
	}

	return result;
}

//Problem 27
fn make_diamond(n: u32) -> String {
	let mut result = String::new();
	let iterations: u32 = n;

	for i in 0..iterations {
		let mut row = strmul(" ", iterations - i - 1);

		row += &strmul("*", 2 * i + 1);

		result += &(row + "\n");
	}

	for i in (0..iterations - 1).rev() {
	    let mut row = strmul(" ", iterations - i - 1);

		row += &strmul("*", 2 * i + 1);

		result += &(row + "\n");
	}

	return result;
}
//End Problem 27

use rand::Rng;

fn rng() -> f64 {
    return rand::thread_rng().gen();
}

//Problem MC1
fn k_consecutive(p: f64, n: u32, k: u32) -> f64 {
	let simulations: u64 = 1_000_000;
	let mut successes: u64 = 0;

	for _ in 0..simulations {
		let mut heads: u32 = 0;
		let mut enoughHeads = false;

		for _ in 0..n {
			if rng() < p {
				heads += 1;

				if heads >= k {
					enoughHeads = true;
				}
			} else {
				heads = 0;
			}
		}

		if enoughHeads {
			successes += 1;
		}
	}

	return successes as f64 / simulations as f64;
}

//Problem MC2
fn p_unfair_coin(n: u32, g: u32, p: f32, n_heads: u32, n_flips: u32) -> f64 {
	let simulations: u32 = 1_000_000;
	let biCoins: u32 = n - g;

	let mut biCounter: u32 = 0;
	let mut tCounter: u32 = 0;

	for _ in 0..simulations {
		let biased: bool = rng() < (biCoins as f64 / n as f64);
		let mut probHead: f64 = p as f64;

		if !biased {
			probHead = 0.5;
		}

		let mut headCount: u32 = 0;

		for _ in 0..n_flips {
			if rng() < probHead {
				headCount += 1;
			}
		}

		if headCount == n_heads {
			tCounter += 1;

			if biased {
				biCounter += 1;
			}
		}
	}

	if tCounter == 0 {
		return 0.0;
	}

	return biCounter as f64 / tCounter as f64;
}

//Problem MC3
fn draw_all_good_cards(n: u32, g: u32, turn: u32) -> f64 {
	let simulations: u32 = 1000000;
	let mut successes: u32 = 0;

	for _ in 0..simulations {
		let mut bCards: u32 = n - g;
		let mut gCards: u32 = g;

		let mut gCardDraws: u32 = 0;

		for _ in 0..turn {
			if rng() < gCards as f64 / (gCards + bCards) as f64 {
				gCardDraws += 1;
				gCards -= 1;
			} else {
				bCards -= 1;
			}
		}

		if gCardDraws == g {
			successes += 1;
		}
	}

	return successes as f64 / simulations as f64;
}

fn main() {
    println!("{}", draw_all_good_cards(10, 3, 7));
}
