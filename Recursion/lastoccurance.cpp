#include <iostream>
using namespace std;

int lastOccurrence(int arr[], int size, int index, int target) {
    // Base case: reached end of array
    if (index == size) return -1;

    // Recurse first for the rest of the array (go deeper)
    int restResult = lastOccurrence(arr, size, index + 1, target);

    // If found in later part of array, that's the last occurrence
    if (restResult != -1) return restResult;

    // Otherwise check current index
    if (arr[index] == target) return index;

    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 2, 9, 2};
    int size = 6;

    cout << lastOccurrence(arr, size, 0, 2);  // Output: 5
    return 0;
}