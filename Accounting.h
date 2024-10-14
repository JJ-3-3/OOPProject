#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <iostream>
#include "Normal.h"

using namespace std;

// The Accounting class inherits from the Normal class, representing an accounting employee
class Accounting : public Normal
{
protected:
    string employeeName; // Name of the accounting employee
    int employeeID;      // Unique identifier for the accounting employee
    float payRate;       // Pay rate for the accounting employee

public:
    // Default constructor
    Accounting();

    // Parameterized constructor to initialize Accounting object with specific details
    Accounting(string employeeName, int employeeID, float payRate);

    // Method to generate a report based on the specified report type
    void generateReport(string reportType);

    // Method to calculate all pay for the accounting employee
    void calculateAllPay();
};

#endif // ACCOUNTING_H
