#include "Booking.h"
#include "Guest.h"
#include <iostream>

Booking::Booking() {
    bookingID = "0000000";
    guest = nullptr;
    roomNumber = nullptr;
    startDate = "Unknown";
    endDate = "Unknown";
}

Booking::Booking(std::string bookingID, Guest* guest, Room* roomNumber, std::string startDate, std::string endDate) {
    this->bookingID = bookingID;
    this->guest = guest;
    this->roomNumber = roomNumber;
    this->startDate = startDate;
    this->endDate = endDate;
}


void Booking::modifyBooking(std::string newStart, std::string newEnd) {
    startDate = newStart;
    endDate = newEnd;
    std::cout << "Booking " << bookingID << " has been modified.\n";
}

void Booking::cancelBooking() {
    std::cout << "Booking " << bookingID << " has been cancelled.\n";
    bookingID = "";
}

void Booking::displayBookingInfo() const {
    std::cout << "Booking ID: " << bookingID << "\n";
    std::cout << "Guest: " << (guest ? guest->getName() : "N/A") << "\n";
    std::cout << "Room Number: " << roomNumber << "\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
    std::cout << "----------------------\n";
}
