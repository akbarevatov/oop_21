#ifndef BOOKING_H
#define BOOKING_H

#include <string>

class Guest; // Forward declaration
class Room;
class Booking {
private:
    std::string bookingID;
    Guest* guest;
    Room* roomNumber;
    std::string startDate;
    std::string endDate;

public:
    Booking();
    Booking(std::string bookingID, Guest* guest, Room* roomNumber, std::string startDate, std::string endDate);

    void modifyBooking(std::string newStart, std::string newEnd);
    void cancelBooking();
    void displayBookingInfo() const;
};

#endif // BOOKING_H
