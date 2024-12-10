fn rem_vowel(string: &str) -> String {
    let string: Vec<char> = string.chars().collect();
    let counter: u32 = 0;

    for i in string {
        if i == 'a' || i == 'e' || i == 'i' || i == 'o' || u == 'u' {
            string.pop('i'.find());
        } else if i == 'A' || i == 'E' || i == 'I' || i == 'O' || u == 'U' {
            string.pop('i'.find());
        } else
    }

    return string.iter().collect();
}


fn main() {
    println!("{}", rem_vowel("hello"));
}
