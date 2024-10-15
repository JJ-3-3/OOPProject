#include "Manager.h"

// calculates the pay of the entire company for the week
bool Manager::calculateAllPay(Company* company) {
  for (int i = 0; i < company->employeeList.size(); i++) {
    std::cout << "\n\n==================== Pay for "
              << company->employeeList[i]->get_name()
              << " ====================\n\n";
    company->employeeList[i]->calculatePay(company);

    // display neatness
    std::cout << "\n================================================";
    std::cout << "================================================\n\n\n";
  }

  return true;
}