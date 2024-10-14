#include "Sales.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#include "Normal.h"

// Default constructor
Sales::Sales() : Normal(), commission(0) {}

// Parameterised constructor
Sales::Sales(string employeeName, int employeeID, float payRate) : employeeName(employeeName), employeeID(employeeID), payRate(payRate), commission(0) {}

// Function to calculate commission
void Sales::calcCommission()
{
    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random number between 10,000 and 50,000
    int randomValue = 10000 + (std::rand() % (50000 - 10000 + 1));

    // Calculate 5% of the random value
    commission = randomValue * 0.05;

    // Output the result
    cout << "Employee ID: " << employeeID << ", Name: " << employeeName << ", Commission: $" << commission << endl;
}
