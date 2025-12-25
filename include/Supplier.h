#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
private:
    int supplierId;
    std::string name;
    std::string contact;
    std::string category; // e.g., Dairy, Electronics

public:
    Supplier(int id = 0, std::string n = "", std::string c = "", std::string cat = "")
        : supplierId(id), name(n), contact(c), category(cat) {}

    // Getters
    int getId() const { return supplierId; }
    std::string getName() const { return name; }
    std::string getContact() const { return contact; }
    std::string getCategory() const { return category; }

    // For file saving
    std::string serialize() const {
        return std::to_string(supplierId) + "," + name + "," + contact + "," + category;
    }
};

#endif