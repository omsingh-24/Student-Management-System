# Student Management System in C

## About the Project

This is a console-based Student Management System built using C. The project allows users to store and manage student records through a simple menu-driven interface.

Student data is stored in a binary file, so records remain available even after the program is closed.

---

## Features

- Add a new student
- View all student records
- Search a student by roll number
- Update student information
- Delete student records
- Store records permanently using file handling

---

## Technologies Used

- C
- Structures
- Functions
- File Handling
- Binary Files

---

## Student Structure

```c
struct Student
{
    int roll;
    char name[50];
    float cgpa;
};
```

---

## Project Structure

```text
Student-Management-System/
│
├── student management system.c
└── README.md
```

---

## Menu

```text
========== STUDENT MANAGEMENT SYSTEM ==========

1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## How It Works

### Add Student

The user enters:

- Roll Number
- Name
- CGPA

The record is saved to `students.dat`.

### View Students

Displays all stored student records.

### Search Student

Finds a student using their roll number.

### Update Student

Allows modification of an existing student's details.

### Delete Student

Removes a student record from the file using a temporary file approach.

---

## Sample Output

### Adding a Student

```text
Enter Roll Number: 101
Enter Name: Om Singh
Enter CGPA: 9.685

Student Added Successfully
```

### Viewing Students

```text
ROLL    NAME            CGPA

101     Om Singh        9.685
102     Rahul Sharma    8.91
```

---

## What I Practiced

While building this project, I worked with:

- Structures
- Functions
- Binary file handling
- Searching records
- CRUD operations
- Temporary files for update/delete operations

---

## Possible Improvements

Some features I would like to add in the future:

- Login system
- Sorting by CGPA
- Student statistics
- Database integration
- GUI version

---

## Compilation

### Linux / macOS

```bash
gcc main.c -o student
./student
```

### Windows

```bash
gcc main.c -o student.exe
student.exe
```

---

## Author

**Om Singh**

- B.Tech COPC 
- Thapar Institute of Engineering and Technology
