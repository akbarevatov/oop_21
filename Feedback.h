#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>
#include "Guest.h"
#include "Hotel.h"

class Feedback {
public:
    static void viewFeedbacks();

    static void sendFeedback(string guestID);

    static void feedbackOperations();
};

#endif // FEEDBACK_H
