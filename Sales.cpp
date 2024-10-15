#include "Sales.h"

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#include "Normal.h"

Sales::Sales(int id, std::string name, std::string username,
             std::string password)
    : Normal(id, name, username, password) {
  commission = 0;
}

// Function to calculate commission
void Sales::calcCommission() {
  // Seed the random number generator
  std::srand(std::time(0));

  // Generate a random number between 10,000 and 50,000
  int randomValue = 1000 + (std::rand() % (5000 - 1000 + 1));

  // Calculate 5% of the random value
  commission = randomValue * 0.05;

  // Output the result
  cout << "Employee ID: " << employeeID << ", Name: " << employeeName
       << ", Commission: $" << commission << endl;
}
