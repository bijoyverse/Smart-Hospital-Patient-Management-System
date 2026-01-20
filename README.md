```
# Smart Hospital Patient Management System (C++)

Smart Hospital Patient Management System is a data-structure–driven C++ console application designed to simulate real hospital workflows. The project focuses on efficient patient handling using core data structures and is suitable for academic projects, DSA practice, and portfolio demonstration.

--------------------------------------------------

PROJECT OVERVIEW

This system manages patient admission, emergency handling, discharge, searching, archiving, and undo/redo operations. It prioritizes emergency patients, stores discharged patient records for fast retrieval, and maintains a history of operations.

--------------------------------------------------

DATA STRUCTURES USED AND PURPOSE

Queue
- Used for normal patient admission (First In First Out)

Deque
- Used for emergency patients to ensure higher priority handling

Binary Search Tree (BST)
- Used to store discharged patients
- Enables fast searching by patient ID

Stack
- Used for undo and redo operations

Singly Linked List
- Used to archive discharged patients

Vector with Sorting
- Used to sort patients by severity, arrival time, or department

--------------------------------------------------

CORE FEATURES

1. Patient Admission
- Normal patients are added to a queue
- Emergency patients are added to the front of a deque
- Arrival time is tracked automatically

2. Emergency Priority Handling
- Emergency patients are always discharged before normal patients

3. Patient Discharge
- Removes patient from queue or deque
- Inserts patient into BST
- Archives patient data using a linked list

4. Patient Search
- Search discharged patients quickly using BST by patient ID

5. Undo and Redo Operations
- Stack-based operation history tracking
- Supports undo and redo functionality

6. BST Display
- Displays all discharged patients in sorted order by ID

--------------------------------------------------

MENU OPTIONS

1. Admit Normal Patient
2. Admit Emergency Patient
3. Discharge Patient
4. Search Patient by ID
5. Undo
6. Redo
7. Display BST
0. Exit

--------------------------------------------------

HOW TO RUN

1. Clone the repository
   git clone https://github.com/bijoyverse/Smart-Hospital-Patient-Management-System.git

2. Compile the program
   g++ main.cpp -o hospital

3. Run the executable
   ./hospital

--------------------------------------------------

LEARNING OUTCOMES

- Practical implementation of core data structures
- Understanding real-world problem solving using DSA
- Hands-on experience with STL containers
- Improved problem decomposition and logic building

--------------------------------------------------

FUTURE IMPROVEMENTS

- File handling for permanent data storage
- Priority queue based on severity level
- Graphical user interface
- Role-based access control for hospital staff

--------------------------------------------------

AUTHOR

Md. Biplob Hasan Bijoy 
CSE Undergraduate  
```
