#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {34, 2, 12, 43, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void quick_sort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = arr[start];
    int j = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);
}

int main() {
    int *arr = new int[5]{34, 2, 12, 43, 5};
    quick_sort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
    delete[] arr; // Remember to deallocate the memory allocated with new[]
    return 0;
}
