#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int bookID;
    string ISBN;
    string title;
    string author;
    string publisher;
    int year;
    string genre;
    bool isAvailable;
};


vector<Book> loadInitialBooks() {
    vector<Book> books;
    books.reserve(10000);   // improves performance

    string authors[] = {
        "J.K. Rowling", "Robert Martin", "Mark Weiss", "Andrew Tanenbaum",
        "Bjarne Stroustrup", "Herbert Schildt", "Stuart Russell",
        "Tom Mitchell", "Ian Sommerville", "William Stallings"
    };

    string publishers[] = {
        "Pearson", "McGraw-Hill", "Wiley", "Prentice Hall",
        "Addison-Wesley", "O'Reilly", "Springer"
    };

    string genres[] = {
        "Programming", "AI", "Database", "Networking",
        "Security", "Software", "Cloud", "Hardware",
        "Data Science", "Electronics"
    };

    for (int i = 1; i <= 10000; i++) {
        Book b;
        b.bookID = 100000 + i;
        b.ISBN = "978000" + to_string(100000000 + i);   // guaranteed unique
        b.title = "Book Title " + to_string(i);
        b.author = authors[i % 10];
        b.publisher = publishers[i % 7];
        b.year = 2000 + (i % 25);
        b.genre = genres[i % 10];
        b.isAvailable = true;

        books.push_back(b);
    }

    return books;
}


void displaySample(const vector<Book>& books) {
    
    for (int i = 0; i < 10000; i++) {
        cout << "ID: " << books[i].bookID
             << " | ISBN: " << books[i].ISBN
             << " | Title: " << books[i].title
             << " | Author: " << books[i].author
             << " | Publisher: " << books[i].publisher
             << " | Year: " << books[i].year
             << " | Genre: " << books[i].genre
             << " | Status: " << (books[i].isAvailable ? "Available" : "Borrowed")
             << endl;
    }
}

int main() {
    vector<Book> library = loadInitialBooks();

    cout << "Total books loaded into system: " << library.size() << endl;

    displaySample(library);

    return 0;
}
