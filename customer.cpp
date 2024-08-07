#include "customer_manage.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Customer> readCustomersFromCSV(const string& filename) {
    vector<Customer> customers;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "������ �� �� �����ϴ�: " << filename << endl;
        return customers;
    }

    string line;
    while (getline(file, line)) { // getline���� �޾Ƽ� ���Ϳ� ����
        stringstream ss(line);
        string idStr, name, phoneNumber, email;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, email, ',');

        if (!idStr.empty() && !name.empty() && !phoneNumber.empty() && !email.empty()) {
            int id = stoi(idStr);
            customers.emplace_back(id, name, phoneNumber, email);
        }
    }

    file.close();
    return customers;
}
