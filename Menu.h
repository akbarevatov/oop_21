#ifndef MENU_H
#define MENU_H

#include "Hotel.h"
#include <iostream>

class Menu {
public:
    Menu();
    // Starts the main menu loop.
    void displayMenu();

private:
    // Submenu options:
    void manageRooms();
    void bookingOperations();
    void employeeOperations();
    void guestOperations();
    void loyaltyOperations();
    void paymentProcessing();
    void feedbackOperations();
    void generateHotelReport();
    void accessControlOperations();

    // Utility method for clearing cin errors.
    void clearInput();
};

#endif // MENU_H
