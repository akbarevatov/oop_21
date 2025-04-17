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


    std::string getBookingID() const { return bookingID; }
    Guest* getGuest() const { return guest; }
    Room* getRoom() const { return roomNumber; }
    std::string getStartDate() const { return startDate; }
    std::string getEndDate() const { return endDate; }


    void modifyBooking(std::string newStart, std::string newEnd);
    void cancelBooking();
    void displayBookingInfo() const;

    static void bookingOperations();
};

#endif // BOOKING_H

