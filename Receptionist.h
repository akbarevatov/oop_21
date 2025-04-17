#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include <iostream>
#include "Employee.h"
using namespace std;

class Receptionist : public Employee {
public:
    Receptionist(const string& name, const string& shift)
        : Employee(name, "Receptionist", shift) {}

    void handleOperations() override {
        checkGuestIn();
    }

    void checkGuestIn() {
        cout << "Receptionist " << name << " is checking in a guest." << endl;
    }
};

#endif //RECEPTIONIST_H

