# Algorithm and Data Structure Group Project

A C++ project simulating a **Library Book Borrowing System**, built to implement and empirically compare classic search, sort, and insertion algorithms on a dataset of 10,000+ books.

## Overview

The project generates a library catalogue and uses it to test how different algorithms perform as the amount of data grows — from 10 records up to 1,000,000 — measuring best, average, and worst-case running time for each.

## Files

| File | Purpose |
|---|---|
| `LibraryBooksDetails.cpp` | Generates the library dataset — 10,000 books with ID, ISBN, title, author, publisher, year, genre, and availability status |
| `linearSearch.cpp` | Linear search implementation — checks each element in order |
| `binarySearch.cpp` | Binary search implementation — repeatedly halves a sorted array to find a target |
| `mergeSort.cpp` | Merge sort implementation — recursively splits and merges the array into sorted order |
| `BinaryInsertion.cpp` | Binary insertion — uses binary search to find the correct position, then inserts and shifts elements |
| `empiricalComplexity.cpp` | Combines all four algorithms and times each one's best, average, and worst case across increasing input sizes (10 to 1,000,000), using `<chrono>` for timing |
| `program1.exe` | Compiled Windows executable |
| `.vscode/tasks.json` | VS Code build task configuration |

## How to run

1. Compile any of the `.cpp` files with a C++ compiler, e.g.:
   ```
   g++ empiricalComplexity.cpp -o empiricalComplexity
   ./empiricalComplexity
   ```
2. `empiricalComplexity.cpp` is the main benchmarking file — running it prints timing results for every algorithm at every tested input size.

## What this project covers

- **Searching:** linear search vs. binary search, and the difference sorted data makes to search speed
- **Sorting:** merge sort, a divide-and-conquer algorithm with consistent O(n log n) performance
- **Insertion:** binary insertion, combining binary search with array shifting to keep data sorted
- **Empirical analysis:** measuring real running time (not just theoretical complexity) across best, average, and worst cases, and across a wide range of input sizes

## Notes

- All algorithms operate on plain C-style arrays (`int arr[]`), not STL containers, which is typical for a data structures course focused on manual memory and index handling.
- Random inputs use `rand()`, seeded with `srand(time(NULL))`.
