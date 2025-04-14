#include "hotel.h"
#include <iostream>
using namespace std;
Hotel::Hotel() {}
Hotel& Hotel::getInstance() {
    static Hotel instance;
    return instance;
}
void Hotel::addRoom(const Room& r) {
    rooms.push_back(r);
}
void Hotel::addEmployee(Employee* e) {
    employees.push_back(e);
}
void Hotel::createBooking(Guest* g, Room& r) {
    cout << "Creating booking for guest and room: " << r.getRoomNumber() << endl;
    Booking* newBooking = new Booking(g, &r);
    bookings.push_back(newBooking);
}
void Hotel::generateReport() {
    cout << "----- Hotel Report -----" << endl;
    cout << "Total Rooms: " << rooms.size() << endl;
    cout << "Total Employees: " << employees.size() << endl;
    cout << "Total Bookings: " << bookings.size() << endl;
}
vector<Room>& Hotel::getRooms() {
    return rooms;
}