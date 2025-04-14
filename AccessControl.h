#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H
#include <iostream>
using namespace std;

class AccessControl {
private:
    map<string, string> rolePermissions;

public:
    void grantAccess(const string& role, const string& permission) {
        rolePermissions[role] = permission;
        cout << "Access granted: " << role << " -> " << permission << endl;
    }

    void restrictAccess(const string& role) {
        rolePermissions.erase(role);
        cout << "Access restricted for role: " << role << endl;
    }

    void showPermissions() const {
        cout << "\nCurrent Permissions:" << endl;
        for (const auto& pair : rolePermissions) {
            cout << "- " << pair.first << ": " << pair.second << endl;
        }
    }
};

#endif //ACCESSCONTROL_H
