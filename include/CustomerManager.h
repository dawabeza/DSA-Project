#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "Customer.h"
#include "../ds/dynamicArray.h"

class CustomerManager {
private:
    DynamicArray<Customer> customers;
    public:
    void saveToDisk();
    CustomerManager();
    void registerCustomer();
    Customer* findCustomer(int id);
    void listCustomers();
};

#endif