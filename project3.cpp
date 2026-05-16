# Library Management System in C++

## Objective

Develop a Library Management System that efficiently manages books, members, and borrowing records using object-oriented programming.

---

# Features Implemented

* Add new books
* Display all books
* Search books by title
* Search books by author
* Add members
* Issue books
* Return books
* Menu-driven console application
* Uses classes and vectors for data management

---

# C++ Program

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};

// Member Class
class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) {
        memberID = id;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    // Display Books
    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n===== Book List =====\n";
        for (auto &b : books) {
            cout << "Book ID: " << b.bookID << endl;
            cout << "Title   : " << b.title << endl;
            cout << "Author  : " << b.author << endl;
            cout << "Status  : " << (b.issued ? "Issued" : "Available") << endl;
            cout << "-------------------------\n";
        }
    }

    // Search by Title
    void searchByTitle() {
        string title;
        cin.ignore();

        cout << "\nEnter Book Title: ";
        getline(cin, title);

        bool found = false;

        for (auto &b : books) {
            if (b.title == title) {
                cout << "\nBook Found!\n";
                cout << "Book ID: " << b.bookID << endl;
                cout << "Author : " << b.author << endl;
                cout << "Status : " << (b.issued ? "Issued" : "Available") << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Book not found.\n";
    }

    // Search by Author
    void searchByAuthor() {
        string author;
        cin.ignore();

        cout << "\nEnter Author Name: ";
        getline(cin, author);

        bool found = false;

        for (auto &b : books) {
            if (b.author == author) {
                cout << "\nBook Found!\n";
                cout << "Book ID: " << b.bookID << endl;
                cout << "Title   : " << b.title << endl;
                cout << "Status  : " << (b.issued ? "Issued" : "Available") << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No books found for this author.\n";
    }

    // Add Member
    void addMember() {
        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "Member Added Successfully!\n";
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        for (auto &b : books) {
            if (b.bookID == id) {
                if (!b.issued) {
                    b.issued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.bookID == id) {
                if (b.issued) {
                    b.issued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }

        cout << "Book not found.\n";
    }
};

// Main Function
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Search Book by Author\n";
        cout << "5. Add Member\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                lib.searchByTitle();
                break;

            case 4:
                lib.searchByAuthor();
                break;

            case 5:
                lib.addMember();
                break;

            case 6:
                lib.issueBook();
                break;

            case 7:
                lib.returnBook();
                break;

            case 8:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 8);

    return 0;
}
```

---

# Explanation of Classes

## 1. Book Class

Stores:

* Book ID
* Title
* Author
* Issue status

## 2. Member Class

Stores:

* Member ID
* Member name

## 3. Library Class

Handles:

* Adding books
* Displaying books
* Searching books
* Adding members
* Issuing books
* Returning books

---

# Sample Output

```text
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display Books
3. Search Book by Title
4. Search Book by Author
5. Add Member
6. Issue Book
7. Return Book
8. Exit
Enter your choice: 1

Enter Book ID: 101
Enter Book Title: C++ Programming
Enter Author Name: Bjarne Stroustrup
Book Added Successfully!
```

---

# Concepts Used

* Classes and Objects
* Vectors
* Functions
* Loops
* Conditional Statements
* Menu-Driven Programming
* String Handling

---

# Expected Outcome

This application successfully performs:

* Book addition
* Book searching
* Book issue and return operations
* Member management
* Dynamic display of records

The project demonstrates object-oriented programming concepts and provides a simple real-world library management solution.

