#include "Appointment.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

void Appointment::book() {
    cout << "\n========== Book Appointment ==========\n";

    cout << "  Enter Patient ID        : ";
    while (!(cin >> patientId) || patientId <= 0) {
        cout << "  Invalid. Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ifstream pFile("patients.txt");
    bool found = false;
    string line;
    while (getline(pFile, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr;
        getline(iss, idStr, '|');
        if (stoi(idStr) == patientId) { found = true; break; }
    }
    pFile.close();

    if (!found) {
        cout << "  Error: Patient ID " << patientId
             << " not found. Register the patient first.\n";
        return;
    }

    cout << "  Enter Doctor Name       : ";
    getline(cin, doctorName);

    cout << "  Enter Date (DD/MM/YYYY) : ";
    getline(cin, date);

    ofstream file("appointments.txt", ios::app);
    if (!file.is_open()) {
        cerr << "  Error: Could not open appointments.txt\n";
        return;
    }
    file << patientId << "|" << doctorName << "|" << date << "\n";
    file.close();

    cout << "  Appointment booked successfully!\n";
}

void Appointment::display() const {
    cout << "  Patient ID : " << patientId  << "\n"
         << "  Doctor     : " << doctorName << "\n"
         << "  Date       : " << date       << "\n";
}

void Appointment::showAll() {
    ifstream file("appointments.txt");
    if (!file.is_open()) {
        cout << "  No appointment records found.\n";
        return;
    }

    string line;
    int count = 0;

    cout << "\n========== All Appointments ==========\n";

    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string pidStr, doctor, dt;
        getline(iss, pidStr, '|');
        getline(iss, doctor, '|');
        getline(iss, dt);

        cout << "  ------------------------------\n";
        cout << "  Patient ID : " << pidStr  << "\n"
             << "  Doctor     : " << doctor  << "\n"
             << "  Date       : " << dt      << "\n";
        ++count;
    }
    file.close();

    if (count == 0)
        cout << "  No appointments found.\n";
    else
        cout << "  ------------------------------\n"
             << "  Total: " << count << " appointment(s)\n";
}