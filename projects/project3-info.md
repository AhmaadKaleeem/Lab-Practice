Project Overview: Library Management System

1. Objective

To manage library operations (add, remove, check out, and view books) without using arrays, storing each change directly to a file (library_books.txt).

Here’s an outline of the functions :

a) Add Book

Objective: Add a book to the file, marking it as available.

Implementation:

Open the file in ios::app mode to append a new book entry.

Check if the book already exists by reading the file.

If not, add the book with its status.



b) Remove Book

Objective: Remove a specified book from the file if it exists.

Implementation:

Read each line, excluding the book to be removed, and write the rest to a temporary file.

Replace the original file with the updated temporary file.



c) Check Out Book

Objective: Mark a book as checked out if available.

Implementation:

Read each line, updating the book’s status if found.

Write the updated data to a temporary file, then replace the original file.



d) Display Books

Objective: Show all books and their availability.

Implementation: Open the file and display each line, which contains a book title and its status.

