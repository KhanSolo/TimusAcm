use std::io::{self, Read};
use std::collections::HashSet;

fn main() {
    // Read ALL input into String
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("Failed to read input");

    // Splitting and parsing
    let mut numbers = input
        .split_whitespace()
        .map(|s| s.parse::<u32>().expect("Invalid number"));

    // First number — capaacity of set
    let cnt = numbers.next().unwrap();
    let mut set = HashSet::with_capacity(cnt as usize);
    let mut prev = None;

    // Filling set (non-repeatable years)
    for _ in 0..cnt {
        let year = numbers.next().unwrap();
        if prev.map_or(true, |p| p < year) {
            set.insert(year);
            prev = Some(year);
        }
    }

    // Next num — number of queries
    let query_cnt = numbers.next().unwrap();
    let mut sum = 0;

    // Handling with contains (O(1))
    for _ in 0..query_cnt {
        let year = numbers.next().unwrap();
        if set.contains(&year) {
            sum += 1;
        }
    }

    println!("{}", sum);
}