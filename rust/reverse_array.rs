fn main() {
    let mut arr = [1, 2, 3, 4, 5];
    let n = arr.len();

    for i in 0..n / 2 {
        arr.swap(i, n - i - 1);
    }

    println!("Reversed Array: {:?}", arr);
}
