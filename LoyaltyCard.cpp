//
// Created by azizb on 3/27/2025.
//

#include "LoyaltyCard.h"
#include <iostream>
using namespace std;

// Constructor definition
LoyaltyCard::LoyaltyCard(float points, const Guest& guest)
    : rewardPoints(points), guest(guest) {}

// Method to add points based on purchase
void LoyaltyCard::addPoints(float purchase) {
    rewardPoints += static_cast<float>(purchase * 0.02);  // Add points as 2% of purchase
}

// Method to redeem points
bool LoyaltyCard::redeemPoints(float amount) {
    if (rewardPoints < amount) {
        cout << "Not enough points in the balance!" << endl;
        return false;
    }
    rewardPoints -= amount;  // Subtract the redeemed points
    cout << "You have redeemed " << amount << " points!" << endl;
    return true;
}

// Method to check the current reward points (const method)
float LoyaltyCard::checkPoints() const {
    return rewardPoints;
}
