#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;  // found
    }
    return -1; // not found
}

// Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Binary Insertion
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

    return left;
}

int binaryInsertion(int arr[], int size, int target) {
    int pos = findInsertPosition(arr, size, target);

    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = target;
    return size + 1;
}

// Test Generators
void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
}

void runLinearSearchTests(int size) {
    cout << "\n===============================";
    cout << "\nLINEAR SEARCH (Array size = " << size << ")";
    cout << "\n===============================" << endl;

    int* arr = new int[size];
    generateSortedArray(arr, size);

    // BEST CASE → first element
    int bestTarget = arr[0];
    auto start = high_resolution_clock::now();
    linearSearch(arr, size, bestTarget);
    auto end = high_resolution_clock::now();
    cout << "Best Case Time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    // AVERAGE CASE → middle element
    int avgTarget = arr[size / 2];
    start = high_resolution_clock::now();
    linearSearch(arr, size, avgTarget);
    end = high_resolution_clock::now();
    cout << "Average Case Time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    // WORST CASE → last element
    int worstTarget = arr[size - 1];
    start = high_resolution_clock::now();
    linearSearch(arr, size, worstTarget);
    end = high_resolution_clock::now();
    cout << "Worst Case Time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

void runBinarySearchTests(int size) {
    cout << "\n===============================";
    cout << "\nBINARY SEARCH (Array size = " << size << ")";
    cout << "\n===============================" << endl;

    int* arr = new int[size];
    generateSortedArray(arr, size);

    // BEST CASE → target is at middle
    int bestTarget = arr[size/2];
    auto start = high_resolution_clock::now();
    binarySearch(arr, size, bestTarget);
    auto end = high_resolution_clock::now();
    cout << "Best Case Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // AVERAGE CASE → random target
    int avgTarget = arr[rand() % size];
    start = high_resolution_clock::now();
    binarySearch(arr, size, avgTarget);
    end = high_resolution_clock::now();
    cout << "Average Case Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // WORST CASE → target at the last element
    int worstTarget = arr[size - 1];
    start = high_resolution_clock::now();
    binarySearch(arr, size, worstTarget);
    end = high_resolution_clock::now();
    cout << "Worst Case Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    delete[] arr;
}

void runMergeSortTests(int size) {
    cout << "\n===============================";
    cout << "\nMERGE SORT (Array size = " << size << ")";
    cout << "\n===============================" << endl;

    int* arr = new int[size];

    // BEST CASE → already sorted
    for (int i = 0; i < size; i++) arr[i] = i;
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto end = high_resolution_clock::now();
    cout << "Best Case (Sorted Input): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // AVERAGE CASE → random values
    for (int i = 0; i < size; i++) arr[i] = rand();
    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    end = high_resolution_clock::now();
    cout << "Average Case (Random Input): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // WORST CASE → reverse sorted
    for (int i = 0; i < size; i++) arr[i] = size - i;
    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    end = high_resolution_clock::now();
    cout << "Worst Case (Reverse Sorted): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    delete[] arr;
}

void runBinaryInsertionTests(int size) {
    cout << "\n===============================";
    cout << "\nBINARY INSERTION TEST (Array size = " << size << ")";
    cout << "\n===============================" << endl;

    int* arr = new int[size + 1]; // +1 for insertion

    // BEST CASE
    for(int i = 0; i < size; i++) arr[i] = i; // fresh sorted array
    int target = size; // insert at end → minimal shifting
    auto start = high_resolution_clock::now();
    binaryInsertion(arr, size, target);
    auto end = high_resolution_clock::now();
    cout << "Best Case (Insert at end): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // AVERAGE CASE
    for(int i = 0; i < size; i++) arr[i] = i; // reset array
    target = size / 2; // insert middle → ~half shifting
    start = high_resolution_clock::now();
    binaryInsertion(arr, size, target);
    end = high_resolution_clock::now();
    cout << "Average Case (Insert middle): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // WORST CASE
    for(int i = 0; i < size; i++) arr[i] = i; // reset array
    target = 0; // insert at beginning → max shifting
    start = high_resolution_clock::now();
    binaryInsertion(arr, size, target);
    end = high_resolution_clock::now();
    cout << "Worst Case (Insert at beginning): "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    delete[] arr;
}




// ====================== MAIN PROGRAM ==============================
int main() {
    srand(time(NULL));

    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};

    for (int s : sizes) {
        runLinearSearchTests(s);
        runBinarySearchTests(s);
        runMergeSortTests(s);
        runBinaryInsertionTests(s);
        cout << "\n-------------------------------------\n";
    }

    return 0;
}
