#include <iostream>
#include <vector>
using namespace std;

class Book {
    string title;
    bool isAvailable;

public:
    Book(string t) : title(t), isAvailable(true) {}
    bool borrow() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }
    void returnBook() { isAvailable = true; }
    string getTitle() const { return title; }
};

class Library {
    vector<Book> books;

public:
    void addBook(const Book& book) { books.push_back(book); }
    void displayBooks() const {
        for (const auto& book : books)
            cout << book.getTitle() << endl;
    }
};

int main() {
    Library lib;
    lib.addBook(Book("C++ Primer"));
    lib.addBook(Book("Effective C++"));
    lib.displayBooks();
    return 0;
}
