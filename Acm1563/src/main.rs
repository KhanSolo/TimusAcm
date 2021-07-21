use std::io;
use std::collections::HashSet;

fn main() {
    let input = io::stdin();

    let mut line = String::new();
    input.read_line(&mut line).unwrap();

    let count : u32 = line.trim().parse().unwrap();

    let mut bayan = 0;

    let mut set: HashSet<String> = HashSet::new();
    for _ in 0..count {
        let mut line = String::new();
        input.read_line(&mut line).unwrap();
        
        if set.contains(&line){
            bayan = bayan + 1;
        } else {
            set.insert(line);
        }
    }

    println!("{}", bayan);
}
