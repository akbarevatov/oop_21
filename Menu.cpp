#include "Menu.h"
#include "Room.h"
#include "Receptionist.h"
#include "Manager.h"
#include "Housekeeping.h"
#include "PayPalPayment.h"
#include "CreditCardPayment.h"
#include "Guest.h"
#include "LoyaltyCard.h"
#include "Feedback.h"
#include "Booking.h"
#include "AccessControl.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Menu::Menu() {
    // Optionally, preload some initial data.
}

void Menu::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Menu::displayMenu() {
    int choice = 0;
    do {
        cout << "\n========== Hotel Management System ==========" << endl;
        cout << "1. Manage Rooms" << endl;
        cout << "2. Booking Operations" << endl;
        cout << "3. Employee Operations" << endl;
        cout << "4. Guest Operations" << endl;
        cout << "5. Loyalty Card Operations" << endl;
        cout << "6. Payment Processing" << endl;
        cout << "7. Feedback Operations" << endl;
        cout << "8. Generate Hotel Report" << endl;
        cout << "9. Access Control Operations" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(cin.fail()){
            clearInput();
            choice = 0;
        }
        switch (choice) {
            case 1:
                manageRooms();
                break;
            case 2:
                bookingOperations();
                break;
            case 3:
                employeeOperations();
                break;
            case 4:
                guestOperations();
                break;
            case 5:
                loyaltyOperations();
                break;
            case 6:
                paymentProcessing();
                break;
            case 7:
                feedbackOperations();
                break;
            case 8:
                generateHotelReport();
                break;
            case 9:
                accessControlOperations();
                break;
            case 10:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
        }
    } while (choice != 10);
}

// Option 1: Room Management
void Menu::manageRooms() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    do {
        cout << "\n----- Manage Rooms -----" << endl;
        cout << "1. Add Room" << endl;
        cout << "2. List All Rooms" << endl;
        cout << "3. Check-In a Room" << endl;
        cout << "4. Check-Out a Room" << endl;
        cout << "5. Schedule Room Maintenance" << endl;
        cout << "6. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                int number;
                double price;
                string status;
                cout << "Enter room number: ";
                cin >> number;
                cout << "Enter room price: ";
                cin >> price;
                cout << "Enter initial status (Available/Occupied): ";
                cin >> status;
                Room r(number, status, price);
                hotel.addRoom(r);
                cout << "Room added successfully." << endl;
                break;
            }
            case 2: {
                cout << "\nList of Rooms:" << endl;
                vector<Room>& rooms = hotel.getRooms();
                for (const Room& r : rooms) {
                    cout << "Room " << r.getRoomNumber()
                         << " | Status: " << r.getStatus()
                         << " | Price: $" << r.getPrice() << endl;
                }
                break;
            }
            case 3: {
                int roomNum;
                cout << "Enter room number for check-in: ";
                cin >> roomNum;
                vector<Room>& rooms = hotel.getRooms();
                bool found = false;
                for (Room& r : rooms) {
                    if (r.getRoomNumber() == roomNum) {
                        if (r.isAvailable()) {
                            r.checkIn();
                            cout << "Room " << roomNum << " is now occupied." << endl;
                        } else {
                            cout << "Room " << roomNum << " is not available for check-in." << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Room not found." << endl;
                break;
            }
            case 4: {
                int roomNum;
                cout << "Enter room number for check-out: ";
                cin >> roomNum;
                vector<Room>& rooms = hotel.getRooms();
                bool found = false;
                for (Room& r : rooms) {
                    if (r.getRoomNumber() == roomNum) {
                        r.checkOut();
                        cout << "Room " << roomNum << " is now available." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Room not found." << endl;
                break;
            }
            case 5: {
                int roomNum;
                cout << "Enter room number for scheduling maintenance: ";
                cin >> roomNum;
                vector<Room>& rooms = hotel.getRooms();
                bool found = false;
                for (Room& r : rooms) {
                    if (r.getRoomNumber() == roomNum) {
                        r.scheduleMaintenance();
                        cout << "Room " << roomNum << " marked for maintenance." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Room not found." << endl;
                break;
            }
            case 6:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please choose again." << endl;
        }
    } while (subChoice != 6);
}

// Option 2: Booking Operations
void Menu::bookingOperations() {
    Hotel& hotel = Hotel::getInstance();
    int subChoice = 0;
    do {
        cout << "\n----- Booking Operations -----" << endl;
        cout << "1. Create Booking (default dates)" << endl;
        cout << "2. Create Booking (custom dates)" << endl;
        cout << "3. Modify Booking" << endl;
        cout << "4. Cancel Booking" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                // Create booking with default dates.
                string guestName, contact, guestId;
                int roomNum;
                cout << "Enter guest name: ";
                cin >> guestName;
                cout << "Enter contact info: ";
                cin >> contact;
                cout << "Enter guest ID: ";
                cin >> guestId;
                Guest* g = new Guest(guestName, contact, guestId);
                cout << "Enter room number for booking: ";
                cin >> roomNum;
                vector<Room>& rooms = hotel.getRooms();
                bool found = false;
                for (Room& r : rooms) {
                    if (r.getRoomNumber() == roomNum && r.isAvailable()) {
                        hotel.createBooking(g, r); // Uses default dates
                        cout << "Booking created successfully." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Room not available or not found." << endl;
                break;
            }
            case 2: {
                // Create booking with custom dates.
                string guestName, contact, guestId, startDate, endDate;
                int roomNum;
                cout << "Enter guest name: ";
                cin >> guestName;
                cout << "Enter contact info: ";
                cin >> contact;
                cout << "Enter guest ID: ";
                cin >> guestId;
                Guest* g = new Guest(guestName, contact, guestId);
                cout << "Enter room number for booking: ";
                cin >> roomNum;
                cout << "Enter start date (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter end date (YYYY-MM-DD): ";
                cin >> endDate;
                vector<Room>& rooms = hotel.getRooms();
                bool found = false;
                for (Room& r : rooms) {
                    if (r.getRoomNumber() == roomNum && r.isAvailable()) {
                        hotel.createBooking(g, r, startDate, endDate);
                        cout << "Booking created successfully with custom dates." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Room not available or not found." << endl;
                break;
            }
            case 3: {
                // Modify an existing booking.
                string bookingID, newStart, newEnd;
                cout << "Enter booking ID to modify: ";
                cin >> bookingID;
                vector<Booking*>& bookings = hotel.getBookings();
                bool found = false;
                for (Booking* b : bookings) {
                    if (b->getBookingID() == bookingID) {
                        cout << "Enter new start date (YYYY-MM-DD): ";
                        cin >> newStart;
                        cout << "Enter new end date (YYYY-MM-DD): ";
                        cin >> newEnd;
                        b->modifyBooking(newStart, newEnd);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Booking not found." << endl;
                break;
            }
            case 4: {
                // Cancel an existing booking.
                string bookingID;
                cout << "Enter booking ID to cancel: ";
                cin >> bookingID;
                vector<Booking*>& bookings = hotel.getBookings();
                bool found = false;
                for (Booking* b : bookings) {
                    if (b->getBookingID() == bookingID) {
                        b->cancelBooking();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Booking not found." << endl;
                break;
            }
            case 5:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 5);
}

// Option 3: Employee Operations
void Menu::employeeOperations() {
    int subChoice = 0;
    do {
        cout << "\n----- Employee Operations -----" << endl;
        cout << "1. Receptionist Operation" << endl;
        cout << "2. Manager Operation" << endl;
        cout << "3. Housekeeping Operation" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                string name, shift;
                cout << "Enter Receptionist name: ";
                cin >> name;
                cout << "Enter shift: ";
                cin >> shift;
                Receptionist r(name, shift);
                r.handleOperations();
                break;
            }
            case 2: {
                string name, shift;
                cout << "Enter Manager name: ";
                cin >> name;
                cout << "Enter shift: ";
                cin >> shift;
                Manager m(name, shift);
                m.handleOperations();
                break;
            }
            case 3: {
                string name, shift;
                cout << "Enter Housekeeping name: ";
                cin >> name;
                cout << "Enter shift: ";
                cin >> shift;
                Housekeeping h(name, shift);
                h.handleOperations();
                break;
            }
            case 4:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 4);
}

// Option 4: Guest Operations
void Menu::guestOperations() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    do {
        cout << "\n----- Guest Operations -----" << endl;
        cout << "1. Add a Guest" << endl;
        cout << "2. View Guest Booking History" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                string name, contact, id;
                cout << "Enter guest name: ";
                cin >> name;
                cout << "Enter contact info: ";
                cin >> contact;
                cout << "Enter guest ID: ";
                cin >> id;
                Guest* g = new Guest(name, contact, id);
                hotel.getGuests().push_back(g);
                cout << "Guest added successfully." << endl;
                break;
            }
            case 2: {
                string name;
                cout << "Enter guest name to view booking history: ";
                cin >> name;
                vector<Guest*>& guests = hotel.getGuests();
                bool found = false;
                for (Guest* g : guests) {
                    if (g->getName() == name) {
                        g->viewBookingHistory();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Guest not found." << endl;
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 3);
}

// Option 5: Loyalty Card Operations
void Menu::loyaltyOperations() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    do {
        cout << "\n----- Loyalty Card Operations -----" << endl;
        cout << "1. Create Loyalty Card for Guest" << endl;
        cout << "2. Add Points" << endl;
        cout << "3. Redeem Points" << endl;
        cout << "4. Check Points Balance" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        static LoyaltyCard* loyaltyCard = nullptr; // For demonstration; one loyalty card instance
        switch (subChoice) {
            case 1: {
                string guestName, contact, id;
                cout << "Enter guest name: ";
                cin >> guestName;
                cout << "Enter contact info: ";
                cin >> contact;
                cout << "Enter guest ID: ";
                cin >> id;
                Guest* g = new Guest(guestName, contact, id);
                hotel.getGuests().push_back(g);
                loyaltyCard = new LoyaltyCard(0.0f, *g);
                cout << "Loyalty card created for " << g->getName() << endl;
                break;
            }
            case 2: {
                if (loyaltyCard) {
                    float purchase;
                    cout << "Enter purchase amount to add points: ";
                    cin >> purchase;
                    loyaltyCard->addPoints(purchase);
                    cout << "Points added." << endl;
                } else {
                    cout << "No loyalty card found. Create one first." << endl;
                }
                break;
            }
            case 3: {
                if (loyaltyCard) {
                    float redeem;
                    cout << "Enter points to redeem: ";
                    cin >> redeem;
                    loyaltyCard->redeemPoints(redeem);
                } else {
                    cout << "No loyalty card found. Create one first." << endl;
                }
                break;
            }
            case 4: {
                if (loyaltyCard) {
                    cout << "Current points: " << loyaltyCard->checkPoints() << endl;
                } else {
                    cout << "No loyalty card found. Create one first." << endl;
                }
                break;
            }
            case 5:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 5);
}

// Option 6: Payment Processing
void Menu::paymentProcessing() {
    int subChoice = 0;
    do {
        cout << "\n----- Payment Processing -----" << endl;
        cout << "1. Process PayPal Payment" << endl;
        cout << "2. Process Credit Card Payment" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                double amt;
                string email;
                cout << "Enter payment amount: ";
                cin >> amt;
                cout << "Enter PayPal email: ";
                cin >> email;
                PayPalPayment paypal(amt, email);
                paypal.processPayment();
                break;
            }
            case 2: {
                double amt;
                string cardNum, exp, cvv;
                cout << "Enter payment amount: ";
                cin >> amt;
                cout << "Enter credit card number: ";
                cin >> cardNum;
                cout << "Enter expiry date (MM/YY): ";
                cin >> exp;
                cout << "Enter CVV: ";
                cin >> cvv;
                CreditCardPayment ccPayment(amt, cardNum, exp, cvv);
                ccPayment.processPayment();
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 3);
}

// Option 7: Feedback Operations
void Menu::feedbackOperations() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    do {
        cout << "\n----- Feedback Operations -----" << endl;
        cout << "1. Send Feedback" << endl;
        cout << "2. View All Feedbacks" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                string guestName, review;
                cout << "Enter guest name: ";
                cin >> guestName;
                cout << "Enter your review: ";
                cin.ignore();  // Clear newline left in buffer
                getline(cin, review);
                // Find the guest in hotel's guest list.
                Guest* foundGuest = nullptr;
                for (Guest* g : hotel.getGuests()) {
                    if (g->getName() == guestName) {
                        foundGuest = g;
                        break;
                    }
                }
                if (foundGuest) {
                    Feedback fb(*foundGuest, review);
                    fb.sendFeedback(*foundGuest, review);
                    cout << "Feedback sent successfully." << endl;
                } else {
                    cout << "Guest not found. Please add the guest first." << endl;
                }
                break;
            }
            case 2: {
                Feedback::viewFeedbacks();
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 3);
}

// Option 8: Generate Hotel Report
void Menu::generateHotelReport() {
    Hotel& hotel = Hotel::getInstance();
    hotel.generateReport();
}

// Option 9: Access Control Operations
void Menu::accessControlOperations() {
    AccessControl ac;
    int subChoice = 0;
    do {
        cout << "\n----- Access Control Operations -----" << endl;
        cout << "1. Grant Access" << endl;
        cout << "2. Restrict Access" << endl;
        cout << "3. Show Permissions" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                string role, permission;
                cout << "Enter role: ";
                cin >> role;
                cout << "Enter permission: ";
                cin >> permission;
                ac.grantAccess(role, permission);
                break;
            }
            case 2: {
                string role;
                cout << "Enter role to restrict: ";
                cin >> role;
                ac.restrictAccess(role);
                break;
            }
            case 3: {
                ac.showPermissions();
                break;
            }
            case 4:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while(subChoice != 4);
}



