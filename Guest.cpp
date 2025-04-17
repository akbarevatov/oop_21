#include "Guest.h"
#include "Booking.h"
#include <iostream>
#include "Hotel.h"
#include "Menu.h"
using namespace std;
Guest::Guest() {
    name = "Unknown";
    contactInfo = "Unknown";
    id = "000000";
}

Guest::Guest(std::string name, std::string contactInfo, std::string id) {
    this->name = name;
    this->contactInfo = contactInfo;
    this->id = id;
}

void Guest::updatePreference(const std::string& pref) {
    preferences.push_back(pref);
    std::cout << "Added preference: " << pref << std::endl;
}

void Guest::viewBookingHistory() const {
    if (bookingHistory.empty()) {
        std::cout << "No bookings found for " << name << ".\n";
        return;
    }
    std::cout << "Booking history for " << name << ":\n";
    for (const auto& booking : bookingHistory) {
        booking->displayBookingInfo();
    }
}

void Guest::addBooking(Booking* booking) {
    bookingHistory.push_back(booking);
}

std::string Guest::getName() const {
    return name;
}

std::string Guest::getID() const {
    return id;
}

void Guest::guestOperations() {
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
            Menu::clearInput();
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
                cout << "Enter guest ID to view booking history: ";
                cin >> name;
                vector<Guest*>& guests = hotel.getGuests();
                bool found = false;
                for (Guest* g : guests) {
                    if (g->getID() == name) {
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
