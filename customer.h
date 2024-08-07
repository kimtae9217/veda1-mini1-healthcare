#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
public:
    int id;
    string name;
    string phoneNumber;
    string email;

    Customer(int id, string name, string phoneNumber, string email)
        : id(id), name(name), phoneNumber(phoneNumber), email(email) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Phone: " << phoneNumber << ", Email: " << email << endl;
    }
};

#endif // !CUSTOMER_H
