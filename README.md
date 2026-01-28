# Student Management System (C – File Handling)

## Project Description
This is a menu-driven Student Management System developed using the C programming language.  
The project performs basic CRUD (Create, Read, Update, Delete) operations on student records using file handling.

Student data is stored permanently in a file named `student.txt`.

---

## Technologies Used
- Language: C
- Compiler: GCC
- File Handling: Binary files

---

## Files Included
student.c   - Main source code  
student.txt - Stores student records (auto-created)  
temp.txt    - Temporary file used during delete operation  
README.md   - Project documentation  

---

## Features
- Add student record  
- View all student records  
- Update student information  
- Delete student record  
- Menu-driven program  
- Persistent storage using file handling  

---

## Student Details Stored
- Student ID  
- Name  
- Age  
- Marks  

---

## Menu Options
1. Add Student  
2. View All Students  
3. Update Student  
4. Delete Student  
5. Exit  

---

## How to Run
1 Clone the repo
```
git clone https://github.com/skeleton111222/Student-Management-System
```
2 Compile the program using the following command:
```
gcc student.c -o student
```
3 After successful compilation, run the program using:
```
./student
```
The menu-driven Student Management System will start and allow you to manage student records.

---

## File Structure
```
Student-Management-System/  
├── Student.c        # Main source code
├── student.txt      # Stores student records (auto-created not uploaded)  
├── temp.txt         # Temporary file used during delete operations  (not uploaded)
└── README.md        # Project documentation
```
---

## Notes
- student.txt is automatically created when the first record is added.  
- temp.txt is used internally during delete operations.  
- All files are stored in the same project directory.  

---

## Future Enhancements
- Search student by ID or name  
- Sort student records  
- Password protection  
- Text file implementation  
- GUI-based version  

---

## Conclusion
This project demonstrates file handling and CRUD operations in C.  
It is suitable for beginners, academic mini-projects, and practical examinations.
