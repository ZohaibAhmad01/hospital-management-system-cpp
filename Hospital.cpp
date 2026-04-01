#include "Hospital.h"
#include "Patient.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

void Hospital::showPatients() {
    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "  No patient records found.\n";
        return;
    }

    string line;
    int count = 0;

    cout << "\n========== All Patients ==========\n";

    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr, name, ageStr, disease;
        getline(iss, idStr,   '|');
        getline(iss, name,    '|');
        getline(iss, ageStr,  '|');
        getline(iss, disease);

        cout << "  ------------------------------\n";
        cout << "  ID      : " << idStr   << "\n"
             << "  Name    : " << name    << "\n"
             << "  Age     : " << ageStr  << "\n"
             << "  Disease : " << disease << "\n";
        ++count;
    }
    file.close();

    if (count == 0)
        cout << "  No patients found.\n";
    else
        cout << "  ------------------------------\n"
             << "  Total: " << count << " patient(s)\n";
}

void Hospital::searchPatient() {
    int searchId;
    cout << "\n========== Search Patient ==========\n";
    cout << "  Enter Patient ID: ";
    while (!(cin >> searchId)) {
        cout << "  Invalid. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "  No patient records found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr, name, ageStr, disease;
        getline(iss, idStr,   '|');
        getline(iss, name,    '|');
        getline(iss, ageStr,  '|');
        getline(iss, disease);

        if (stoi(idStr) == searchId) {
            cout << "\n  Patient Found!\n";
            cout << "  ------------------------------\n";
            cout << "  ID      : " << idStr   << "\n"
                 << "  Name    : " << name    << "\n"
                 << "  Age     : " << ageStr  << "\n"
                 << "  Disease : " << disease << "\n";
            cout << "  ------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "  Patient with ID " << searchId << " not found.\n";

    file.close();
}

void Hospital::deletePatient() {
    int deleteId;
    cout << "\n========== Delete Patient ==========\n";
    cout << "  Enter Patient ID: ";
    while (!(cin >> deleteId)) {
        cout << "  Invalid. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "  No patient records found.\n";
        return;
    }

    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr;
        getline(iss, idStr, '|');

        if (stoi(idStr) == deleteId) {
            found = true;
            continue;
        }
        temp << line << "\n";
    }

    file.close();
    temp.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found)
        cout << "  Patient with ID " << deleteId << " deleted successfully.\n";
    else
        cout << "  Patient with ID " << deleteId << " not found.\n";
}

void Hospital::updatePatient() {
    int updateId;
    cout << "\n========== Update Patient ==========\n";
    cout << "  Enter Patient ID: ";
    while (!(cin >> updateId)) {
        cout << "  Invalid. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "  No patient records found.\n";
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr;
        getline(iss, idStr, '|');

        if (stoi(idStr) == updateId) {
            found = true;

            string newName, newDisease;
            int    newAge;

            cout << "  Enter new Name    : ";
            getline(cin, newName);

            cout << "  Enter new Age     : ";
            while (!(cin >> newAge) || newAge <= 0 || newAge > 150) {
                cout << "  Invalid. Enter age (1-150): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "  Enter new Disease : ";
            getline(cin, newDisease);

            ostringstream oss;
            oss << updateId << "|" << newName << "|" << newAge << "|" << newDisease;
            lines.push_back(oss.str());
        } else {
            lines.push_back(line);
        }
    }
    file.close();

    if (!found) {
        cout << "  Patient with ID " << updateId << " not found.\n";
        return;
    }

    ofstream outFile("patients.txt");
    for (size_t i = 0; i < lines.size(); i++)
        outFile << lines[i] << "\n";
    outFile.close();

    cout << "  Patient updated successfully.\n";
}