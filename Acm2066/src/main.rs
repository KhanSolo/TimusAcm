use std::io;
use std::cmp;

fn main() {
    let mut array: [i32; 3] = [0; 3];

    for i in 0..3 {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let parsed : i32 = line.trim().parse().unwrap();
        array[i] = parsed;
    }
    //array.sort(); ???
    let min1 = array[0]-array[1]-array[2];
    let min2 = array[0]-array[1]*array[2];

    let min = cmp::min(min1,min2);

    println!("{}", min);
}
