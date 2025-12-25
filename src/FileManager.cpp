#include "../include/FileManager.h"

void FileManager::saveProducts(const DynamicArray<Product>& products) {
    std::ofstream file("../data/products.txt");
    if (file.is_open()) {
        for (const auto& prod : products) {
            file << prod.serialize() << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

DynamicArray<Product> FileManager::loadProducts()
{
    DynamicArray<Product> products;
    std::ifstream file("../data/products.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, cat, price, qty;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, cat, ',');
        std::getline(ss, price, ',');
        std::getline(ss, qty);

        // Remove BOM if present (this is the real bug)
        if (id.size() >= 3 &&
            (unsigned char)id[0] == 0xEF &&
            (unsigned char)id[1] == 0xBB &&
            (unsigned char)id[2] == 0xBF) {
            id.erase(0, 3);
        }

        if (id.empty())
            continue;

        products.push_back(Product(
            std::stoi(id),
            name,
            cat,
            std::stod(price),
            std::stoi(qty)
        ));
    }

    return products;
}


void FileManager::saveCustomers(const DynamicArray<Customer>& customers) {
    std::ofstream file("../data/customers.txt");
    if (file.is_open()) {
        for (const auto& cust : customers) {
            file << cust.serialize() << "\n";
        }
        file.close();
    }
}

DynamicArray<Customer> FileManager::loadCustomers() {
    DynamicArray<Customer> customers;
    std::ifstream file("../data/customers.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, name, phone, pointsStr;

        if (std::getline(ss, idStr, ',') &&
            std::getline(ss, name, ',') &&
            std::getline(ss, phone, ',') &&
            std::getline(ss, pointsStr, ',')) {
            
            try {
                customers.push_back(Customer(std::stoi(idStr), name, phone, std::stoi(pointsStr)));
            } catch (...) {
                // Ignore malformed lines
            }
        }
    }
    file.close();
    return customers;
}