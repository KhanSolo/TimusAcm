use std::io;

fn main() {
    let input = io::stdin();

    let mut line = String::new();
    input.read_line(&mut line).unwrap();

    let count : u32 = line.trim().parse().unwrap();

    let mut has_three = false;
    let mut only_fives = true;

    let mut sum : u32 = 0;

    for _ in 0..count {
        let mut line = String::new();
        input.read_line(&mut line).unwrap();
        let mark : u32 = line.trim().parse().unwrap();
        sum = sum + mark;
        if mark == 3 {
            has_three = true;
        }
        if mark != 5 {
            only_fives = false;
        }
    }

    let avg = (sum as f32) / (count as f32);

    if has_three {
        println!("None");
    } else
    if only_fives {
        println!("Named");
    } else
    if avg >= 4.5 {
        println!("High");
    } else {
        println!("Common");
    }
    //println!("{}", avg);
}
