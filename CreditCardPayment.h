//
// Created by User on 4/3/2025.
//

#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include "Payment.h"
using namespace std;

class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string expiryDate;
    string cvv;

public:
    CreditCardPayment(double amt, string cardNum, string exp, string cv)
        : Payment(amt, "Credit Card"), cardNumber(cardNum), expiryDate(exp), cvv(cv) {}

    void processPayment() override {
        cout << "Processing credit card payment of $" << amount
                  << " with card ending in " << cardNumber.substr(cardNumber.length() - 4)
                  << endl;
        // In a real system, this would connect to a payment gateway
        cout << "Payment processed successfully. Transaction ID: " << transactionId << endl;
    }
};
#endif //CREDITCARDPAYMENT_H
