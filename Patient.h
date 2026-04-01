#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
};

class Patient : public Person {
public:
    int id;
    int age;
    std::string disease;

    void input();
    void save();
};

#endif