#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Doctor.h"

class Appointment : public Doctor {
public:
    int patientId;
    std::string date;

    void book();
};

#endif