fn main() {
    let mut input = String::with_capacity(16);
    let cnt = read_u32(&mut input);

    let mut map = Vec::with_capacity(cnt as usize);
    let mut prev:  Option<u32> = None;
    for _ in 0..cnt {
        let year = read_u32(&mut input);

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

    let cnt = read_u32(&mut input);
    let mut sum = 0u32;
    for _ in 0..cnt {
        let year = read_u32(&mut input);
        let a = map.binary_search(&year);
        match a {
            Ok(_) => sum+=1,
            Err(_) => (),
        }
    }

    println!("{}", sum);
}

fn read_u32(input:&mut String) -> u32 {
    input.clear();
    std::io::stdin().read_line(input).ok();

    trim_newline(input);
    let cnt = input.parse::<u32>().expect("cannot parse");

    cnt
}

fn trim_newline(s: &mut String) {
    if s.ends_with('\n') {
        s.pop();
        if s.ends_with('\r') {
            s.pop();
        }
    }
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