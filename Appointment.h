#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Doctor.h"
#include <string>

class Appointment : public Doctor {
private:
    int         patientId;
    std::string date;

public:
    Appointment() : patientId(0), date("") {}

    int         getPatientId() const { return patientId; }
    std::string getDate()      const { return date; }

    void book();
    void display() const;
    static void showAll();
};

#endif