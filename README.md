# Smart Hospital Patient Management System

A data structure-driven C++ console application designed to simulate real hospital workflows with efficient patient handling. This project demonstrates practical implementation of core data structures in a healthcare management context.

## 📋 Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [System Architecture](#system-architecture)
- [Installation](#installation)
- [Usage](#usage)
- [Menu Options](#menu-options)
- [Implementation Details](#implementation-details)
- [Learning Outcomes](#learning-outcomes)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [Author](#author)
- [License](#license)

## 🎯 Project Overview

The Smart Hospital Patient Management System is designed to handle various hospital operations efficiently using fundamental data structures. The system prioritizes emergency patients, maintains discharge records for quick retrieval, and supports undo/redo functionality for administrative operations.

### Key Objectives

- Simulate real-world hospital patient flow management
- Demonstrate practical application of data structures and algorithms
- Provide efficient patient admission, discharge, and search operations
- Implement operation history tracking with undo/redo capabilities

### Target Audience

- Computer Science students learning Data Structures & Algorithms
- Developers building portfolio projects
- Anyone interested in healthcare management systems

## ✨ Features

### 1. **Patient Admission**
- Normal patients join a standard queue (FIFO)
- Emergency patients get priority placement
- Automatic timestamp tracking for arrival time
- Department assignment and patient details capture

### 2. **Emergency Priority Handling**
- Emergency patients are always processed first
- Separate handling mechanism using deque structure
- Ensures critical cases receive immediate attention

### 3. **Patient Discharge**
- Removes patient from active queue/deque
- Automatically archives patient records
- Stores discharge information in Binary Search Tree
- Maintains complete patient history

### 4. **Fast Patient Search**
- BST-based search by patient ID
- O(log n) average search complexity
- Quick retrieval of discharged patient records

### 5. **Undo/Redo Operations**
- Stack-based operation history
- Revert recent administrative actions
- Redo previously undone operations
- Useful for error correction

### 6. **Patient Sorting**
- Sort by severity level
- Sort by arrival time
- Sort by department
- Flexible sorting using vectors

### 7. **Archive Management**
- Linked list-based patient archive
- Maintains historical records
- Sequential access to past patients

## 🗂️ Data Structures Used

| Data Structure | Purpose | Operations | Complexity |
|----------------|---------|------------|------------|
| **Queue** | Normal patient admission (FIFO) | Enqueue, Dequeue | O(1) |
| **Deque** | Emergency patient priority handling | Push front, Pop | O(1) |
| **Binary Search Tree** | Store and search discharged patients | Insert, Search, Display | O(log n) avg |
| **Stack** | Undo/Redo operation tracking | Push, Pop | O(1) |
| **Singly Linked List** | Archive discharged patient records | Insert, Traverse | O(n) |
| **Vector** | Patient sorting (severity, time, dept) | Sort, Access | O(n log n) |

### Why These Structures?

- **Queue**: Perfect for FIFO patient admission flow
- **Deque**: Allows priority insertion at front for emergencies
- **BST**: Enables fast searching of discharged patients by ID
- **Stack**: Natural fit for undo/redo (LIFO) operations
- **Linked List**: Efficient for sequential archive storage
- **Vector**: Flexible container with built-in sorting capabilities

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────┐
│         PATIENT MANAGEMENT SYSTEM           │
└─────────────────────────────────────────────┘
                    │
        ┌───────────┴───────────┐
        │                       │
   ┌────▼────┐            ┌─────▼─────┐
   │ NORMAL  │            │ EMERGENCY │
   │ QUEUE   │            │   DEQUE   │
   └────┬────┘            └─────┬─────┘
        │                       │
        └───────────┬───────────┘
                    │
              ┌─────▼──────┐
              │ DISCHARGE  │
              └─────┬──────┘
                    │
        ┌───────────┼───────────┐
        │           │           │
   ┌────▼────┐ ┌───▼───┐  ┌────▼─────┐
   │   BST   │ │ STACK │  │ ARCHIVE  │
   │ SEARCH  │ │ UNDO/ │  │  LINKED  │
   │         │ │ REDO  │  │   LIST   │
   └─────────┘ └───────┘  └──────────┘
```

## 🚀 Installation

### Prerequisites

- C++ compiler (GCC, Clang, MSVC, or similar)
- C++11 or higher
- Git (for cloning the repository)

### Clone the Repository

```bash
git clone https://github.com/bijoyverse/Smart-Hospital-Patient-Management-System.git
cd Smart-Hospital-Patient-Management-System
```

### Compilation

#### Using GCC/G++
```bash
g++ main.cpp -o hospital
```

#### Using Clang++
```bash
clang++ main.cpp -o hospital
```

#### Using MSVC (Windows)
```bash
cl main.cpp /Fe:hospital.exe
```

### Running the Program

#### Linux/Mac
```bash
./hospital
```

#### Windows
```bash
hospital.exe
```

## 💻 Usage

### Starting the System

When you run the program, you'll see the main menu:

```
╔════════════════════════════════════════════╗
║   SMART HOSPITAL MANAGEMENT SYSTEM         ║
╚════════════════════════════════════════════╝

1. Admit Normal Patient
2. Admit Emergency Patient
3. Discharge Patient
4. Search Patient by ID
5. Undo Last Operation
6. Redo Operation
7. Display All Discharged Patients (BST)
8. Display Archive
9. Sort Patients
0. Exit

Enter your choice: 
```

### Example Workflow

#### 1. Admitting a Normal Patient
```
Enter choice: 1
Enter Patient ID: 101
Enter Patient Name: John Doe
Enter Age: 45
Enter Department: Cardiology
Patient admitted successfully!
```

#### 2. Admitting an Emergency Patient
```
Enter choice: 2
Enter Patient ID: 201
Enter Patient Name: Jane Smith
Enter Age: 30
Enter Department: Emergency
Emergency patient admitted with priority!
```

#### 3. Discharging a Patient
```
Enter choice: 3
Emergency patient Jane Smith (ID: 201) discharged.
Record stored in BST and archive.
```

#### 4. Searching for a Patient
```
Enter choice: 4
Enter Patient ID to search: 201
Patient Found:
ID: 201 | Name: Jane Smith | Age: 30 | Department: Emergency
```

#### 5. Using Undo
```
Enter choice: 5
Last operation undone successfully!
```

## 📝 Menu Options

| Option | Function | Description |
|--------|----------|-------------|
| **1** | Admit Normal Patient | Add patient to normal queue |
| **2** | Admit Emergency Patient | Add patient to priority deque |
| **3** | Discharge Patient | Process next patient (emergency first) |
| **4** | Search Patient by ID | Find discharged patient in BST |
| **5** | Undo | Revert last operation |
| **6** | Redo | Restore undone operation |
| **7** | Display BST | Show all discharged patients (sorted) |
| **8** | Display Archive | Show archived patient list |
| **9** | Sort Patients | Sort by severity/time/department |
| **0** | Exit | Close the application |

## 🔧 Implementation Details

### Core Classes

#### Patient Class
```cpp
class Patient {
    int id;
    string name;
    int age;
    string department;
    time_t arrivalTime;
    bool isEmergency;
};
```

#### Binary Search Tree Node
```cpp
struct BSTNode {
    Patient data;
    BSTNode* left;
    BSTNode* right;
};
```

#### Linked List Node
```cpp
struct ListNode {
    Patient data;
    ListNode* next;
};
```

### Key Algorithms

**BST Insertion (O(log n) average)**
```cpp
BSTNode* insert(BSTNode* root, Patient p) {
    if (root == nullptr) return new BSTNode(p);
    if (p.id < root->data.id)
        root->left = insert(root->left, p);
    else
        root->right = insert(root->right, p);
    return root;
}
```

**BST Search (O(log n) average)**
```cpp
Patient* search(BSTNode* root, int id) {
    if (root == nullptr) return nullptr;
    if (root->data.id == id) return &root->data;
    if (id < root->data.id)
        return search(root->left, id);
    return search(root->right, id);
}
```

## 📚 Learning Outcomes

Through this project, you will gain:

### Technical Skills
- ✅ Practical implementation of Queue, Deque, Stack, BST, and Linked List
- ✅ Understanding of time and space complexity
- ✅ C++ STL container usage and manipulation
- ✅ Object-oriented programming principles
- ✅ Memory management and pointer manipulation

### Problem-Solving Skills
- ✅ Breaking down complex problems into manageable components
- ✅ Choosing appropriate data structures for specific tasks
- ✅ Designing efficient algorithms for real-world scenarios
- ✅ Handling edge cases and error conditions

### Software Development
- ✅ Code organization and modular design
- ✅ User interface design for console applications
- ✅ Documentation and code commenting
- ✅ Version control with Git

## 🔮 Future Enhancements

### Planned Features

- [ ] **File Handling**: Persistent data storage using file I/O
- [ ] **Priority Queue**: Severity-based patient prioritization
- [ ] **GUI Interface**: Graphical user interface using Qt or similar
- [ ] **Multi-threading**: Concurrent patient processing
- [ ] **Database Integration**: MySQL/SQLite for data persistence
- [ ] **Authentication**: Role-based access control (Doctor, Nurse, Admin)
- [ ] **Reporting**: Generate patient statistics and reports
- [ ] **Appointment Scheduling**: Calendar-based appointment system
- [ ] **Billing Module**: Patient billing and invoice generation
- [ ] **Notification System**: Alerts for critical patients

### Technical Improvements

- [ ] Exception handling for robust error management
- [ ] Unit testing framework integration
- [ ] Code refactoring for better maintainability
- [ ] Performance optimization for large datasets
- [ ] Cross-platform compatibility testing

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/YourFeature
   ```
3. **Commit your changes**
   ```bash
   git commit -m "Add YourFeature"
   ```
4. **Push to the branch**
   ```bash
   git push origin feature/YourFeature
   ```
5. **Open a Pull Request**

### Contribution Guidelines

- Follow existing code style and conventions
- Add comments for complex logic
- Update documentation for new features
- Test thoroughly before submitting
- Write meaningful commit messages

## 👨‍💻 Author

**Md. Biplob Hasan Bijoy**  
CSE Undergraduate

- GitHub: [@bijoyverse](https://github.com/bijoyverse)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2025 Md. Biplob Hasan Bijoy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
```

## 🙏 Acknowledgments

- Inspired by real-world hospital management systems
- Built as part of Data Structures & Algorithms coursework
- Thanks to the open-source community for inspiration and support

## 📞 Support

If you encounter any issues or have questions:

1. Check the [Issues](https://github.com/bijoyverse/Smart-Hospital-Patient-Management-System/issues) page
2. Create a new issue with detailed description
3. Contact the author directly

---

**⭐ Star this repository if you find it helpful!**

**🔗 Share with others learning Data Structures & Algorithms**

