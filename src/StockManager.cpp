#include "../include/StockManager.h"
#include <iostream>

void StockManager::updateStock(ProductManager& pm, int productId, int additionalQty) {
    Product* p = pm.findProduct(productId);
    if (p) {
        int newQty = p->getQuantity() + additionalQty;
        p->setQuantity(newQty);
        std::cout << "Stock updated! " << p->getName() << " now has " << newQty << " units.\n";
        pm.saveToDisk(); // Ensure the change is permanent
    } else {
        std::cout << "Product ID not found.\n";
    }
}

void StockManager::showLowStockAlerts(ProductManager& pm, int threshold) {
    std::cout << "\n--- LOW STOCK ALERTS (Below " << threshold << " units) ---\n";
    bool found = false;
    
    // We use the iterator we built for the DynamicArray
    for (auto& product : pm.getProducts()) {
        if (product.getQuantity() < threshold) {
            std::cout << "[!] ID: " << product.getId() 
                      << " | Name: " << product.getName() 
                      << " | Current Qty: " << product.getQuantity() << "\n";
            found = true;
        }
    }
    
    if (!found) std::cout << "All stock levels are healthy.\n";
}