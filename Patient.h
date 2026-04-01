#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <iostream>
#include <string>

class Patient : public Person {
private:
    int         id;
    int         age;
    std::string disease;

public:
    Patient() : id(0), age(0), disease("") {}
    Patient(int id, const std::string& name, int age, const std::string& disease);

    int         getId()      const { return id; }
    int         getAge()     const { return age; }
    std::string getDisease() const { return disease; }

    void setId(int i)                     { id = i; }
    void setAge(int a)                    { age = a; }
    void setDisease(const std::string& d) { disease = d; }

    void input();
    bool save() const;
    void display() const;
};

#endif