use std::io::{self, Read};

fn main() {
    // Read ALL input to String
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("Failed to read input");

    // split and parse
    let mut numbers = input
        .split_whitespace()
        .map(|s| s.parse::<u32>().expect("Invalid number"));

    // map count (1st number)
    let cnt = numbers.next().unwrap();
    let mut map = Vec::with_capacity(cnt as usize);
    let mut prev = None;

    // fill map
    for _ in 0..cnt {
        let year = numbers.next().unwrap();
        if prev.map_or(true, |p| p < year) {
            map.push(year);
            prev = Some(year);
        }
    }

    // get amount
    let query_cnt = numbers.next().unwrap();
    let mut sum = 0;

    // handling with binary_search
    for _ in 0..query_cnt {
        let year = numbers.next().unwrap();
        if map.binary_search(&year).is_ok() {
            sum += 1;
        }
    }

    println!("{}", sum);
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