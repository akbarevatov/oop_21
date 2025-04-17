#include "Feedback.h"
#include "Hotel.h"
#include "Menu.h"
#include <iostream>
#include <fstream>

void Feedback::viewFeedbacks() {
    std::ifstream file("feedbacks.txt");
    if (file.is_open()) {
        std::string line;
        std::cout << "\n========== Guest Feedbacks ==========\n";
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "=====================================\n" << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open feedback file." << std::endl;
    }
}

void Feedback::sendFeedback(string guestID=0) {
    string review;
    if (guestID == "0") {
        cout << "Enter guest ID: ";
        cin >> guestID;
    }
        cin.ignore();  // Clear leftover newline
        cout << "Enter your review: ";
        getline(cin, review);
    Hotel& hotel = Hotel::getInstance();
    Guest* foundGuest = nullptr;

    for (Guest* g : hotel.getGuests()) {  // Changed Guest& to Guest*
        if (g->getID() == guestID) {      // Changed . to ->
            foundGuest = g;
            break;
        }
    }

    if (foundGuest) {
        ofstream file("feedbacks.txt", ios::app);
        if (file.is_open()) {
            file << "Guest Name: " << foundGuest->getName() << "\n";
            file << "Review: " << review << "\n";
            file << "--------------------------\n";
            file.close();
            cout << "Thank you for your feedback!\n";
        } else {
            cerr << "Unable to open feedback file.\n";
        }
    } else {
        cout << "Guest not found. Please register first.\n";
    }
}
void Feedback::feedbackOperations() {
    int subChoice = 0;
    Hotel& hotel = Hotel::getInstance();
    do {
        cout << "\n----- Feedback Operations -----" << endl;
        cout << "1. Send Feedback" << endl;
        cout << "2. View All Feedbacks" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;
        if(cin.fail()){
            Menu::clearInput();
            subChoice = 0;
        }
        switch (subChoice) {
            case 1: {
                Feedback::sendFeedback("0");
            }
            case 2: {
                Feedback::viewFeedbacks();
                break;
            }
            case 3:
                cout << "Returning to main menu..." << endl;
            break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (subChoice != 3);
}