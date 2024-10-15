#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Contact {
    string name;
    string phone;
    string email;

public:
    Contact() {}
    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }

    void display() const {
        cout << "Name: " << name << ", Phone: " << phone << ", Email: " << email << endl;
    }
};

// Function to add a new contact to the file
void addContact(const Contact& contact) {
    ofstream outFile("contacts.txt", ios::app);  // Open in append mode
    outFile << contact.getName() << "," << contact.getPhone() << "," << contact.getEmail() << endl;
    outFile.close();
}

// Function to display all contacts
void displayContacts() {
    ifstream inFile("contacts.txt");
    string line;
    cout << "Contacts List:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

// Function to search for a contact by name
void searchContact(const string& searchName) {
    ifstream inFile("contacts.txt");
    string name, phone, email;
    bool found = false;

    while (getline(inFile, name, ',') && getline(inFile, phone, ',') && getline(inFile, email)) {
        if (name == searchName) {
            cout << "Found: " << name << ", " << phone << ", " << email << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No contact found with name: " << searchName << endl;
    }
    inFile.close();
}

// Function to delete a contact by name
void deleteContact(const string& deleteName) {
    ifstream inFile("contacts.txt");
    ofstream outFile("temp.txt");
    string name, phone, email;
    bool found = false;

    while (getline(inFile, name, ',') && getline(inFile, phone, ',') && getline(inFile, email)) {
        if (name != deleteName) {
            outFile << name << "," << phone << "," << email << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found) {
        cout << "Contact deleted successfully.\n";
    } else {
        cout << "No contact found with name: " << deleteName << endl;
    }
}

int main() {
    int choice;
    string name, phone, email;

    do {
        cout << "\nAddress Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Email: ";
                getline(cin, email);
                addContact(Contact(name, phone, email));
                cout << "Contact added successfully.\n";
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                cout << "Enter name to search: ";
                getline(cin, name);
                searchContact(name);
                break;

            case 4:
                cout << "Enter name to delete: ";
                getline(cin, name);
                deleteContact(name);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
