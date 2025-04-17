#include "Booking.h"
#include "Guest.h"
#include "Hotel.h"
#include "Menu.h"
#include <iostream>
using namespace std;

Booking::Booking() {
    bookingID = "0000000";
    guest = nullptr;
    roomNumber = nullptr;
    startDate = "Unknown";
    endDate = "Unknown";
}

Booking::Booking(std::string bookingID, Guest* guest, Room* roomNumber, std::string startDate, std::string endDate) {
    this->bookingID = bookingID;
    this->guest = guest;
    this->roomNumber = roomNumber;
    this->startDate = startDate;
    this->endDate = endDate;
}

void Booking::modifyBooking(std::string newStart, std::string newEnd) {
    startDate = newStart;
    endDate = newEnd;
    std::cout << "Booking " << bookingID << " has been modified.\n";
}

void Booking::cancelBooking() {
    std::cout << "Booking " << bookingID << " has been cancelled.\n";
    bookingID = "";
}

void Booking::displayBookingInfo() const {
    std::cout << "Booking ID: " << bookingID << "\n";
    std::cout << "Guest: " << (guest ? guest->getName() : "N/A") << "\n";
    std::cout << "Room Number: " << roomNumber << "\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
    std::cout << "----------------------\n";
}

void Booking::bookingOperations() {
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
            Menu::clearInput();
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