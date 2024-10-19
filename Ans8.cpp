#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Constructor to initialize Book details
    Book(const string& t, const string& a, double p) 
        : title(t), author(a), price(p) {}

    // Overload the << operator to print Book details
    friend ostream& operator<<(ostream& os, const Book& b) {
        os << "Book Details:\n"
           << "----------------\n"
           << "Title  : " << b.title << "\n"
           << "Author : " << b.author << "\n"
           << "Price  : $" << b.price << "\n";
        return os;
    }

    // Optional: Method to update book price
    void updatePrice(double newPrice) {
        price = newPrice;
    }
};

int main() {
    // Creating Book objects
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 15.99);
    Book book2("To Kill a Mockingbird", "Harper Lee", 18.50);

    // Displaying Book details using overloaded << operator
    cout << book1 << endl;
    cout << book2 << endl;

    // Updating the price of book2 and displaying updated details
    book2.updatePrice(20.00);
    cout << "Updated Book 2:\n" << book2 << endl;

    return 0;
}
