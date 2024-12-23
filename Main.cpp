#include <iostream>
using namespace std;

struct User {
    int id;
    string name;
};

struct WaitingNode {
    int userId;
    WaitingNode* next;
};

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
    WaitingNode* waitingList;  // Pointer to the head of the waiting list
    Book* next;
};

// Function to add a user to the waiting list
void addToWaitingList(Book* book, int userId) {
    WaitingNode* newNode = new WaitingNode{ userId, nullptr };
    if (book->waitingList == nullptr) {
        book->waitingList = newNode;
    }
    else {
        WaitingNode* temp = book->waitingList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "User " << userId << " added to the waiting list for " << book->title << endl;
}

// Function to add a book to the library
void addBook(Book*& head, int id, const string& title, const string& author) {
    Book* newBook = new Book{ id, title, author, true, nullptr, nullptr };
    if (head == nullptr) {
        head = newBook;
    }
    else {
        Book* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newBook;
    }
    cout << "Book added successfully!" << endl;
}

// Function to search for a book by ID or title
Book* searchBookByIdOrTitle(Book* head, const string& searchTerm, int id) {
    Book* curr = head;
    while (curr != nullptr) {
        if (curr->id == id || curr->title == searchTerm) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

// Function to delete a book from the library
void deleteBook(Book*& head, const string& title, int id) {
    if (head == nullptr) {
        cout << "The library is empty; no books to delete!" << endl;
        return;
    }

    Book* target = searchBookByIdOrTitle(head, title, id);

    if (target == nullptr) {
        cout << "The book is nowhere to be found!" << endl;
        return;
    }

    if (target == head) {
        head = head->next;
        cout << target->title << " book deleted successfully!" << endl;
        delete target;
        return;
    }

    // Find the book to delete and remove it from the list
    Book* curr = head;
    while (curr->next != nullptr && curr->next != target) {
        curr = curr->next;
    }

    if (curr->next == nullptr) {
        cout << "Book not found." << endl;
        return;
    }

    curr->next = curr->next->next;
    cout << target->title << " book deleted successfully!" << endl;
    delete target;
}

// Function to borrow a book, or add user to waiting list if unavailable
void borrowBook(Book* head, int bookId, int userId) {
    Book* curr = head;
    while (curr != nullptr) {
        if (curr->id == bookId) {
            if (curr->isAvailable) {
                curr->isAvailable = false;
                cout << "Book borrowed successfully by User " << userId << ": " << curr->title << endl;
                return;
            }
            else {
                addToWaitingList(curr, userId);
                return;
            }
        }
        curr = curr->next;
    }
    cout << "Book with ID " << bookId << " not found." << endl;
}

// Function to process the waiting list when a book is returned
void returnBook(Book* head, int bookId) {
    Book* curr = head;
    while (curr != nullptr) {
        if (curr->id == bookId) {
            if (!curr->isAvailable) {
                curr->isAvailable = true;
                cout << "Book returned successfully: " << curr->title << endl;

                // If there are users waiting, let the first one borrow the book
                if (curr->waitingList != nullptr) {
                    WaitingNode* firstUser = curr->waitingList;
                    cout << "Notifying User " << firstUser->userId << " to borrow the book: " << curr->title << endl;
                    curr->waitingList = firstUser->next; // Remove the user from the waiting list
                    delete firstUser;
                }
                return;
            }
            else {
                cout << "This book was not borrowed." << endl;
                return;
            }
        }
        curr = curr->next;
    }
    cout << "Book with ID " << bookId << " not found." << endl;
}

// Function to display books and their availability
void displayBooks(Book* head) {
    if (head == nullptr) {
        cout << "No books available." << endl;
        return;
    }

    cout << "Available Books:" << endl;
    Book* curr = head;
    while (curr != nullptr) {
        cout << "ID: " << curr->id << " | Title: " << curr->title << " | Author: " << curr->author
            << " | " << (curr->isAvailable ? "Available" : "Unavailable") << endl;
        curr = curr->next;
    }
}

void displayMenu() {
    cout << "  Library System  \n";
    cout << " 1. Add a new book \n";
    cout << " 2. Display all available books \n";
    cout << " 3. Borrow a book \n";
    cout << " 4. Return a book \n";
    cout << " 5. Search for a book \n";
    cout << " 6. Delete a book \n";
    cout << " 7. Exit  \n";
    cout << "Please choose an option (1-7): ";
}

int main() {
    Book* bookHead = nullptr;

    addBook(bookHead, 101, "The Great Gatsby", "F. Scott Fitzgerald");
    addBook(bookHead, 102, "To Kill a Mockingbird", "Harper Lee");
    addBook(bookHead, 103, "1984", "George Orwell");
    addBook(bookHead, 104, "Pride and Prejudice", "Jane Austen");
    addBook(bookHead, 105, "The Catcher in the Rye", "J.D. Salinger");
    addBook(bookHead, 106, "Moby Dick", "Herman Melville");
    addBook(bookHead, 107, "War and Peace", "Leo Tolstoy");
    addBook(bookHead, 108, "The Odyssey", "Homer");

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            int bookId;
            string title, author;
            cout << "Enter book ID: ";
            cin >> bookId;
            cout << "Enter book title: ";
            cin >> title;
            cout << "Enter book author: ";
            cin >> author;
            addBook(bookHead, bookId, title, author);
        }
        else if (choice == 2) {
            displayBooks(bookHead);
        }
        else if (choice == 3) {
            int bookId, userId;
            cout << "Enter book ID to borrow: ";
            cin >> bookId;
            cout << "Enter user ID: ";
            cin >> userId;
            borrowBook(bookHead, bookId, userId);
        }
        else if (choice == 4) {
            int bookId;
            cout << "Enter book ID to return: ";
            cin >> bookId;
            returnBook(bookHead, bookId);
        }
        else if (choice == 5) {
            string search;
            cout << "Enter book title or ID to search: ";
            cin >> search;
            Book* result = searchBookByIdOrTitle(bookHead, search, stoi(search));
            if (result) {
                cout << "Book found: ID: " << result->id << " | Title: " << result->title << " | Author: " << result->author << endl;
            }
            else {
                cout << "No book found with the given title or ID." << endl;
            }
        }
        else if (choice == 6) {
            string title;
            int id;
            cout << "Enter book title or ID to delete: ";
            cin >> title;
            cout << "Enter book ID to delete: ";
            cin >> id;
            deleteBook(bookHead, title, id);
        }
        else if (choice == 7) {
            cout << "Exiting from the program " << endl;
            return 0;
        }
        else {
            cout << "Wrong choice. Please try again " << endl;
        }
    }

    return 0;
}