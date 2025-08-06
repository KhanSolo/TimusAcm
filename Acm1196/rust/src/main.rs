fn main() {
    let cnt = read_u32();

    let mut map = Vec::with_capacity(cnt as usize);
    let mut prev:  Option<u32> = None;
    for _ in 0..cnt {
        let year = read_u32();

        match prev {
            Some(prev_year) => {
                if prev_year < year {
                    map.push(year);
                    prev = Some(year);
                }
            },
            None => {
                map.push(year);
                prev = Some(year);
            },
        }        
    }

    let cnt = read_u32();
    let mut sum = 0u32;
    for _ in 0..cnt {
        let year = read_u32();
        match bnr_srch(&map, year){
            Some(_) => sum += 1,
            None => (),
        }
    }

    println!("{}", sum);
}

fn read_u32() -> u32 {
    let mut input = String::with_capacity(16); // todo move outside to reduce memory consumption
    std::io::stdin().read_line(&mut input).ok();
    let cnt = input.trim().parse::<u32>().expect("cannot parse");
    cnt
} 

fn bnr_srch(arr: &[u32], x: u32) -> Option<u32> { 
    if arr.len() == 0 { return None; }

    let (mut l, mut r) = (0usize, arr.len());

    while l < r {
        let m = l + (r-l)/2;
        if arr[m] == x {
            return Some(m as u32);
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