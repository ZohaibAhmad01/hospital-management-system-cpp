#include "Patient.h"
#include <fstream>
#include <sstream>
#include <limits>

Patient::Patient(int id, const std::string& name, int age, const std::string& disease)
    : id(id), age(age), disease(disease)
{
    this->name = name;
}

void Patient::input() {
    std::cout << "\n========== Add New Patient ==========\n";

    std::cout << "  Enter Patient ID   : ";
    while (!(std::cin >> id) || id <= 0) {
        std::cout << "  Invalid. Enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Enter Patient Name : ";
    std::getline(std::cin, name);

    std::cout << "  Enter Patient Age  : ";
    while (!(std::cin >> age) || age <= 0 || age > 150) {
        std::cout << "  Invalid. Enter age (1-150): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Enter Disease      : ";
    std::getline(std::cin, disease);
}

bool Patient::save() const {
    std::ifstream inFile("patients.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.empty()) continue;
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, '|');
            if (std::stoi(idStr) == id) {
                std::cerr << "  Error: Patient with ID "
                          << id << " already exists.\n";
                inFile.close();
                return false;
            }
        }
        inFile.close();
    }

    std::ofstream file("patients.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "  Error: Could not open patients.txt\n";
        return false;
    }
    file << id << "|" << name << "|" << age << "|" << disease << "\n";
    file.close();
    return true;
}

void Patient::display() const {
    std::cout << "  ID      : " << id      << "\n"
              << "  Name    : " << name    << "\n"
              << "  Age     : " << age     << "\n"
              << "  Disease : " << disease << "\n";
}