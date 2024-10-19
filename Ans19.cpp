#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>  // For std::find_if
using namespace std;

// Class to represent a Contact
class Contact {
private:
    string name;
    string phone;

public:
    Contact(const string& n, const string& p) : name(n), phone(p) {}

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    void display() const {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }

    // Function to save the contact to a file
    void saveToFile(ofstream& file) const {
        file << name << "," << phone << endl;
    }
};

// Class to manage the Address Book
class AddressBook {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    // Function to load contacts from a file
    void loadContacts() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t commaPos = line.find(',');
                if (commaPos != string::npos) {
                    string name = line.substr(0, commaPos);
                    string phone = line.substr(commaPos + 1);
                    contacts.emplace_back(name, phone);
                }
            }
            file.close();
        }
    }

public:
    AddressBook() {
        loadContacts();  // Load contacts from the file when the address book is created
    }

    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        ofstream file(filename, ios::app);  // Open the file in append mode
        contact.saveToFile(file);  // Save contact to the file
        file.close();
    }

    void displayContacts() const {
        cout << "\nContacts List:\n";
        for (const auto& contact : contacts) {
            contact.display();
        }
    }

    void searchContact(const string& name) const {
        auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.getName() == name;
        });

        if (it != contacts.end()) {
            cout << "Contact found:\n";
            it->display();
        } else {
            cout << "Contact not found.\n";
        }
    }

    void deleteContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.getName() == name;
        });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact \"" << name << "\" deleted.\n";

            // Rewrite the contacts file without the deleted contact
            ofstream file(filename);
            for (const auto& contact : contacts) {
                contact.saveToFile(file);
            }
            file.close();
        } else {
            cout << "Contact not found.\n";
        }
    }
};

int main() {
    AddressBook addressBook;

    int choice;
    string name, phone;

    do {
        cout << "\nAddress Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name and phone number: ";
                cin >> name >> phone;
                addressBook.addContact(Contact(name, phone));
                break;
            case 2:
                addressBook.displayContacts();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                addressBook.searchContact(name);
                break;
            case 4:
                cout << "Enter name to delete: ";
                cin >> name;
                addressBook.deleteContact(name);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
