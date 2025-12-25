#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
private:
    int customerId;
    std::string name;
    std::string phone;
    int loyaltyPoints;

public:
    Customer(int id = 0, std::string n = "", std::string p = "", int points = 0);

    // Getters
    int getId() const { return customerId; }
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    int getPoints() const { return loyaltyPoints; }


    
    // Logic for loyalty points
    void addPoints(int p) { loyaltyPoints += p; }

    void display() const {
        std::cout << customerId << "\t" << name << "\t" << phone << "\tPoints: " << loyaltyPoints << std::endl;
    }

    // CSV Serialization
    std::string serialize() const {
        return std::to_string(customerId) + "," + name + "," + phone + "," + std::to_string(loyaltyPoints);
    }
};

#endif