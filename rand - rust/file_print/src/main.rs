use std::env;
use std::fs::File;
use std::io::{self, Read};
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 3 {
        eprintln!("Usage: {} <file_path> <word>", args[0]);
        process::exit(1);
    }

    let file_path = &args[1];
    let word = &args[2];

    match count_word_occurrences(word, file_path) {
        Ok(counter) => println!("The total occurrences of the word \"{}\" in your file is: {}", word, counter),
        Err(err) => {
            eprintln!("Error reading file {}: {}", file_path, err);
            process::exit(1);
        }
    }
}

fn count_word_occurrences(word: &str, path: &str) -> Result<usize, io::Error> {
    let mut file = File::open(path)?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;

    let mut counter = 0;
    let mut start = 0;

    while let Some(pos) = contents[start..].find(word) {
        counter += 1;
        start += pos + word.len();
    }

    Ok(counter)
}

fn count_char_occurrences(chr: char, strng: &str) -> usize {
    let mut count = 0;
    let mut start = 0;

    while let Some(pos) = strng[start..].find(chr) {
        count += 1;
        start += pos + 1;
    }

    return count;
}

fn extract_domain(email: &str) -> Option<String> {
    if let Some(pos) = email.find('@') {
        return Some(email[pos + 1..].to_string());
    } else {
        return None;
    }
}
