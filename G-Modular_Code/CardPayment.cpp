#ifndef CARDPAYMENT_CPP
#define CARDPAYMENT_CPP
#include <iostream>
#include "Payment.cpp"
using namespace std;

class CardPayment : public Payment {
public:
    CardPayment(double amt) : Payment(amt) {}
    bool pay(double amountToCharge) override {
        if (amountToCharge <= 0) return false;
        cout << "  [CARD] Confirm Rs." << amountToCharge
             << " -> 1=Success 0=Simulate failure: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "  [CARD] Rs." << amountToCharge << " paid successfully\n";
            return true;
        }
        cout << "  [CARD] Payment FAILED\n";
        return false;
    }
    string methodName() const override { return "CARD"; }
};
#endif
