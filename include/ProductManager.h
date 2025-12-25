#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "Product.h"
#include "../ds/dynamicArray.h"

class ProductManager {
private:
    DynamicArray<Product> products;
    public:
    void loadFromDisk();
    void saveToDisk();
    ProductManager();
    void addProduct();
    void viewAllProducts();
    void deleteProduct();
    void searchProduct();
    void updateProduct();
    void viewLowStockReport();
    bool isIdDuplicate(int id);
    Product* findProduct(int id);
    DynamicArray<Product> getProducts() const { return products; }
};

#endif