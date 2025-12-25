#include "../include/ProductManager.h"
#include "../include/FileManager.h"
#include "../include/InputUtils.h"
#include "../algorithm/Sort.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

ProductManager::ProductManager()
{
    loadFromDisk();
}

void ProductManager::loadFromDisk()
{
    products = FileManager::loadProducts();
}

void ProductManager::saveToDisk()
{
    FileManager::saveProducts(products);
}

void ProductManager::addProduct()
{
    int id, qty;
    std::string name, cat;
    double price;

    std::cout << "\n--- Add New Product ---\n";

    if (!InputUtils::readPositiveInt("Enter ID: ", id)) {
        std::cout << "Invalid Product ID.\n";
        return;
    }

    if (isIdDuplicate(id)) {
        std::cout << "Error: Product ID " << id << " already exists! Action cancelled.\n";
        return;
    }

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Product name cannot be empty.\n";
        return;
    }

    std::cout << "Enter Category: ";
    std::getline(std::cin, cat);
    if (cat.empty()) {
        std::cout << "Category cannot be empty.\n";
        return;
    }

    if (!InputUtils::readNonNegativeDouble("Enter Price: ", price)) {
        std::cout << "Invalid price.\n";
        return;
    }

    if (!InputUtils::readNonNegativeInt("Enter Quantity: ", qty)) {
        std::cout << "Invalid quantity.\n";
        return;
    }

    products.push_back(Product(id, name, cat, price, qty));
    saveToDisk();

    std::cout << "Product added successfully!\n";
}

void ProductManager::viewAllProducts()
{
    std::cout << "\n" << std::left
              << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(15) << "Category"
              << std::setw(10) << "Price"
              << std::setw(8)  << "Qty" << '\n';

    std::cout << std::string(63, '-') << '\n';

    for (const auto& p : products) {
        std::cout << std::left
                  << std::setw(10) << p.getId()
                  << std::setw(20) << p.getName()
                  << std::setw(15) << p.getCategory()
                  << "$" << std::setw(9) << p.getPrice()
                  << std::setw(8)  << p.getQuantity() << '\n';
    }

    std::cout << std::string(63, '-') << '\n';
}

void ProductManager::deleteProduct()
{
    int id;

    if (!InputUtils::readPositiveInt("Enter Product ID to delete: ", id)) {
        std::cout << "Invalid Product ID.\n";
        return;
    }

    int indexToDelete = -1;
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getId() == id) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        std::cout << "Product not found.\n";
        return;
    }

    products.removeAt(indexToDelete);
    saveToDisk();

    std::cout << "Product deleted successfully.\n";
}

void ProductManager::searchProduct()
{
    int id;

    if (!InputUtils::readPositiveInt("Enter Product ID to search: ", id)) {
        std::cout << "Invalid Product ID.\n";
        return;
    }

    auto it = std::find_if(
        products.begin(),
        products.end(),
        [id](const Product& p) {
            return p.getId() == id;
        }
    );

    if (it != products.end()) {
        std::cout << "Product Found:\n";
        it->display();
    } else {
        std::cout << "Product not found.\n";
    }
}

void ProductManager::updateProduct()
{
    int id;

    if (!InputUtils::readPositiveInt("Enter Product ID to update: ", id)) {
        std::cout << "Invalid Product ID.\n";
        return;
    }

    auto it = std::find_if(
        products.begin(),
        products.end(),
        [id](const Product& p) {
            return p.getId() == id;
        }
    );

    if (it == products.end()) {
        std::cout << "Product not found.\n";
        return;
    }

    double newPrice;
    if (!InputUtils::readNonNegativeDouble("Enter New Price: ", newPrice)) {
        std::cout << "Invalid price.\n";
        return;
    }

    int newQty;
    if (!InputUtils::readNonNegativeInt("Enter New Quantity: ", newQty)) {
        std::cout << "Invalid quantity.\n";
        return;
    }

    it->setPrice(newPrice);
    it->setQuantity(newQty);

    saveToDisk();
    std::cout << "Product updated successfully.\n";
}

bool ProductManager::isIdDuplicate(int id)
{
    for (const auto& p : products) {
        if (p.getId() == id)
            return true;
    }
    return false;
}

Product* ProductManager::findProduct(int id)
{
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getId() == id)
            return &products[i];
    }
    return nullptr;
}

bool compareQuantity(const Product& a, const Product& b)
{
    return a.getQuantity() <= b.getQuantity();
}

void ProductManager::viewLowStockReport()
{
    Sort<Product>::mergeSort(products, 0, products.size() - 1, compareQuantity);

    std::cout << "\n--- SORTED STOCK REPORT (Low to High) ---\n";
    viewAllProducts();

    loadFromDisk(); // restore original order
}
