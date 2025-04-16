#ifndef LOYALTYCARD_H
#define LOYALTYCARD_H

#include <string>
#include <memory>
#include "Guest.h"

class LoyaltyCard {
private:
    float points;
    std::shared_ptr<Guest> guest; // Changed to shared_ptr for safer memory management

public:
    // Removed default constructor - cards must be created with a guest
    LoyaltyCard(float points, std::shared_ptr<Guest> guest);

    // Getters
    float getPoints() const;
    const Guest& getGuest() const;
    std::string getGuestID() const;

    // Points management
    void addPoints(float value);
    bool redeemPoints(float value); // Returns success status

    // Validation
    bool canRedeem(float value) const;

    // Static creation method for easier use in Menu
    static std::shared_ptr<LoyaltyCard> createCard(std::shared_ptr<Guest> guest, float initialPoints = 0.0f);

    static void LoyaltyGuest(std::string GuestID);

    static void loyaltyOperations();
};

#endif // LOYALTYCARD_H