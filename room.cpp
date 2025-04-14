#include "room.h"
Room::Room(int number, const string& status, double price, bool needsMaintenance)
    : roomNumber(number), status(status), price(price), needsMaintenance(needsMaintenance) {}
int Room::getRoomNumber() const {
    return roomNumber;
}
string Room::getStatus() const {
    return status;
}
double Room::getPrice() const {
    return price;
}
bool Room::getMaintenanceStatus() const {
    return needsMaintenance;
}
void Room::setRoomNumber(int number) {
    roomNumber = number;
}
void Room::setStatus(const string& s) {
    status = s;
}
void Room::setPrice(double p) {
    price = p;
}
void Room::setMaintenanceStatus(bool status) {
    needsMaintenance = status;
}
void Room::checkIn() {
    status = "Occupied";
}
void Room::checkOut() {
    status = "Available";
}
void Room::scheduleMaintenance() {
    needsMaintenance = true;
}