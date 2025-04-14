#include <iostream>
#include "Billing.h"
using namespace std;


int main() {
    Billing customerBill;

    // Add expenses
    customerBill.addExpense(120.50); // Just amount
    customerBill.addExpense("Room Service", 45.00); // With description
    customerBill.addExpense("Laundry", 25.00);
    customerBill.addExpense(80.75); // Another amount without description
    customerBill.addExpense("Mini Bar", 15.25);

    // Generate and display receipt
    customerBill.generateReceipt();

    return 0;
}