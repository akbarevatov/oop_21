
#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Employee.h"
using namespace std;

class Manager : public Employee {
public:
    Manager(const string& name, const string& shift)
        : Employee(name, "Manager", shift) {}

    void handleOperations() override {
        cout << "Manager " << name << " is handling staff schedules and reports." << endl;
    }
};
#endif //MANAGER_H
