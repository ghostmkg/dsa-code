fn rotate_right(arr: &mut [i32], k: usize) {
    let n = arr.len();
    arr.rotate_right(k % n);
}

fn main() {
    let mut arr = [1, 2, 3, 4, 5];
    rotate_right(&mut arr, 2);
    println!("After Rotation: {:?}", arr);
}
