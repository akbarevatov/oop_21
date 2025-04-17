#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    string role;
    string shift;

public:
    Employee(const string& name, const string& role, const string& shift)
        : name(name), role(role), shift(shift) {}

    virtual ~Employee() {}

    void assignTask(const string& task) {
        cout << role << " " << name << " is assigned to: " << task << endl;
    }

    void changeShift(const string& newShift) {
        shift = newShift;
        cout << name << "'s shift has been changed to: " << shift << endl;
    }

    virtual void handleOperations() = 0; // Pure virtual
};

#endif //EMPLOYEE_H

