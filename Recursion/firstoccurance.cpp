#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int size, int index, int target) {
    // Base case: reached end of array, not found
    if (index == size) return -1;

    // Found the target
    if (arr[index] == target) return index;

    // Move forward
    return firstOccurrence(arr, size, index + 1, target);
}

int main() {
    int arr[] = {4, 2, 7, 2, 9, 2};
    int size = 6;

    cout << firstOccurrence(arr, size, 0, 2);  // Output: 1
    return 0;
}