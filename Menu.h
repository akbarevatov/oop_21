#ifndef MENU_H
#define MENU_H

#include "Hotel.h"
#include <iostream>

class Menu {
public:
    Menu();
    // Starts the main menu loop.
    void displayMenu();
    static void clearInput();
private:
    // Submenu options:
    void manageRooms();
    void bookingOperations();
    void employeeOperations();
    void guestOperations();
    void paymentProcessing();
    void generateHotelReport();
    void accessControlOperations();

    // Utility method for clearing cin errors.

    void showAdminMenu();
    void showGuestMenu(Guest* guest);

    // Helper to find guest by name
    Guest* findGuestByName(const std::string& name);
};

#endif // MENU_H
