
# Library Management System

## Description

This project is a fully functional **Library Management System** implemented in **C++**, allowing for efficient management of library operations. The system provides users with features to add, search, borrow, return, delete, and display books in the library. It also supports managing waitlists for books that are unavailable.

The library system utilizes **linked lists** for book storage, providing dynamic and efficient memory management.

## Features

### Core Features
- **Add Book**: Add new books to the library, specifying ID, title, and author.
- **Search Book**: Search for books by ID or title and view their details.
- **Borrow Book**: Borrow books if available, or be added to a waitlist for the book.
- **Return Book**: Return borrowed books and notify the next user in the waitlist, if applicable.
- **Delete Book**: Remove books from the library using ID or title.
- **Display Books**: View all books currently in the library, along with their availability status.

### Additional Functionalities
- **Manage Waitlists**: Tracks users waiting for unavailable books and notifies them when the book becomes available.
- **Dynamic Memory Allocation**: Ensures efficient memory usage by dynamically creating and deleting book and waitlist nodes.

## Sample Preloaded Data
Upon program initialization, the library contains a collection of popular books, such as:
- *The Great Gatsby* by F. Scott Fitzgerald
- *1984* by George Orwell
- *To Kill a Mockingbird* by Harper Lee

## Future Enhancements
- **User Registration**: Register users with personal details.
- **Book Sorting**: Implement sorting of books by title, author, or ID.
- **Enhanced User Interface**: Provide a more user-friendly experience with graphical options.
- **Persistent Storage**: Save library data to a file for long-term storage and load it during program startup.

## Data Structure Used
- **Linked Lists**: Dynamically store books and their attributes.
- **Custom Nodes**: Manage waitlists for unavailable books using a separate linked list for each book.

## How to Use

### Prerequisites
- C++ compiler (e.g., GCC, Clang, or Visual Studio).
- Basic knowledge of compiling and running C++ programs.

### Compilation and Execution
1. Clone or download the repository.
2. Open a terminal or command prompt.
3. Navigate to the project directory.
4. Compile the code using the following command:

   ```bash
   g++ -o LibraryManagementSystem main.cpp
   ```

5. Run the program:

   ```bash
   ./LibraryManagementSystem
   ```

### Menu Options
The program provides an interactive menu to perform various actions:
1. **Add a new book**: Specify ID, title, and author to add books.
2. **Display all available books**: View the entire catalog and availability.
3. **Borrow a book**: Enter the book ID and user ID to borrow books or join a waitlist.
4. **Return a book**: Return a borrowed book and notify the next user in the waitlist.
5. **Search for a book**: Search by title or ID.
6. **Delete a book**: Remove books from the library.
7. **Exit**: Exit the program.

### Example Usage
1. Add a book:
   ```text
   Enter book ID: 201
   Enter book title: The Hobbit
   Enter book author: J.R.R. Tolkien
   ```
2. Borrow a book:
   ```text
   Enter book ID to borrow: 101
   Enter user ID: 1
   ```
3. Return a book:
   ```text
   Enter book ID to return: 101
   ```

## Code Overview
The implementation includes:
- **`struct Book`**: Represents a book with ID, title, author, availability status, and waitlist pointer.
- **`struct WaitingNode`**: Represents a user waiting for a book.
- **Key Functions**:
  - `addBook()`: Adds a new book.
  - `searchBookByIdOrTitle()`: Searches for a book.
  - `deleteBook()`: Deletes a book from the library.
  - `borrowBook()`: Borrows a book or joins the waitlist if unavailable.
  - `returnBook()`: Processes a book return and notifies waitlisted users.
  - `displayBooks()`: Displays all books in the library.

## Contribution
Contributions to this project are welcome! You can:
- Add new features.
- Enhance the user interface.
- Optimize the current functionality.

## License
This project is open-source and available under the [MIT License](LICENSE).
