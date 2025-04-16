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
    string login;
    string password = "1234";
    string input;
    std::shared_ptr<Guest> foundGuest = nullptr;  // Declared at function scope

    cout << " ===Welcome to G21 hotel===" << endl;
    do {
        cout << "Please enter your login or submit 0 to exit: ";
        cin >> login;

        if (login == "admin") {
            cout << "Enter password: ";
            cin >> input;
            while (input != password) {
                cout << "Invalid input, please try again: ";
                cin >> input;
                cout << endl;
            };

            cout << "===Administrator menu===\n";
            int choice1;
            do {
                cout << "1. Manage Rooms" << endl;
                cout << "2. Booking Operations" << endl;
                cout << "3. Employee Operations" << endl;
                cout << "4. Guest Operations" << endl;
                cout << "5. Loyalty Card Operations" << endl;
                cout << "6. Payment Processing" << endl;
                cout << "7. Feedback Operations" << endl;
                cout << "8. Generate Hotel Report" << endl;
                cout << "9. Access Control Operations" << endl;
                cout << "10. Back to log in page" << endl;
                cout << "Enter your choice: ";
                cin >> choice1;

                if(cin.fail()) {
                    clearInput();
                    choice1 = 0;
                }

                switch (choice1) {
                    case 1: Room::manageRooms(); break;
                    case 2: Booking::bookingOperations(); break;
                    case 3: employeeOperations(); break;
                    case 4: Guest::guestOperations(); break;
                    case 5: LoyaltyCard::loyaltyOperations(); break;
                    case 6: paymentProcessing(); break;
                    case 7: Feedback::feedbackOperations(); break;
                    case 8: generateHotelReport(); break;
                    case 9: accessControlOperations(); break;
                    case 10: cout << "Logging out..." << endl; break;
                    default: cout << "Invalid selection. Please try again." << endl;
                }
            } while (choice1 != 10);
        }
        else {
            if(login != "0") {
                Hotel& hotel = Hotel::getInstance();
                foundGuest = nullptr;  // Reset before searching

                for (auto guest : hotel.getGuests()) {
                    if (guest->getID() == login) {
                        foundGuest = std::shared_ptr<Guest>(guest, [](Guest*) {});
                        break;
                    }
                }

                if (foundGuest) {
                    int choice2;
                    cout << "===Guest Operations===" << endl;
                    cout << "1. Leave feedback" << endl;
                    cout << "2. My loyalty card" << endl;
                    cout << "3. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    if(cin.fail()) {
                        clearInput();
                        choice2 = 0;
                    }

                    switch (choice2) {
                        case 1:
                            Feedback::sendFeedback(foundGuest->getID());
                        break;
                        case 2:
                            LoyaltyCard::LoyaltyGuest(foundGuest->getID());
                        case 3:
                            cout << "Exiting the system..." << endl;
                        break;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                } else {
                    cout << "Guest not found." << endl;
                }
            } else {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    } while(login != "0");
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
