#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
protected:
    std::string doctorName;

public:
    Doctor() : doctorName("") {}
    virtual ~Doctor() = default;

    void        setDoctorName(const std::string& n) { doctorName = n; }
    std::string getDoctorName() const               { return doctorName; }
};

#endif