#include <iostream>
#include <string>
using namespace std;

int main() {
    // sample sorted books
    string books[6] = {
        "Alice in Wonderland",
        "Harry Potter",
        "Introduction to Algorithms",
        "Lord of the Rings",
        "Programming in C++",
        "The Great Gatsby"
    };

    string findBook;
    cout << "Enter book title to search: ";
    getline(cin, findBook);

    int left = 0;
    int right = 5;
    int mid;
    bool found = false;

    // binary search
    while (left <= right) {
        mid = (left + right) / 2;

        if (books[mid] == findBook) {
            found = true;
            break;
        }

        // if the book title is bigger alphabetically
        if (books[mid] < findBook) {
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
