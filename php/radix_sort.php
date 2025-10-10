<?php

function countingSortByDigit(&$arr, $exp) {
    $n = count($arr);
    $output = array_fill(0, $n, 0);
    $count = array_fill(0, 10, 0);

    // Count occurrences of digits
    for ($i = 0; $i < $n; $i++) {
        $digit = intdiv($arr[$i], $exp) % 10;
        $count[$digit]++;
    }

    // Cumulative count
    for ($i = 1; $i < 10; $i++) {
        $count[$i] += $count[$i - 1];
    }

    // Build output array
    for ($i = $n - 1; $i >= 0; $i--) {
        $digit = intdiv($arr[$i], $exp) % 10;
        $output[$count[$digit] - 1] = $arr[$i];
        $count[$digit]--;
    }

    // Copy output to original array
    for ($i = 0; $i < $n; $i++) {
        $arr[$i] = $output[$i];
    }
}

function radixSort(&$arr) {
    // Find the maximum number
    $max = max($arr);

    // Do counting sort for every digit
    $exp = 1;
    while (intdiv($max, $exp) > 0) {
        countingSortByDigit($arr, $exp);
        $exp *= 10;
    }
}

// Example usage
$arr = [170, 45, 75, 90, 802, 24, 2, 66];
radixSort($arr);
echo "Sorted array: " . implode(", ", $arr) . "\n";
