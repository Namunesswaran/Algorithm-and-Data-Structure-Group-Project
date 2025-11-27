#include <iostream>
using namespace std;

// Find insert position using binary search
int findInsertPosition(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // Left becomes the correct insertion index
    return left;
}

// Binary insertion
int binaryInsertion(int arr[], int size, int target) {
    int pos = findInsertPosition(arr, size, target);

    // Insert at correct sorted position
    // Note: Inserting into a raw array requires shifting elements manually
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = target;
    return size + 1;
}
