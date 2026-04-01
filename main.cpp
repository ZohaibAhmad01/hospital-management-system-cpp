#include <iostream>
#include "Patient.h"
#include "Hospital.h"
#include "Appointment.h"

using namespace std;

int main() {
    int choice;
    Patient p;
    Hospital h;
    Appointment a;

    do {
        cout << "\n1. Add Patient";
        cout << "\n2. View Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Delete Patient";
        cout << "\n5. Book Appointment";
        cout << "\n6. Exit";
        cout << "\nChoice: ";

        cin >> choice;

        switch(choice) {
            case 1:
                p.input();
                p.save();
                break;

            case 2:
                h.showPatients();
                break;

            case 3:
                h.searchPatient();
                break;

            case 4:
                h.deletePatient();
                break;

            case 5:
                a.book();
                break;
        }

    } while(choice != 6);

    return 0;
}