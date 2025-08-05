use std::io;
use std::io::Read;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read input");

    let nums : Vec<u64> = input
        .split_whitespace()
        .filter_map(|f| f.parse::<u64>().ok())
        .collect::<Vec<u64>>();

    for n in nums.into_iter().rev() {
        println!("{:.4}", (n as f64).sqrt());
    }
}
