#include "Hotel.h"
#include <ctime>
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
    string bookingID = "BOOK" + to_string(time(0));
    string startDate = "2025-04-14";
    string endDate = "2025-04-15";
    cout << "Creating booking for guest and room: " << r.getRoomNumber() << endl;
    Booking* newBooking = new Booking(bookingID, g, &r, startDate, endDate);
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
vector<Booking*>& Hotel::getBookings() {
    return bookings;
}
vector<Guest*>& Hotel::getGuests() {
    return guests;
}
vector<Feedback*>& Hotel::getFeedbacks() {
    return feedbacks;
}
void Hotel::addFeedback(Feedback* feedback) {
    feedbacks.push_back(feedback);
}
void Hotel::createBooking(Guest* g, Room& r, string startDate, string endDate) {
    string bookingID = to_string(bookings.size() + 1);
    Booking* booking = new Booking(bookingID, g, &r, startDate, endDate);
    bookings.push_back(booking);
}
