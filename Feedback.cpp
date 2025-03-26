#include "Feedback.h"
#include <iostream>

std::vector<Feedback> Feedback::feedbacks; // Define the static member

Feedback::Feedback(Guest guest, const std::string& review)
    : guest(guest), review(review) {}

void Feedback::sendFeedback(const Guest& guest, const std::string& review) {
    feedbacks.push_back(Feedback(guest, review)); // Add feedback to the static vector
}

void Feedback::printFeedback(const Feedback& feedback) const {
    std::cout << "Guest Name: " << feedback.guest.getName() << std::endl;
    std::cout << "Review: " << feedback.review << std::endl;
}

void Feedback::viewFeedbacks() {
    for (const auto& feedback : feedbacks) { // Iterate over all feedbacks
        feedback.printFeedback(feedback);    // Call printFeedback
        std::cout << std::endl;
    }
}
