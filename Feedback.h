#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>
#include <vector>
#include "Guest.h"

class Feedback {
private:
    Guest guest;                 // Guest who gave the feedback
    std::string review;          // Review text
    static std::vector<Feedback> feedbacks; // Static vector of feedbacks

public:
    Feedback(Guest guest, const std::string& review);

    void sendFeedback(const Guest& guest, const std::string& review);
    void printFeedback(const Feedback& feedback) const;
    static void viewFeedbacks(); // Static function to view all feedbacks
};

#endif //FEEDBACK_H
