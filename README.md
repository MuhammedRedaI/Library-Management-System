# Library Management System

## Description

This project is a simple Library Management System implemented in C++. The system allows users to add, search, delete, and display books in a library using linked lists. The system supports basic functionalities for managing books, such as adding new books, searching for books by title or ID, and deleting books from the library.

The system uses a linked list data structure to store and manage books, with each book having attributes such as title, ID, and availability status.

## Features (Implemented so far)

- **Add Book**: Add new books to the library system.
- **Search Book**: Search for a book by title or ID and display the book's details.
- **Delete Book**: Delete a book from the library system by title or ID.
- **Display Books**: Display the list of all books currently available in the library.
- **Initialize Library**: Populate the library with 100 default books for testing.

## Future Features

- **User Registration**: Allow users to register with their details (e.g., name, ID).
- **Borrow a Book**: Implement functionality for users to borrow books if available.
- **Return a Book**: Allow users to return borrowed books to the library.
- **Sort Books**: Provide the option to sort books by title, author, or ID.
- **Waitlist for Borrowed Books**: Implement a queue for managing users requesting unavailable books.

## Data Structure Used

- **Linked List**: Used to store the books in the library. Each node in the list contains information about a book, such as the title, ID, and availability status.
- **Dynamic Memory Allocation**: Books are dynamically allocated using the `new` keyword when added to the library, and memory is freed when books are deleted.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC or Clang).
- Basic knowledge of C++ programming, including linked lists and dynamic memory management.

### How to Compile and Run

1. Clone or download the project to your local machine.
2. Open a terminal or command prompt.
3. Navigate to the project directory.
4. Compile the project using the following command:

   ```bash
   g++ -o LibraryManagementSystem main.cpp
