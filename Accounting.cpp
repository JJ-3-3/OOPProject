#include "Accounting.h"

// Default constructor
Accounting::Accounting() 
    : Normal() { // Initialise using Normal's constructor with default values
    // Additional initialisation can be done here if needed
}

// Parameterized constructor
Accounting::Accounting(string employeeName, int employeeID, float payRate)
    : employeeName(employeeName), employeeID(employeeID), payRate(payRate) { 
    // Initialize the base class (Normal) with employee details and set pay rate
}

// Method to generate a report based on the specified report type
void Accounting::generateReport(string reportType) {
    cout << "Generating " << reportType << " report for employee " << employeeName 
         << " (ID: " << employeeID << ")." << endl;
    // Additional report generation logic can be added here
}

// Method to calculate all pay for the accounting employee
void Accounting::calculateAllPay() {
    // Example calculation: for simplicity, we might just multiply payRate by a fixed number of hours worked
    float hoursWorked = 40.0; // Assuming a standard 40-hour work week
    float totalPay = payRate * hoursWorked;
    
    cout << "Total pay for employee " << employeeName << " (ID: " << employeeID 
         << ") is: $" << totalPay << endl;
    // Additional logic for different pay calculation methods can be implemented here
}
