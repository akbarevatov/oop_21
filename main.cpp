#include <iostream>
#include "hotel.h"
#include "room.h"
#include "Guest.h"
#include "Employee.h"

int main() {
    Hotel& hotel = Hotel::getInstance();
    hotel.addRoom(Room(101, "Available", 100.0));
    hotel.addRoom(Room(102, "Available", 120.0));
    Guest* guest = new Guest("Mavluda");
    Employee* employee = new Employee("Kamola");
    hotel.addEmployee(employee);
    Room& roomToBook = hotel.getRooms()[0];
    hotel.createBooking(guest, roomToBook);
    roomToBook.checkIn();
    hotel.generateReport();
    delete guest;
    delete employee;
    return 0;
}