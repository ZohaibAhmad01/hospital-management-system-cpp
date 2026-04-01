#include "Appointment.h"
#include <iostream>
#include <fstream>

using namespace std;

void Appointment::book() {
    ofstream file("appointments.txt", ios::app);

    cout << "Enter Patient ID: ";
    cin >> patientId;

    cout << "Enter Doctor Name: ";
    cin >> doctorName;

    cout << "Enter Date: ";
    cin >> date;

    file << patientId << " " << doctorName << " " << date << endl;

    file.close();

    cout << "Appointment booked successfully." << endl;
}