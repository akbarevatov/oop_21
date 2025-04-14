#include <iostream>
#include <string>
#include <map>
#include "Employee.h"
#include "Manager.h"
#include "Receptionist.h"
#include "Housekeeping.h"
#include "AccessControl.h"

using namespace std;


int main() {
    Manager mgr("Amina", "Morning");
    Receptionist rec("Bilal", "Evening");
    Housekeeping hk("Fatima", "Night");

    mgr.assignTask("Review reports");
    rec.assignTask("Check-in guests");
    hk.assignTask("Clean floor 2");

    mgr.handleOperations();
    rec.handleOperations();
    hk.handleOperations();

    mgr.changeShift("Evening");

    AccessControl access;
    access.grantAccess("Manager", "Full Access");
    access.grantAccess("Receptionist", "Front Desk Access");
    access.grantAccess("Housekeeping", "Room Access");

    access.showPermissions();

    access.restrictAccess("Housekeeping");

    access.showPermissions();

    return 0;
}
