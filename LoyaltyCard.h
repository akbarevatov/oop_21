#ifndef LOYALTYCARD_H
#define LOYALTYCARD_H

#include "Guest.h"

class LoyaltyCard {
private:
    float rewardPoints;
    Guest guest;

public:
    LoyaltyCard(float rewardPoints, const Guest& guest);

    void addPoints(float purchase);
    bool redeemPoints(float amount);
    float checkPoints() const; // Make sure this declaration includes `const`
};

#endif // LOYALTYCARD_H
