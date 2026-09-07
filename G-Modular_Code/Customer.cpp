#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phone;

public:
    Customer(string n, string p) : name(n), phone(p) {}

    Customer(string n) : name(n), phone("N/A") {}

    string getName() const { return name; }
    string getPhone() const { return phone; }
};
#endif
