#include "Room.h"
using namespace std;
Room::Room(int number, const string& status, double price, bool needsMaintenance)
    : roomNumber(number), status(status), price(price), needsMaintenance(needsMaintenance) {}
int Room::getRoomNumber() const {
    return roomNumber;
}
string Room::getStatus() const {
    return status;
}
double Room::getPrice() const {
    return price;
}
bool Room::getMaintenanceStatus() const {
    return needsMaintenance;
}
void Room::setRoomNumber(int number) {
    roomNumber = number;
}
void Room::setStatus(const string& s) {
    status = s;
}
void Room::setPrice(double p) {
    price = p;
}
void Room::setMaintenanceStatus(bool status) {
    needsMaintenance = status;
}
void Room::checkIn() {
    status = "Occupied";
}
void Room::checkOut() {
    status = "Available";
}
void Room::scheduleMaintenance() {
    needsMaintenance = true;
}
bool Room::isAvailable() const {
    return status == "Available" && !needsMaintenance;  // Check if the room is available
}
void Room::manageRooms() {
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
            Menu::clearInput();
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
