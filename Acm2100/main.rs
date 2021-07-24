use std::io;

fn main() {
    let count: u32;
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        count = line.trim().parse::<u32>().unwrap();
    }

    let mut guests_count: u32 = 2;
    for _ in 0..count {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        guests_count = guests_count + if line.contains("+") { 2 } else { 1 };
    }

    let result = if guests_count == 13 {
        guests_count + 1
    } else {
        guests_count
    } * 100;

    println!("{}", result);
}
