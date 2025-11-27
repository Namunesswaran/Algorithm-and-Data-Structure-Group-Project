struct Book {
    std::string title;
    // ... other fields (author, bookID, etc.)
};

/**
 * Merges two sorted subarrays: arr[left...mid] and arr[mid+1...right]
 * Sorting is based on the Book title.
 */
void merge(std::vector<Book>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors for the left and right halves
    std::vector<Book> leftArr(n1);
    std::vector<Book> rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left...right]
    int i = 0;   // Initial index of first subarray
    int j = 0;   // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        // Compare Book titles for sorting
        if (leftArr[i].title <= rightArr[j].title) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * The main function that sorts arr[left...right] using the recursive merge() calls.
 * This is used once at system initialization to sort all existing books[cite: 41].
 */
void mergeSort(std::vector<Book>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}