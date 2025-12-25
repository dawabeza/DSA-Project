#ifndef SALERECORD_H
#define SALERECORD_H

#include <string>

struct SaleRecord {
    int saleId;
    double totalAmount;
    std::string date; // Simple string format "YYYY-MM-DD"
};

#endif