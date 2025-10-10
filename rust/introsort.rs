// Introsort implementation in Rust (generic, in-place)
pub fn introsort<T: Ord>(arr: &mut [T]) {
    if arr.len() <= 1 { return; }
    let depth_limit = 2 * ((arr.len() as f64).log2().floor() as usize);
    introsort_impl(arr, depth_limit);
}

fn introsort_impl<T: Ord>(arr: &mut [T], mut depth_limit: usize) {
    const INSERTION_THRESHOLD: usize = 16;

    let mut low = 0usize;
    let mut high = arr.len();

    // Use a manual stack to avoid deep recursion on tail calls
    let mut stack: Vec<(usize, usize, usize)> = Vec::new();
    stack.push((low, high, depth_limit));

    while let Some((lo, hi, depth)) = stack.pop() {
        let len = hi.saturating_sub(lo);
        if len <= 1 { continue; }

        if len <= INSERTION_THRESHOLD {
            insertion_sort(&mut arr[lo..hi]);
            continue;
        }

        if depth == 0 {
            heapsort(&mut arr[lo..hi]);
            continue;
        }

        // Partition with median-of-three pivot
        let pivot_index = partition_median3(&mut arr[lo..hi]);
        // pivot_index is relative to the subslice [lo..hi]
        // push larger side first so smaller side is processed next (keeps stack small)
        let left_len = pivot_index;
        let right_len = len - pivot_index - 1;

        if left_len < right_len {
            // push right, then left
            if pivot_index + 1 < len {
                stack.push((lo + pivot_index + 1, hi, depth - 1));
            }
            if left_len > 0 {
                stack.push((lo, lo + pivot_index, depth - 1));
            }
        } else {
            if left_len > 0 {
                stack.push((lo, lo + pivot_index, depth - 1));
            }
            if pivot_index + 1 < len {
                stack.push((lo + pivot_index + 1, hi, depth - 1));
            }
        }
    }
}

fn insertion_sort<T: Ord>(slice: &mut [T]) {
    for i in 1..slice.len() {
        let mut j = i;
        while j > 0 && slice[j] < slice[j - 1] {
            slice.swap(j, j - 1);
            j -= 1;
        }
    }
}

fn partition_median3<T: Ord>(slice: &mut [T]) -> usize {
    let len = slice.len();
    let mid = len / 2;
    // choose indices 0, mid, len-1 -> median-of-three
    let (a, b, c) = (0usize, mid, len - 1);
    // reorder such that slice[a] <= slice[b] <= slice[c]
    if slice[a] > slice[b] { slice.swap(a, b); }
    if slice[b] > slice[c] { slice.swap(b, c); }
    if slice[a] > slice[b] { slice.swap(a, b); }

    // move pivot to end-1 (so we'll partition excluding last element)
    slice.swap(b, len - 1);
    let pivot_idx = len - 1;
    let mut i = 0usize;
    for j in 0..(len - 1) {
        if slice[j] <= slice[pivot_idx] {
            slice.swap(i, j);
            i += 1;
        }
    }
    slice.swap(i, pivot_idx);
    i
}

fn heapsort<T: Ord>(slice: &mut [T]) {
    let len = slice.len();
    if len <= 1 { return; }

    // build max heap
    for start in (0..=(len/2)).rev() {
        sift_down(slice, start, len);
    }

    // sortdown
    for end in (1..len).rev() {
        slice.swap(0, end);
        sift_down(slice, 0, end);
    }

    fn sift_down<T: Ord>(slice: &mut [T], start: usize, end: usize) {
        let mut root = start;
        loop {
            let left = 2 * root + 1;
            if left >= end { break; }
            let mut swap = root;
            if slice[swap] < slice[left] {
                swap = left;
            }
            let right = left + 1;
            if right < end && slice[swap] < slice[right] {
                swap = right;
            }
            if swap == root { break; }
            slice.swap(root, swap);
            root = swap;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_introsort_simple() {
        let mut v = vec![3, 1, 4, 1, 5, 9, 2, 6, 5];
        introsort(&mut v);
        assert_eq!(v, {
            let mut t = vec![1,1,2,3,4,5,5,6,9];
            t
        });
    }

    #[test]
    fn test_introsort_sorted() {
        let mut v: Vec<i32> = (0..100).collect();
        introsort(&mut v);
        assert_eq!(v, (0..100).collect::<Vec<i32>>());
    }

    #[test]
    fn test_introsort_reverse() {
        let mut v: Vec<i32> = (0..100).rev().collect();
        introsort(&mut v);
        assert_eq!(v, (0..100).collect::<Vec<i32>>());
    }
}
