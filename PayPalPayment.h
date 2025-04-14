//
// Created by User on 4/3/2025.
//

#ifndef PAYPALPAYMENT_H
#define PAYPALPAYMENT_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include "Payment.h"
using namespace std;

class PayPalPayment : public Payment {
private:
    string email;

public:
    PayPalPayment(double amt, string em)
        : Payment(amt, "PayPal"), email(em) {}

    void processPayment() override {
        cout << "Processing PayPal payment of $" << amount
                  << " from account " << email << endl;
        // In a real system, this would connect to PayPal API
        cout << "Payment processed successfully. Transaction ID: " << transactionId << endl;
    }
};
#endif //PAYPALPAYMENT_H
