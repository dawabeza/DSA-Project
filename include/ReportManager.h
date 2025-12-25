#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include <string>

class ReportManager {
private:
    const std::string salesFile = "../data/sales.txt";

public:
    void generateFinancialReport();
    void recordSale(double amount); // Called by SalesManager after a successful checkout
};

#endif