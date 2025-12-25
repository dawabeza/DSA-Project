#include "../include/CustomerManager.h"
#include "../include/FileManager.h"
#include "../include/InputUtils.h"

#include <iostream>
#include <iomanip>

CustomerManager::CustomerManager()
{
    customers = FileManager::loadCustomers();
}

void CustomerManager::saveToDisk()
{
    FileManager::saveCustomers(customers);
}

void CustomerManager::registerCustomer()
{
    int id;
    std::string name;
    std::string phone;

    // Read and validate customer ID
    if (!InputUtils::readPositiveInt("Enter Customer ID: ", id)) {
        std::cout << "Invalid Customer ID.\n";
        return;
    }

    // Enforce uniqueness
    for (const auto& c : customers) {
        if (c.getId() == id) {
            std::cout << "Customer ID already exists.\n";
            return;
        }
    }

    // Name and phone are free-form text, getline is correct here
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "Name cannot be empty.\n";
        return;
    }

    std::cout << "Enter Phone: ";
    std::getline(std::cin, phone);

    if (phone.empty()) {
        std::cout << "Phone cannot be empty.\n";
        return;
    }

    customers.push_back(Customer(id, name, phone, 0));
    saveToDisk();

    std::cout << "Customer registered successfully.\n";
}

Customer* CustomerManager::findCustomer(int id)
{
    for (auto& c : customers) {
        if (c.getId() == id)
            return &c;
    }
    return nullptr;
}

void CustomerManager::listCustomers()
{
    std::cout << "\n" << std::left
              << std::setw(8)  << "ID"
              << std::setw(20) << "Name"
              << std::setw(15) << "Phone"
              << std::setw(10) << "Points" << '\n';

    std::cout << std::string(53, '-') << '\n';

    for (const auto& c : customers) {
        std::cout << std::left
                  << std::setw(8)  << c.getId()
                  << std::setw(20) << c.getName()
                  << std::setw(15) << c.getPhone()
                  << std::setw(10) << c.getPoints() << '\n';
    }

    std::cout << std::string(53, '-') << '\n';
}
