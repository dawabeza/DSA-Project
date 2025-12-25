#include "../include/ReportManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

void ReportManager::recordSale(double amount) {
    std::ofstream file(salesFile, std::ios::app); // Open in Append mode
    
    // Get current date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string date = std::to_string(1900 + ltm->tm_year) + "-" + 
                       std::to_string(1 + ltm->tm_mon) + "-" + 
                       std::to_string(ltm->tm_mday);

    // Append: Amount,Date
    file << amount << "," << date << "\n";
    file.close();
}

void ReportManager::generateFinancialReport() {
    std::ifstream file(salesFile);
    if (!file.is_open()) {
        std::cout << "No sales records found.\n";
        return;
    }

    double grandTotal = 0;
    int transactionCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            double amount = std::stod(line.substr(0, commaPos));
            grandTotal += amount;
            transactionCount++;
        }
    }
    file.close();

    std::cout << "\n========================================";
    std::cout << "\n       FINANCIAL SUMMARY REPORT";
    std::cout << "\n========================================";
    std::cout << "\nTotal Transactions: " << transactionCount;
    std::cout << "\nTotal Revenue:      $" << std::fixed << std::setprecision(2) << grandTotal;
    if (transactionCount > 0) {
        std::cout << "\nAverage Sale:       $" << (grandTotal / transactionCount);
    }
    std::cout << "\n========================================\n";
}