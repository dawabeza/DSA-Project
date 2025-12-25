#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include "../ds/DynamicArray.h"
#include "../ds/LinkedList.h"
#include "ProductManager.h"
#include "CustomerManager.h"

#include <string>

struct CartItem {
    int productId;
    std::string name;
    int quantity;
    double price;
};

class SalesManager {
private:
    // ---------- Business helpers ONLY ----------

    Product* findProductById(ProductManager& mgr, int id);

    bool handleCustomer(CustomerManager& custMgr, Customer*& outCustomer);

    bool addItemToCart(
        ProductManager& prodMgr,
        LinkedList<CartItem>& cart,
        double& grandTotal
    );

    void printReceipt(
        const LinkedList<CartItem>& cart,
        double grandTotal
    );

public:
    void processSale(ProductManager& prodMgr, CustomerManager& custMgr);
};

#endif
