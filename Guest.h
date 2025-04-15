#ifndef GUEST_H
#define GUEST_H

#include <string>
#include <vector>

class Booking; // Forward declaration

class Guest {
private:
    std::string name;
    std::string contactInfo;
    std::string id;
    std::vector<Booking*> bookingHistory;
    std::vector<std::string> preferences;

public:
    Guest();
    Guest(std::string name, std::string contactInfo, std::string id);

    void updatePreference(const std::string& pref);
    void viewBookingHistory() const;

    void addBooking(Booking* booking);

    std::string getName() const;
};

#endif // GUEST_H

