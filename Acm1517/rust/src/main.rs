use std::collections::{HashMap, HashSet};

const MOD: u64 = 1_000_000_007;
const BASE: u64 = 911;

// Предвычисление степеней BASE по модулю MOD
fn compute_powers(len: usize) -> Vec<u64> {
    let mut power = vec![1; len + 1];
    for i in 1..=len {
        power[i] = (power[i - 1] * BASE) % MOD;
    }
    power
}

// Возвращает множество хешей и позиции начала подстрок длины `length`
fn compute_hashes(s: &str, length: usize, power: &[u64]) -> (HashSet<u64>, HashMap<u64, usize>) {
    let s_bytes = s.as_bytes();
    let n = s.len();
    let mut h: u64 = 0;
    let mut hashes = HashSet::new();
    let mut hash_to_pos = HashMap::new();

    if length == 0 || length > n {
        return (hashes, hash_to_pos);
    }

    for i in 0..length {
        h = (h * BASE + s_bytes[i] as u64) % MOD;
    }
    hashes.insert(h);
    hash_to_pos.insert(h, 0);

    for i in length..n {
        let left = s_bytes[i - length] as u64;
        h = ((h + MOD - (left * power[length - 1]) % MOD) * BASE + s_bytes[i] as u64) % MOD;
        hashes.insert(h);
        hash_to_pos.insert(h, i - length + 1);
    }

    (hashes, hash_to_pos)
}

// Основная функция: наибольшая общая подстрока
fn longest_common_substring(s1: &str, s2: &str) -> String {
    let max_len = s1.len().min(s2.len());
    let power = compute_powers(max_len);

    let (mut low, mut high) = (0, max_len);
    let mut best_len = 0;
    let mut best_substr = String::new();

    while low <= high {
        let mid = (low + high) / 2;
        let (hashes1, pos1) = compute_hashes(s1, mid, &power);
        let (hashes2, pos2) = compute_hashes(s2, mid, &power);

        let common_hash = hashes1.intersection(&hashes2).next().cloned();
        if let Some(h) = common_hash {
            best_len = mid;
            let start = pos1[&h];
            best_substr = s1[start..start + mid].to_string();
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    best_substr
}