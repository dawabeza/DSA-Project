#ifndef STOCKMANAGER_H
#define STOCKMANAGER_H

#include "ProductManager.h"

class StockManager {
public:
    // Update stock when new items arrive
    void updateStock(ProductManager& pm, int productId, int additionalQty);
    
    // Low stock alert (using a simple filter)
    void showLowStockAlerts(ProductManager& pm, int threshold = 10);
};

#endif