use std::io;

fn main() {
    let cnt = read_u32();

    for i in 0..cnt {
        println!("i {}", i);
    }

}

fn read_u32() -> u32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).ok();
    let cnt = input.trim().parse::<u32>().expect("cannot parse");
    cnt
} 

fn binary_search() -> u32 { 0 }