#include <iostream>
using namespace std;

class Book {
    string title, author;
    double price;

public:
    Book(string t, string a, double p) : title(t), author(a), price(p) {}
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.title << ", Author: " << book.author << ", Price: " << book.price;
        return os;
    }
};

int main() {
    Book b("C++ Primer", "Lippman", 45.99);
    cout << b << endl;
    return 0;
}
