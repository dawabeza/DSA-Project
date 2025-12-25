#include <iostream>
#include "../include/ProductManager.h"
#include "../include/CustomerManager.h"
#include "../include/SupplierManager.h"
#include "../include/StockManager.h"
#include "../include/SalesManager.h"
#include "../include/InputUtils.h"

// --- SUB-MENUS ---

void productSubMenu(ProductManager& pm) {
    int choice;
    do {
        std::cout << "\n--- Product Management ---\n"
                  << "1. Add New Product\n"
                  << "2. View All Products\n"
                  << "3. Delete Product\n"
                  << "4. Update Product\n"
                  << "5. Back to Main Menu\n";

        if (!InputUtils::readIntInRange("Choice: ", choice, 1, 5))
            continue;

        switch (choice) {
            case 1: pm.addProduct(); break;
            case 2: pm.viewAllProducts(); break;
            case 3: pm.deleteProduct(); break;
            case 4: pm.updateProduct(); break;
            case 5: break;
        }
    } while (choice != 5);
}

void customerSubMenu(CustomerManager& cm) {
    int choice;
    do {
        std::cout << "\n--- Customer Management ---\n"
                  << "1. Register New Customer\n"
                  << "2. View All Customers\n"
                  << "3. Back to Main Menu\n";

        if (!InputUtils::readIntInRange("Choice: ", choice, 1, 3))
            continue;

        switch (choice) {
            case 1: cm.registerCustomer(); break;
            case 2: cm.listCustomers(); break;
            case 3: break;
        }
    } while (choice != 3);
}

void supplierSubMenu(SupplierManager& sm) {
    int choice;
    do {
        std::cout << "\n--- Supplier Management ---\n"
                  << "1. Add New Supplier\n"
                  << "2. View All Suppliers\n"
                  << "3. Back to Main Menu\n";

        if (!InputUtils::readIntInRange("Choice: ", choice, 1, 3))
            continue;

        switch (choice) {
            case 1: sm.addSupplier(); break;
            case 2: sm.viewSuppliers(); break;
            case 3: break;
        }
    } while (choice != 3);
}

void stockSubMenu(ProductManager& pm, StockManager& sm) {
    int choice;
    do {
        std::cout << "\n--- Stock Management ---\n"
                  << "1. Restock Item\n"
                  << "2. View Low Stock Alerts\n"
                  << "3. Back to Main Menu\n";

        if (!InputUtils::readIntInRange("Choice: ", choice, 1, 3))
            continue;

        switch (choice) {
            case 1: {
                int id, qty;
                if (!InputUtils::readPositiveInt("Enter Product ID: ", id)) break;
                if (!InputUtils::readPositiveInt("Enter New Shipment Quantity: ", qty)) break;
                sm.updateStock(pm, id, qty);
                break;
            }
            case 2: sm.showLowStockAlerts(pm); break;
            case 3: break;
        }
    } while (choice != 3);
}

// --- MAIN INTERFACE ---

void displayMainMenu() {
    std::cout << "\n========================================\n"
              << "   SUPERMARKET MANAGEMENT SYSTEM (DSA)\n"
              << "========================================\n"
              << "1. Product Management\n"
              << "2. Customer Management\n"
              << "3. Supplier Management\n"
              << "4. START NEW SALE (Checkout)\n"
              << "5. Reports & Stock Alerts\n"
              << "0. Exit & Save All Data\n";
}

int main() {
    ProductManager prodManager;
    CustomerManager custManager;
    SupplierManager suppManager;
    StockManager stockManager;
    SalesManager salesManager;

    int mainChoice;

    do {
        displayMainMenu();
        if (!InputUtils::readIntInRange("Select an option: ", mainChoice, 0, 5))
            continue;

        switch (mainChoice) {
            case 1: productSubMenu(prodManager); break;
            case 2: customerSubMenu(custManager); break;
            case 3: supplierSubMenu(suppManager); break;
            case 4:
                salesManager.processSale(prodManager, custManager);
                prodManager.saveToDisk();
                custManager.saveToDisk();
                break;
            case 5: stockSubMenu(prodManager, stockManager); break;
            case 0:
                std::cout << "Finalizing all records and closing system...\n";
                prodManager.saveToDisk();
                custManager.saveToDisk();
                suppManager.saveToDisk();
                break;
        }
    } while (mainChoice != 0);

    return 0;
}
