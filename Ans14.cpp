#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Include for std::find
using namespace std;

// Class to represent a Book
class Book {
private:
    string title;
    string author;

public:
    Book(const string& t, const string& a) : title(t), author(a) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << endl;
    }

    // Overload the equality operator for Book comparison
    bool operator==(const Book& other) const {
        return title == other.title && author == other.author;
    }
};

// Class to represent a User
class User {
private:
    string name;
    vector<Book> borrowedBooks;

public:
    User(const string& n) : name(n) {}

    void borrowBook(const Book& book) {
        borrowedBooks.push_back(book);
        cout << name << " borrowed \"" << book.getTitle() << "\" by " << book.getAuthor() << endl;
    }

    void returnBook(const Book& book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            cout << name << " returned \"" << book.getTitle() << "\" by " << book.getAuthor() << endl;
        } else {
            cout << name << " does not have \"" << book.getTitle() << "\" borrowed." << endl;
        }
    }

    void displayBorrowedBooks() const {
        cout << name << "'s borrowed books:\n";
        if (borrowedBooks.empty()) {
            cout << "No books borrowed.\n";
            return;
        }
        for (const auto& book : borrowedBooks) {
            book.display();
        }
    }
};

// Main function to simulate the library system
int main() {
    vector<Book> library;  // Library collection
    library.push_back(Book("1984", "George Orwell"));
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
    library.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald"));

    User user("Alice");

    // Simulating borrowing and returning books
    user.borrowBook(library[0]);  // Borrow "1984"
    user.borrowBook(library[1]);  // Borrow "To Kill a Mockingbird"
    user.displayBorrowedBooks();

    user.returnBook(library[1]);  // Return "To Kill a Mockingbird"
    user.displayBorrowedBooks();

    user.returnBook(library[2]);  // Attempt to return a book not borrowed

    return 0;
}
