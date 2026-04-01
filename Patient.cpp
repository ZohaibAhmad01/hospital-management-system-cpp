#include "Patient.h"
#include <fstream>

void Patient::input() {
    std::cout << "Enter ID: ";
    std::cin >> id;

    std::cout << "Enter Name: ";
    std::cin >> name;

    std::cout << "Enter Age: ";
    std::cin >> age;

    std::cout << "Enter Disease: ";
    std::cin >> disease;
}

void Patient::save() {
    std::ofstream file("patients.txt", std::ios::app);

    if (file.is_open()) {
        file << id << " " << name << " " << age << " " << disease << std::endl;
        file.close();
    }
}