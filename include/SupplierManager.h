#ifndef SUPPLIERMANAGER_H
#define SUPPLIERMANAGER_H

#include "../ds/DynamicArray.h"
#include "Supplier.h"

class SupplierManager {
private:
    DynamicArray<Supplier> suppliers;
    const std::string filename = "data/suppliers.txt";

public:
    SupplierManager();
    void addSupplier();
    void viewSuppliers();
    Supplier* findSupplier(int id);
    void loadFromDisk();
    void saveToDisk();
};

#endif