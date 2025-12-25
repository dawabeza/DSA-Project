#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <sstream>
#include "Product.h"
#include "Customer.h"
#include "../ds/dynamicArray.h"

class FileManager {
public:
    static void saveProducts(const DynamicArray<Product>& products);
    static DynamicArray<Product> loadProducts();
    static void saveCustomers(const DynamicArray<Customer>& customers);
    static DynamicArray<Customer> loadCustomers();
};

#endif