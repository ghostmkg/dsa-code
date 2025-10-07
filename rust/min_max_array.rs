fn main() {
    let arr = [45, 12, 67, 23, 89, 34];
    let mut max = arr[0];
    let mut min = arr[0];

    for &val in arr.iter() {
        if val > max { max = val; }
        if val < min { min = val; }
    }

    println!("Max = {}, Min = {}", max, min);
}
