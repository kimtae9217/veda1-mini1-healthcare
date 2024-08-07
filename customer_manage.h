#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <vector>
#include <string>
#include "Customer.h"

using namespace std;

vector<Customer> readCustomersFromCSV(const string& filename);

#endif // !CUSTOMER_MANAGER_H
