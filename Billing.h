//
// Created by User on 4/3/2025.
//

#ifndef BILLING_H
#define BILLING_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

class Billing {
private:
    double totalAmount;
    vector<string> expenses; // Stores expense descriptions or amounts

public:
    Billing() : totalAmount(0.0) {}

    //  Add expense with just amount (method overloading)
    void addExpense(double amount) {
        totalAmount += amount;
        expenses.push_back("Expense: $" + to_string(amount));
    }

    // Add expense with description and amount (method overloading)
    void addExpense(const string& description, double amount) {
        totalAmount += amount;
        expenses.push_back(description + ": $" + to_string(amount));
    }

    void generateReceipt() {
        cout << "\n=== Hotel Receipt ===" << endl;
        cout << "Itemized Expenses:" << endl;
        for (const auto& expense : expenses) {
            cout << "- " << expense << endl;
        }
        cout << "---------------------" << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Thank you for staying with us!" << endl;
    }

    double getTotalAmount() const { return totalAmount; }
};
#endif //BILLING_H
