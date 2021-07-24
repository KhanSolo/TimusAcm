use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let split = line.trim().split(" ");
    let vec = split.collect::<Vec<&str>>();
    let n = vec[0].parse::<u32>().unwrap();
    let k = vec[1].parse::<u32>().unwrap();

    let result = if n <= k { 2 } else { (2 * n + k - 1) / k };
    println!("{}", result);
}
