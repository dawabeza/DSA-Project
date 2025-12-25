#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;

public:
    // Constructor
    Product(int p_id = 0, std::string p_name = "", std::string p_cat = "", double p_price = 0.0, int p_qty = 0);

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    std::string getCategory() const { return category; }


    // Setters
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }

    // Helper to display product details
    void display() const {
        std::cout << id << "\t" << name << "\t" << category << "\t$" << price << "\t" << quantity << std::endl;
    }

    // Method to format data for file storage (CSV style)
    std::string serialize() const {
        return std::to_string(id) + "," + name + "," + category + "," + std::to_string(price) + "," + std::to_string(quantity);
    }
};

#endif