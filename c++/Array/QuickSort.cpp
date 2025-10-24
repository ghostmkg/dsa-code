#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // choose the last element as pivot
    int i = low - 1;       // pointer for smaller element

    for (int j = low; j < high; j++)
    {
        // if current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive QuickSort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // find the partition index
        int pi = partition(arr, low, high);

        // recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
