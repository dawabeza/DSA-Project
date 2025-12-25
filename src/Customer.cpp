#include "../include/Customer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
Customer::Customer(int id, std::string n, std::string p, int points) {
    customerId = id;
    name = n;
    phone = p;
    loyaltyPoints = points;
}
