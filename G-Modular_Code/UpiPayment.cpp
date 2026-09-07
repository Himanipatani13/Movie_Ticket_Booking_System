#ifndef UPIPAYMENT_CPP
#define UPIPAYMENT_CPP
#include <iostream>
#include "Payment.cpp"
using namespace std;

class UpiPayment : public Payment {
public:
    UpiPayment(double amt) : Payment(amt) {}
    bool pay(double amountToCharge) override {
        if (amountToCharge <= 0) return false;
        cout << "  [UPI] Confirm Rs." << amountToCharge
             << " -> 1=Success 0=Simulate failure: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "  [UPI] Rs." << amountToCharge << " paid successfully\n";
            return true;
        }
        cout << "  [UPI] Payment FAILED\n";
        return false;
    }
    string methodName() const override { return "UPI"; }
};
#endif
