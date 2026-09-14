# Student Record Manager

A menu-driven **Student Record Management System** developed in C using a **Singly Linked List**.

## Features

* Create student records dynamically
* Display all student records
* Search for a student using roll number
* Insert a new student at the beginning
* Delete a student using roll number
* Update student details
* Find the student with the highest marks
* Calculate average marks
* Dynamic memory allocation using `malloc()`
* Proper memory deallocation using `free()`

## Concepts Used

* Structures in C
* Singly Linked Lists
* Pointers
* Dynamic Memory Allocation
* `malloc()` and `free()`
* Functions
* Loops and conditional statements
* Menu-driven programming

## Student Record Structure

Each student record contains:

* **Roll Number**
* **Name**
* **Marks**
* **Pointer to the next student**

The records are connected using a singly linked list:

```text
[Student 1] → [Student 2] → [Student 3] → NULL
```

## How to Run

### Compile

```bash
clang studentrecords.c -o studentrecords
```

### Run

```bash
./studentrecords
```

## Menu Options

```text
1. Display Students
2. Search Student
3. Insert Student
4. Delete Student
5. Update Student
6. Find Topper
7. Calculate Average Marks
8. Exit
```

## Purpose

This project was created to apply **Data Structures and C programming concepts** to a practical problem while understanding how linked lists and dynamic memory allocation work in a real application.
