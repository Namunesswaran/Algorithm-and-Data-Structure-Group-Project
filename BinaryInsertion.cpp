#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string id;
    string status; // "available" or "borrowed"

    Book(string t, string a, string i, string s = "available")
        : title(t), author(a), id(i), status(s) {
    }
};

// --------------------------------------------------
// BINARY SEARCH TO FIND INSERTION POSITION
// --------------------------------------------------
int findInsertPosition(const vector<Book>& books, const string& title) {
    int left = 0, right = books.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (books[mid].title == title)
            return mid; // exact match (duplicate titles allowed)

        if (books[mid].title < title)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // Left becomes the correct insertion index
    return left;
}

// --------------------------------------------------
// BINARY INSERTION FUNCTION
// --------------------------------------------------
void insertBook(vector<Book>& books, const Book& newBook) {
    int pos = findInsertPosition(books, newBook.title);

    // Insert at correct sorted position
    books.insert(books.begin() + pos, newBook);

    cout << "Book inserted at position " << pos << endl;
}

// --------------------------------------------------
// DISPLAY ALL BOOKS
// --------------------------------------------------
void displayBooks(const vector<Book>& books) {
    cout << "\n===== BOOK LIST (Sorted by Title) =====\n";
    for (const auto& b : books) {
        cout << "- " << b.title << " (" << b.id << "), Status: " << b.status << endl;
    }
    cout << "========================================\n";
}

// --------------------------------------------------
// MAIN (Example Usage)
// --------------------------------------------------
int main() {
    vector<Book> library;

    // Insert sample books
    insertBook(library, Book("Data Structures", "Mark Weiss", "B001"));
    insertBook(library, Book("Algorithms", "CLRS", "B002"));
    insertBook(library, Book("C++ Programming", "Bjarne Stroustrup", "B003"));
    insertBook(library, Book("Artificial Intelligence", "Stuart Russell", "B004"));
    insertBook(library, Book("Database Systems", "Raghu Ramakrishnan", "B005"));

    // Display sorted result
    displayBooks(library);

    return 0;
}
