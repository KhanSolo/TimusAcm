use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let sum: u64 = line
        .split_whitespace()
        .map(|f| f.parse::<u64>().unwrap())
        .sum();

    println!("{sum}");
}
