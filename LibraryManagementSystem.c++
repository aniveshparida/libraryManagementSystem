#include <iostream>
#include <string>
using namespace std;

// Book structure to store details of each book
struct Book {
    int id;                 // Book ID
    string title;           // Book title
    string author;          // Book author
    Book* next;             // Pointer to the next book in the list

    // Constructor to initialize book details
    Book(int bookID, string bookTitle, string bookAuthor) {
        id = bookID;
        title = bookTitle;
        author = bookAuthor;
        next = nullptr;
    }
};

// Library class to manage book operations
class Library {
private:
    Book* head; // Pointer to the first book in the linked list

public:
    // Constructor to initialize the library
    Library() {
        head = nullptr;
    }

    // Function to add a book to the library
    void addBook(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);

        if (!head) {
            head = newBook; // Add as the first book if the library is empty
        } else {
            Book* temp = head;
            while (temp->next) {
                temp = temp->next; // Traverse to the last book
            }
            temp->next = newBook; // Add the new book at the end
        }

        cout << "Book '" << title << "' by " << author << " added successfully!" << endl;
    }

    // Function to remove a book from the library
    void removeBook(int id) {
        if (!head) {
            cout << "The library is empty! No books to remove." << endl;
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next; // Remove the first book
            delete temp;
            cout << "Book with ID " << id << " removed successfully!" << endl;
            return;
        }

        Book* current = head;
        while (current->next && current->next->id != id) {
            current = current->next; // Traverse the list to find the book
        }

        if (current->next) {
            Book* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            cout << "Book with ID " << id << " removed successfully!" << endl;
        } else {
            cout << "Book with ID " << id << " not found in the library!" << endl;
        }
    }

    // Function to search for a book by ID or title
    void searchBook(string searchTerm) {
        Book* temp = head;

        while (temp) {
            if (to_string(temp->id) == searchTerm || temp->title.find(searchTerm) != string::npos) {
                cout << "Book Found: ID=" << temp->id << ", Title='" << temp->title << "', Author='" << temp->author << "'" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "No book found with the search term '" << searchTerm << "'." << endl;
    }

    // Function to display all books in the library
    void displayBooks() {
        if (!head) {
            cout << "The library is empty! No books to display." << endl;
            return;
        }

        Book* temp = head;
        cout << "Books currently in the library:" << endl;

        while (temp) {
            cout << "ID: " << temp->id << ", Title: '" << temp->title << "', Author: '" << temp->author << "'" << endl;
            temp = temp->next;
        }
    }
};

// Main function
int main() {
    Library library;
    int choice, id;
    string title, author, searchTerm;

    cout << "Welcome to the Library Management System!" << endl;

    do {
        cout << "\n1. Add Book\n2. Remove Book\n3. Search Book\n4. Display Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter Book ID to Remove: ";
                cin >> id;
                library.removeBook(id);
                break;

            case 3:
                cout << "Enter Book ID or Title to Search: ";
                cin.ignore();
                getline(cin, searchTerm);
                library.searchBook(searchTerm);
                break;

            case 4:
                library.displayBooks();
                break;

            case 5:
                cout << "Exiting the Library Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
