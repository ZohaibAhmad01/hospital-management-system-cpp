#include <iostream>
#include <limits>
#include "Patient.h"
#include "Hospital.h"
#include "Appointment.h"

using namespace std;

void displayMenu() {
    cout << "\n======================================\n";
    cout << "    HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "======================================\n";
    cout << "  1.  Add Patient\n";
    cout << "  2.  View All Patients\n";
    cout << "  3.  Search Patient\n";
    cout << "  4.  Update Patient\n";
    cout << "  5.  Delete Patient\n";
    cout << "  6.  Book Appointment\n";
    cout << "  7.  View All Appointments\n";
    cout << "  8.  Exit\n";
    cout << "======================================\n";
    cout << "  Enter your choice: ";
}

int main() {
    int choice;
    Hospital hospital;

    do {
        displayMenu();

        while (!(cin >> choice)) {
            cout << "  Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                Patient p;
                p.input();
                if (p.save())
                    cout << "  Patient added successfully!\n";
                break;
            }
            case 2:
                hospital.showPatients();
                break;
            case 3:
                hospital.searchPatient();
                break;
            case 4:
                hospital.updatePatient();
                break;
            case 5:
                hospital.deletePatient();
                break;
            case 6: {
                Appointment a;
                a.book();
                break;
            }
            case 7:
                Appointment::showAll();
                break;
            case 8:
                cout << "\n  Thank you! Goodbye!\n\n";
                break;
            default:
                cout << "  Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}