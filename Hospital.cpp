#include "Hospital.h"
#include <iostream>
#include <fstream>
using namespace std;

void Hospital::showPatients() {
    ifstream file("patients.txt");
    int id, age;
    string name, disease;

    while (file >> id >> name >> age >> disease) {
        cout << "ID: " << id << " Name: " << name
             << " Age: " << age << " Disease: " << disease << endl;
    }

    file.close();
}

void Hospital::searchPatient() {
    ifstream file("patients.txt");
    int searchId;
    int id, age;
    string name, disease;
    bool found = false;

    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    while (file >> id >> name >> age >> disease) {
        if (id == searchId) {
            cout << "Found: " << id << " " << name << " " << age << " " << disease << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Patient not found." << endl;
    }

    file.close();
}

void Hospital::deletePatient() {
    ifstream file("patients.txt");
    ofstream temp("temp.txt");

    int deleteId;
    int id, age;
    string name, disease;

    cout << "Enter Patient ID to delete: ";
    cin >> deleteId;

    while (file >> id >> name >> age >> disease) {
        if (id != deleteId) {
            temp << id << " " << name << " " << age << " " << disease << endl;
        }
    }

    file.close();
    temp.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    cout << "Patient deleted if found." << endl;
}