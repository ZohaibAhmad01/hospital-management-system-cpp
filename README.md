<img width="1219" height="953" alt="add_patient" src="https://github.com/user-attachments/assets/32a79276-d265-4aeb-80a4-deda64de541e" />
<img width="1219" height="953" alt="view_pateint" src="https://github.com/user-attachments/assets/52f38154-550e-40bd-92cf-7e92770d5e2b" />
<img width="1219" height="953" alt="add_appointment_and_view_appointment" src="https://github.com/user-attachments/assets/43fed153-cf09-498a-ab45-6f089e6601fa" />

==============================
HOSPITAL MANAGEMENT SYSTEM
==============================

A C++ console application for managing hospital operations including
patient records and appointment scheduling.

------------------------------------------------------------
TABLE OF CONTENTS
------------------------------------------------------------
1. Overview
2. Features
3. Technologies & Concepts
4. System Architecture
5. File Structure
6. Installation & Compilation
7. Usage Guide
8. Data Storage Format
9. Code Functionality
10. OOP Concepts
11. Error Handling
12. Future Enhancements
13. Contributing
14. License
15. Contact & Support
16. Acknowledgments
17. Project Stats

------------------------------------------------------------
1. OVERVIEW
------------------------------------------------------------
- Text-based interface for managing patients and appointments
- Full CRUD operations for patients
- Appointment booking with validation
- Persistent data storage in text files
- Menu-driven interface
- Object-oriented design

------------------------------------------------------------
2. FEATURES
------------------------------------------------------------
Patient Management:
- Add, View, Search, Update, Delete patients
- Unique ID, Name, Age, Disease

Appointment Management:
- Book and view appointments
- Patient existence verification

Data Persistence:
- patients.txt and appointments.txt
- Pipe-delimited format
- Retains data between runs

Input Validation:
- Prevents duplicate IDs
- Age: 1-150
- Numeric validation for IDs/menu
- File operation checks

------------------------------------------------------------
3. TECHNOLOGIES & CONCEPTS
------------------------------------------------------------
- C++11 Standard
- Classes & Objects, Inheritance, Encapsulation, Polymorphism
- File I/O with fstream
- String parsing with stringstream
- Vector for dynamic storage
- Exception safety

Standard Libraries:
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>

------------------------------------------------------------
4. SYSTEM ARCHITECTURE
------------------------------------------------------------
main.cpp
- Menu & input handling
Hospital
- CRUD & search
Appointment
- Booking & validation
Patient -> Person
Doctor (Base)
Appointment -> Doctor
Person (Base)

------------------------------------------------------------
5. FILE STRUCTURE
------------------------------------------------------------
HospitalManagementSystem/
├── Person.h
├── Patient.h / Patient.cpp
├── Doctor.h
├── Appointment.h / Appointment.cpp
├── Hospital.h / Hospital.cpp
├── main.cpp
├── patients.txt
├── appointments.txt
└── readme.txt

------------------------------------------------------------
6. INSTALLATION & COMPILATION
------------------------------------------------------------
Requirements:
- GCC/G++ (C++11+)
- Linux/macOS/Windows

Compile:
g++ -std=c++11 -o hospital main.cpp Patient.cpp Hospital.cpp Appointment.cpp

Run:
./hospital       (Linux/macOS)
hospital.exe     (Windows)

------------------------------------------------------------
7. USAGE GUIDE
------------------------------------------------------------
Main Menu:
1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Book Appointment
7. View All Appointments
8. Exit

Workflow Examples:
- Add Patient: Input ID, Name, Age, Disease
- Book Appointment: Input Patient ID, Doctor, Date
- Search Patient: Enter ID
- Update Patient: Enter new info
- View Patients: Lists all records

------------------------------------------------------------
8. DATA STORAGE FORMAT
------------------------------------------------------------
patients.txt
Format: ID|Name|Age|Disease
Example:
101|John Doe|45|Hypertension

appointments.txt
Format: PatientID|DoctorName|Date
Example:
101|Dr. Sarah Smith|15/06/2024

------------------------------------------------------------
9. CODE FUNCTIONALITY
------------------------------------------------------------
Person.h: Base class with name
Patient: input(), save(), display()
Hospital: CRUD operations with files
Appointment: book(), verify patient, showAll()

------------------------------------------------------------
10. OOP CONCEPTS
------------------------------------------------------------
- Inheritance: Person->Patient, Doctor->Appointment
- Encapsulation: Private members, getters/setters
- Polymorphism: Virtual destructors
- Abstraction: Simple user methods hide file handling

------------------------------------------------------------
11. ERROR HANDLING
------------------------------------------------------------
- Input validation
- File operation checks
- Duplicate ID prevention
- Patient verification
- Atomic file operations

------------------------------------------------------------
12. FUTURE ENHANCEMENTS
------------------------------------------------------------
- User authentication
- Search by Name
- Appointment cancellation
- Bill generation
- Medical history tracking
- Doctor schedule management
- Database integration
- GUI interface
- Report generation
- Multi-language support
- JSON/XML storage
- Unit testing & logging
- Date validation
- Encryption & backup/restore

------------------------------------------------------------
13. CONTRIBUTING
------------------------------------------------------------
1. Fork repo
2. Create feature branch
3. Commit changes
4. Push branch
5. Open Pull Request

Standards:
- C++11, meaningful names, comments, consistent indentation

------------------------------------------------------------
14. LICENSE
------------------------------------------------------------
MIT License

------------------------------------------------------------
15. CONTACT & SUPPORT
------------------------------------------------------------
Developer: Zohaib Ahmad
Email: ahmadzohaib912@gmail.com
GitHub: https://github.com/ZohaibAhmad01

Report issues via GitHub

------------------------------------------------------------
16. ACKNOWLEDGMENTS
------------------------------------------------------------
- C++ Standard Library
- cppreference.com
- Open-source community

------------------------------------------------------------
17. PROJECT STATS
------------------------------------------------------------
- LOC: ~800
- Files: 9
- Classes: 5 (Person, Patient, Doctor, Appointment, Hospital)
- Methods: 15+
- Development: Educational

==============================
Made with ❤️ in C++
==============================
