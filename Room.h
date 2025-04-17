#ifndef ROOM_H
#define ROOM_H
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;
    string status;
    double price;
    bool needsMaintenance;
public:
    Room(int number, const string& status, double price, bool needsMaintenance = false);
    int getRoomNumber() const;
    string getStatus() const;
    double getPrice() const;
    bool getMaintenanceStatus() const;
    void setRoomNumber(int number);
    void setStatus(const string& status);
    void setPrice(double price);
    void setMaintenanceStatus(bool status);
    void checkIn();
    void checkOut();
    void scheduleMaintenance();
    bool isAvailable() const;  // Add this method
    static void manageRooms();
};

#endif


