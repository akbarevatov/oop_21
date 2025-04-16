#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include <string>
#include "Room.h"
#include "Guest.h"
#include "Booking.h"
#include "Employee.h"
#include "Feedback.h"
using namespace std;
class Feedback;
class Hotel {
private:
    vector<Room> rooms;
    vector<Employee*> employees;
    vector<Booking*> bookings;
    vector<Guest*> guests;
    vector<Feedback*> feedbacks;
    Hotel();
public:
    static Hotel& getInstance();
    void addRoom(const Room& r);
    void addEmployee(Employee* e);
    void createBooking(Guest* g, Room& r);
    void generateReport();
    vector<Room>& getRooms();
    vector<Booking*>& getBookings();
    vector<Guest*>& getGuests();
    vector<Feedback*>& getFeedbacks();
    void addFeedback(Feedback* feedback);
    void createBooking(Guest* g, Room& r, std::string startDate, std::string endDate);
};
#endif
