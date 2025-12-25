#include "../include/SalesManager.h"
#include "../include/ReportManager.h"
#include "../include/InputUtils.h"

#include <iostream>
#include <iomanip>

// ---------- Private Helpers ----------

Product* SalesManager::findProductById(ProductManager& mgr, int id)
{
    for (auto& p : mgr.getProducts()) {
        if (p.getId() == id)
            return &p;
    }
    return nullptr;
}

bool SalesManager::handleCustomer(CustomerManager& custMgr, Customer*& outCustomer)
{
    int custId;
    if (!InputUtils::readPositiveInt("Enter Customer ID: ", custId)) {
        std::cout << "Invalid Customer ID.\n";
        return false;
    }

    outCustomer = custMgr.findCustomer(custId);
    if (!outCustomer) {
        if (!InputUtils::readYesNo("Customer not found! Continue as Guest? (y/n): ")) {
            return false;
        }
    }
    return true;
}

bool SalesManager::addItemToCart(
    ProductManager& prodMgr,
    LinkedList<CartItem>& cart,
    double& grandTotal
)
{
    int productId;
    if (!InputUtils::readPositiveInt("Enter Product ID: ", productId)) {
        std::cout << "Invalid Product ID.\n";
        return false;
    }

    Product* prod = findProductById(prodMgr, productId);
    if (!prod || prod->getQuantity() == 0) {
        std::cout << "Product not found or out of stock.\n";
        return false;
    }

    std::cout << "Product: " << prod->getName()
              << " | Price: $" << prod->getPrice() << '\n';

    int qty;
    if (!InputUtils::readPositiveInt(
            "Enter Quantity (Available: " + std::to_string(prod->getQuantity()) + "): ",
            qty)) {
        std::cout << "Invalid quantity.\n";
        return false;
    }

    if (qty > prod->getQuantity()) {
        std::cout << "Insufficient stock.\n";
        return false;
    }

    cart.insert({productId, prod->getName(), qty, prod->getPrice()});
    grandTotal += prod->getPrice() * qty;

    return true;
}

void SalesManager::printReceipt(
    const LinkedList<CartItem>& cart,
    double grandTotal
)
{
    std::cout << "\n--- FINAL RECEIPT ---\n";
    std::cout << std::left
              << std::setw(20) << "Item"
              << std::setw(10) << "Qty"
              << "Subtotal\n";

    for (const auto& item : cart) {
        std::cout << std::left
                  << std::setw(20) << item.name
                  << std::setw(10) << item.quantity
                  << "$" << (item.quantity * item.price) << '\n';
    }

    std::cout << "-----------------------\n";
    std::cout << "TOTAL AMOUNT: $" << grandTotal << '\n';
}

// ---------- Public API ----------

void SalesManager::processSale(ProductManager& prodMgr, CustomerManager& custMgr)
{
    Customer* customer = nullptr;
    if (!handleCustomer(custMgr, customer)) {
        return;
    }

    LinkedList<CartItem> cart;
    double grandTotal = 0.0;

    do {
        addItemToCart(prodMgr, cart, grandTotal);
    } while (InputUtils::readYesNo("Add more items? (y/n): "));

    // Deduct stock ONLY after sale confirmation
    for (const auto& item : cart) {
        Product* p = findProductById(prodMgr, item.productId);
        if (p) {
            p->setQuantity(p->getQuantity() - item.quantity);
        }
    }

    printReceipt(cart, grandTotal);

    if (customer) {
        customer->addPoints(static_cast<int>(grandTotal) / 10);
        std::cout << "Loyalty Points Updated!\n";
    }

    ReportManager rm;
    rm.recordSale(grandTotal);

    prodMgr.saveToDisk();
}
