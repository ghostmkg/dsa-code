import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class BucketSort {
    public static void bucketSort(double[] arr) {
        int n = arr.length;
        if (n <= 0) return;
        List<List<Double>> buckets = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            buckets.add(new ArrayList<>());
        }
        for (double value : arr) {
            int bucketIndex = (int) (value * n); 
            if (bucketIndex >= n) bucketIndex = n - 1;
            buckets.get(bucketIndex).add(value);
        }
         for (List<Double> bucket : buckets) {
            Collections.sort(bucket);
        }
        int idx = 0;
        for (List<Double> bucket : buckets) {
            for (double num : bucket) {
                arr[idx++] = num;
            }
        }
    }
    /**
     * Usage Example: Demonstrates bucket sort on an array of doubles in [0, 1).
     */
    public static void main(String[] args) {
        double[] data = {0.42, 0.32, 0.23, 0.52, 0.5, 0.47, 0.3, 0.89, 0.1, 0.15};

        System.out.println("Before Sorting:");
        for (double d : data) {
            System.out.print(d + " ");
        }
        System.out.println();
        bucketSort(data);

        System.out.println("After Sorting:");
        for (double d : data) {
            System.out.print(d + " ");
        }
        System.out.println();
    }
}