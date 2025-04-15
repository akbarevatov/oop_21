#include "Guest.h"
#include "Booking.h"
#include <iostream>

Guest::Guest() {
    name = "Unknown";
    contactInfo = "Unknown";
    id = "000000";
}

Guest::Guest(std::string name, std::string contactInfo, std::string id) {
    this->name = name;
    this->contactInfo = contactInfo;
    this->id = id;
}

void Guest::updatePreference(const std::string& pref) {
    preferences.push_back(pref);
    std::cout << "Added preference: " << pref << std::endl;
}

void Guest::viewBookingHistory() const {
    if (bookingHistory.empty()) {
        std::cout << "No bookings found for " << name << ".\n";
        return;
    }
    std::cout << "Booking history for " << name << ":\n";
    for (const auto& booking : bookingHistory) {
        booking->displayBookingInfo();
    }
}

void Guest::addBooking(Booking* booking) {
    bookingHistory.push_back(booking);
}

std::string Guest::getName() const {
    return name;
}
