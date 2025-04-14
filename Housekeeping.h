#ifndef HOUSEKEEPING_H
#define HOUSEKEEPING_H
#include <iostream>
#include "Employee.h"
using namespace std;

class Housekeeping : public Employee {
public:
    Housekeeping(const string& name, const string& shift)
        : Employee(name, "Housekeeping", shift) {}

    void handleOperations() override {
        cleanRoom();
    }

    void cleanRoom() {
        cout << "Housekeeping " << name << " is cleaning the room." << endl;
    }
};
#endif //HOUSEKEEPING_H
