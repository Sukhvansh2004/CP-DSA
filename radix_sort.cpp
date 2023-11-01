#include <iostream>
#include <vector>

// Find the maximum element in the array
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort for a particular digit (exp)
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

// Radix Sort implementation
void radixSort(std::vector<int>& arr) {
    // Find the maximum element to determine the number of digits
    int max = findMax(arr);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    std::cout << "Original array: ";
    printArray(arr);

    radixSort(arr);
    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
