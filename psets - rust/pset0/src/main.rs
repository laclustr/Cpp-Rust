#![allow(dead_code)]
#![allow(non_snake_case)]

//Problem 1
fn rect_area(length: u32, width: u32) -> u32 {
    length * width
}

//Problem 2
fn circ_area(radius: f64) -> f64 {
    radius * radius * 3.14
}

//Problem 3
fn cylinder_area(radius: u32, height: u32) -> f64 {
    let radius = radius as f64;
    let height = height as f64;
    let result: f64 = radius * height * 3.14 * 2.0;
    return result + 2.0 * 3.14 * radius * radius;
}

//Problem 4
fn sphere_surface_area(radius: u32) -> f64 {
    let radius = radius as f64;
    return radius * radius * 3.14 * 4.0;
}

//Problem 5
fn sum_double(a: i32, b: i32) -> i32 {
    if a == b {
        return (a + b) * 2;
    }

    return a + b;
}

//Problem 6
fn in_range(num1: i32, num2: i32) -> bool {
    if (num1 >= 20 && num1 <= 30) && (num2 >= 20 && num2 <= 30) {
        return true;
    }
    if (num1 >= 90 && num1 <= 100) && (num2 >= 90 && num2 <= 100) {
        return true;
    }

    return false;
}

//Problem 7
fn distance(x: i32, y: i32) -> f64 {
    let x = x as f64;
    let y = y as f64;
    return ((x * x) + (y * y)).sqrt();
}

//Problem 8
fn open_gate(workday: bool, gate_activated: bool, gate_up: bool) -> bool {
    if workday && gate_activated && !gate_up {
        return true;
    }
    return false;
}

//Problem 9
fn has_discount(age: u32, had_accident: bool) -> bool {
    if age >= 24 && !had_accident {
        return true;
    }
    return false;
}

//Problem 10
fn should_apply(gpa: f32, act_score: u8) -> bool {
    if gpa >= 3.9 && act_score > 31 {
        return true;
    }
    if gpa >= 4.25 || act_score >= 34 {
        return true;
    }
    return false;
}

//Problem 11
fn oil_light(miles: u32, days: u32) -> bool {
    if miles >= 10_000 || days > 365 {
        return true;
    }

    return false;
}

//Problem 12
fn abs_val(x: i32) -> i32 {
    if x < 0 {
        return x * -1;
    }
    return x;
}
//End Problem 12

fn min_num(a: i32, b: i32) -> i32 {
    if a < b {
        return a;
    } else {
        return b;
    }
}

//Problem 13
fn closest_tens(a: i32, b: i32) -> i32 {
    let a_rem: i32 = min_num(a % 10, 10 - (a % 10));
    let b_rem: i32 = min_num(b % 10, 10 - (b % 10));

    if a_rem < b_rem {
        return a;
    } else if a_rem > b_rem {
        return b;
    } else {
        return a;
    }
}

//Problem 14
fn get_ticket_price(price: impl Into<f64>, flying_soon: bool, open_seat_pct: impl Into<f64>) -> f64 {
    let price = price.into();
    let open_seat_pct = open_seat_pct.into();

    if !flying_soon {
        if open_seat_pct < 0.25 {
            return price * 1.25;
        }
        return price;
    }
    if open_seat_pct > 0.5 {
        return price * 0.85;
    } else if open_seat_pct < 0.1 {
        return price * 1.4;
    }
    return price;
}

//Problem 15
fn is_special(num: i32) -> bool {
    let last_num: i32 = num % 10;
    if last_num == 2 || last_num == 4 || last_num == 8 {
        return true;
    }
    return false;
}

//Problem 16
fn rev_num(n: i32) -> i32 {
    let mut n = n;
    let mut result = String::new();

    result += &(n % 10).to_string();
    n /= 10;

    result += &(n % 10).to_string();
    n /= 10;

    result += &n.to_string();

    return result.parse::<i32>().unwrap();
}

//Problem 17
fn is_leap_year(year: i32) -> bool {
    if year % 400 == 0 {
        return true;
    }
    if year % 4 == 0 && year % 100 != 0 {
        return true;
    }
    return false;
}
//End Problem 17

fn first_day_num(year: i32) -> i32 {
    let mut y = year;
    let mut m = 13;

    if m < 3 {
        y -= 1;
        m += 12;
    }

    let k = y % 100;
    let j = y / 100;

    let h = (1 + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

    (h + 6) % 7
}

//Problem 18
fn first_day(year: i32) -> String {
    let day_num = first_day_num(year);

	if day_num == 0 {
        return "Sunday".to_string();
    } else if day_num == 1 {
        return "Monday".to_string();
    } else if day_num == 2 {
        return "Tuesday".to_string();
    } else if day_num == 3 {
        return "Wednesday".to_string();
    } else if day_num == 4 {
        return "Thursday".to_string();
    } else if day_num == 5 {
        return "Friday".to_string();
    } else if day_num == 6 {
        return "Saturday".to_string();
    } else {
        return day_num.to_string();
    }
}

//Problem 19
fn day_of_year(month: i32, day: i32, year: i32) -> i32 {
	let mut daysBefore = 0;

	if month > 1 {
		daysBefore += 31;
	} if month > 2 {
		if is_leap_year(year) {
			daysBefore += 29;
		} else {
			daysBefore += 28;
		}
	} if month > 3 {
		daysBefore += 31;
	} if month > 4 {
		daysBefore += 30;
	} if month > 5 {
		daysBefore += 31;
	} if month > 6 {
		daysBefore += 30;
	} if month > 7 {
		daysBefore += 31;
	} if month > 8 {
		daysBefore += 31;
	} if month > 9 {
		daysBefore += 30;
    } if month > 10 {
		daysBefore += 31;
    } if month > 11 {
		daysBefore += 30;
    }

	return daysBefore + day;
}

//Problem 20
fn day_of_week(month: i32, day: i32, year: i32) -> String{
	let firstDay = first_day_num(year);
	let dayOfYear = day_of_year(month, day, year);
	let dayNum = (firstDay + (dayOfYear - 1)) % 7;

	if dayNum == 0 {
		return "Sunday".to_string();
	} else if dayNum == 1 {
		return "Monday".to_string();
	} else if dayNum == 2 {
		return "Tuesday".to_string();
	} else if dayNum == 3 {
		return "Wednesday".to_string();
	} else if dayNum == 4 {
		return "Thursday".to_string();
	} else if dayNum == 5 {
		return "Friday".to_string();
	} else if dayNum == 6 {
		return "Saturday".to_string();
	} else {
	    return dayNum.to_string();
	}
}

fn main() {
    println!("{}", first_day(2000));
}
