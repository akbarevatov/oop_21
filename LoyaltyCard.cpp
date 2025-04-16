#include "LoyaltyCard.h"
#include "Hotel.h"
#include "Menu.h"
#include <stdexcept>
#include <iostream>
using namespace std;

LoyaltyCard::LoyaltyCard(float pts, std::shared_ptr<Guest> g)
    : points(pts > 0 ? pts : 0), guest(std::move(g)) {
    if (!guest) {
        throw std::invalid_argument("Guest cannot be null when creating loyalty card");
    }
    std::cout << "Created loyalty card for guest: " << guest->getName() << "\n";
}

float LoyaltyCard::getPoints() const {
    return points;
}

const Guest& LoyaltyCard::getGuest() const {
    return *guest;
}

std::string LoyaltyCard::getGuestID() const {
    return guest->getID();
}

void LoyaltyCard::addPoints(float value) {
    if (value <= 0) {
        throw std::invalid_argument("Cannot add negative or zero points");
    }
    points += value;
    std::cout << "Added " << value << " points to " << guest->getName() << "'s card. Total: " << points << "\n";
}

bool LoyaltyCard::redeemPoints(float value) {
    if (!canRedeem(value)) {
        std::cerr << "Failed to redeem points: Not enough points or invalid amount\n";
        return false;
    }
    points -= value;
    std::cout << "Redeemed " << value << " points for " << guest->getName() << ". Remaining: " << points << "\n";
    return true;
}

bool LoyaltyCard::canRedeem(float value) const {
    return value > 0 && points >= value;
}

// Static factory method
std::shared_ptr<LoyaltyCard> LoyaltyCard::createCard(std::shared_ptr<Guest> guest, float initialPoints) {
    if (!guest) {
        throw std::invalid_argument("Cannot create card for null guest");
    }
    return std::make_shared<LoyaltyCard>(initialPoints, guest);
}

void LoyaltyCard::LoyaltyGuest(string GuestID) {
    int subChoice1 = 0;
    Hotel& hotel = Hotel::getInstance();
    static std::shared_ptr<LoyaltyCard> currentCard = nullptr;

    do {
        cout << "\n----- Loyalty Card Operations -----" << endl;
        cout << "1. Redeem Points" << endl;
        cout << "2. Check Points Balance" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice1;

        if(cin.fail()) {
            subChoice1 = 0;
        }

        try {
            switch (subChoice1) {
                case 1: {
                    if (currentCard) {
                        float points;
                        cout << "Enter points to redeem: ";
                        cin >> points;
                        if (!currentCard->redeemPoints(points)) {
                            cout << "Redemption failed. Not enough points." << endl;
                        }
                    } else {
                        cout << "No active loyalty card. Create one first." << endl;
                    }
                    break;
                }
                case 2: {
                    if (currentCard) {
                        cout << "Current points: " << currentCard->getPoints() << endl;
                        cout << "Card holder: " << currentCard->getGuest().getName() << endl;
                    } else {
                        cout << "No active loyalty card." << endl;
                    }
                    break;
                }
                case 3:
                    cout << "Returning to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid option." << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;

        }
    } while (subChoice1 != 5);
}
void LoyaltyCard::loyaltyOperations() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    static std::shared_ptr<LoyaltyCard> currentCard = nullptr;

    do {
        cout << "\n----- Loyalty Card Operations -----" << endl;
        cout << "1. Create Loyalty Card for Guest" << endl;
        cout << "2. Add Points" << endl;
        cout << "3. Redeem Points" << endl;
        cout << "4. Check Points Balance" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;

        if(cin.fail()) {
            Menu::clearInput();
            subChoice = 0;
        }

        try {
            switch (subChoice) {
                case 1: {
                    string guestID;
                    cout << "Enter guest ID to create a loyalty card: ";
                    cin >> guestID;

                    // Find guest and convert to shared_ptr
                    std::shared_ptr<Guest> foundGuest = nullptr;
                    for (auto guest : hotel.getGuests()) {  // guest is Guest*
                        if (guest->getID() == guestID) {
                            // Create a new shared_ptr that shares ownership
                            foundGuest = std::shared_ptr<Guest>(guest, [](Guest*) {
                                // Empty deleter since Hotel owns the Guest
                            });
                            break;
                        }
                    }

                    if (foundGuest) {
                        currentCard = std::make_shared<LoyaltyCard>(0.0f, foundGuest);
                    } else {
                        cout << "Guest not found." << endl;
                    }
                    break;
                }
                case 2: {
                    if (currentCard) {
                        float points;
                        cout << "Enter points to add: ";
                        cin >> points;
                        currentCard->addPoints(points);
                    } else {
                        cout << "No active loyalty card. Create one first." << endl;
                    }
                    break;
                }
                case 3: {
                    if (currentCard) {
                        float points;
                        cout << "Enter points to redeem: ";
                        cin >> points;
                        if (!currentCard->redeemPoints(points)) {
                            cout << "Redemption failed. Not enough points." << endl;
                        }
                    } else {
                        cout << "No active loyalty card. Create one first." << endl;
                    }
                    break;
                }
                case 4: {
                    if (currentCard) {
                        cout << "Current points: " << currentCard->getPoints() << endl;
                        cout << "Card holder: " << currentCard->getGuest().getName() << endl;
                    } else {
                        cout << "No active loyalty card." << endl;
                    }
                    break;
                }
                case 5:
                    cout << "Returning to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid option." << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
            Menu::clearInput();
        }
    } while (subChoice != 5);
}
