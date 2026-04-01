#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;

public:
    Person() : name("") {}
    virtual ~Person() = default;

    void        setName(const std::string& n) { name = n; }
    std::string getName() const               { return name; }
};

#endif