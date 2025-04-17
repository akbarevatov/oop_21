#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

class Payment {
protected:
    double amount;
    string method;
    string transactionId;

public:
    Payment(double amt, string meth) : amount(amt), method(meth) {
        // Generate a simple transaction ID (in real system, use a better method)
        transactionId = "TXN" + to_string(time(0)) + to_string(rand() % 1000);
    }

    virtual ~Payment() {}

    // Pure virtual function - makes this class abstract
    virtual void processPayment() = 0;

    double getAmount() const { return amount; }
    string getMethod() const { return method; }
    string getTransactionId() const { return transactionId; }
};
#endif //PAYMENT_H
