#include <iostream>
#include "Payment.h"
#include "PayPalPayment.h"
#include "CreditCardPayment.h"

using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0))); // For generating random transaction IDs

    cout << "Choose Payment Method:\n1. Credit Card\n2. PayPal\n> ";
    int choice;
    cin >> choice;

    Payment* payment = nullptr;

    if (choice == 1) {
        string cardNum, exp, cvv;
        cout << "Enter Card Number: ";
        cin >> cardNum;
        cout << "Enter Expiry Date (MM/YY): ";
        cin >> exp;
        cout << "Enter CVV: ";
        cin >> cvv;

        payment = new CreditCardPayment(120.50, cardNum, exp, cvv); // Demo amount
    } else if (choice == 2) {
        string email;
        cout << "Enter PayPal Email: ";
        cin >> email;

        payment = new PayPalPayment(120.50, email); // Demo amount
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    payment->processPayment();

    // Optional: display transaction details
    cout << "Payment method: " << payment->getMethod() << endl;
    cout << "Amount paid: $" << payment->getAmount() << endl;
    cout << "Transaction ID: " << payment->getTransactionId() << endl;

    delete payment;
    return 0;
}