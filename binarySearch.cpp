#include <iostream>
#include <string>
using namespace std;

int main(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;
    bool found = false;

    // binary search
    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == target) {
            found = true;
            break;
        }

        // if the book title is bigger alphabetically
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "\nBook found at position: " << mid << endl;
    } else {
        cout << "\nBook not found in the library." << endl;
    }

    return 0;
}
