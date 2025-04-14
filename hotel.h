#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include <string>
#include "Room.h"
#include "Guest.h"
#include "Booking.h"
#include "Employee.h"
using namespace std;

class Hotel {
private:
    vector<Room> rooms;
    vector<Employee*> employees;
    vector<Booking*> bookings;
    Hotel();

public:
    static Hotel& getInstance();
    void addRoom(const Room& r);
    void addEmployee(Employee* e);
    void createBooking(Guest* g, Room& r);
    void generateReport();
    vector<Room>& getRooms();
};
#endif