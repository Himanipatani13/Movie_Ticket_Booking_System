#ifndef CASHPAYMENT_CPP
#define CASHPAYMENT_CPP
#include <iostream>
#include "Payment.cpp"
using namespace std;

class CashPayment : public Payment {
public:
    CashPayment(double amt) : Payment(amt) {}
    bool pay(double amountToCharge) override {
        if (amountToCharge <= 0) return false;
        cout << "  [CASH] Confirm Rs." << amountToCharge
             << " -> 1=Success 0=Simulate failure: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "  [CASH] Rs." << amountToCharge << " paid successfully\n";
            return true;
        }
        cout << "  [CASH] Payment FAILED\n";
        return false;
    }
    string methodName() const override { return "CASH"; }
};
#endif
