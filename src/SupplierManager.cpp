#include "../include/SupplierManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

SupplierManager::SupplierManager() {
    loadFromDisk();
}
void SupplierManager::viewSuppliers() {
    std::cout << "\n" << std::left 
              << std::setw(8)  << "ID" 
              << std::setw(20) << "Supplier Name" 
              << std::setw(15) << "Contact" 
              << std::setw(15) << "Category" << std::endl;
    std::cout << std::string(58, '-') << std::endl;

    for (const auto& s : suppliers) {
        std::cout << std::left 
                  << std::setw(8)  << s.getId()
                  << std::setw(20) << s.getName()
                  << std::setw(15) << s.getContact()
                  << std::setw(15) << s.getCategory() << std::endl;
    }
}

void SupplierManager::addSupplier() {
    int id;
    std::string name, contact, cat;
    std::cout << "Enter Supplier ID: "; std::cin >> id;
    std::cout << "Enter Name: "; std::cin.ignore(); getline(std::cin, name);
    std::cout << "Enter Contact: "; getline(std::cin, contact);
    std::cout << "Enter Category: "; getline(std::cin, cat);

    suppliers.push_back(Supplier(id, name, contact, cat));
    saveToDisk();
    std::cout << "Supplier added successfully!\n";
}

#include "../include/SupplierManager.h"
#include <fstream>
#include <sstream>
#include <iostream>


void SupplierManager::loadFromDisk() {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    suppliers.clear(); // Clear custom DynamicArray
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, name, contact, category;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, contact, ',');
        std::getline(ss, category, ',');

        if (!idStr.empty()) {
            suppliers.push_back(Supplier(std::stoi(idStr), name, contact, category));
        }
    }
    file.close();
}

void SupplierManager::saveToDisk() {
    std::ofstream file(filename);
    for (const auto& s : suppliers) {
        file << s.serialize() << "\n";
    }
    file.close();
}

Supplier* SupplierManager::findSupplier(int id) {
    // Linear Search implementation - O(n)
    for (int i = 0; i < suppliers.size(); i++) {
        if (suppliers[i].getId() == id) {
            return &suppliers[i];
        }
    }
    return nullptr;
}