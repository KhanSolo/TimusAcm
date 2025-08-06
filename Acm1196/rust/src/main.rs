use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut reader = stdin.lock(); // lock for faster read
    let mut buf = String::new();

    // read elements count for map
    let cnt = read_u32(&mut reader, &mut buf);
    let mut map = Vec::with_capacity(cnt as usize);

    let mut prev = None;
    for _ in 0..cnt {
        let year = read_u32(&mut reader, &mut buf);
        if prev.map_or(true, |prev_year| prev_year < year) {
            map.push(year);
            prev = Some(year);
        }
    }

    // matching
    let cnt = read_u32(&mut reader, &mut buf);
    let mut sum = 0;
    for _ in 0..cnt {
        let year = read_u32(&mut reader, &mut buf);
        if let Ok(_) = map.binary_search(&year) {
            sum += 1;
        }
    }

    println!("{}", sum);
}

// Read u32 from reader, skip non numbers
fn read_u32(reader: &mut impl BufRead, buf: &mut String) -> u32 {
    buf.clear();
    reader.read_line(buf).expect("Failed to read line");
    buf.trim_end().parse().expect("Not a number")
}

fn bnr_srch(arr: &[u32], x: u32) -> Option<usize> { 
    if arr.len() == 0 { return None; }

    let (mut l, mut r) = (0usize, arr.len());

    while l < r {
        let m = l + (r-l)/2;
        if arr[m] == x {
            return Some(m);
        }
        if arr[m] > x {
            r = m;
        } else {
            l = m + 1;
        }        
    }
    None
 }

 #[cfg(test)]
 mod tests{
    use super::*;

    #[test]
    fn binary_search_found(){
        // Arrange
        let map = vec![1054u32, 1492];

        // Act
        let result = bnr_srch(&map, 1492u32);

        // Assert
        assert_eq!(result, Some(1));
    }

    #[test]
    fn binary_search_not_found_big(){
        // Arrange
        let map = vec![1054u32, 1492];

        // Act
        let result = bnr_srch(&map, 65536u32);

        // Assert
        assert_eq!(result, None);
    }

    #[test]
    fn binary_search_not_found_small(){
        // Arrange
        let map = vec![1054u32, 1492];

        // Act
        let result = bnr_srch(&map, 100u32);

        // Assert
        assert_eq!(result, None);
    }

    #[test]
    fn binary_search_empty_map(){
        // Arrange
        let map:Vec<u32> = vec![];

        // Act
        let result = bnr_srch(&map, 100u32);

        // Assert
        assert_eq!(result, None);
    }    
 }