#include "Company.h"

Employee* Company::findEmployee(std::string username) {
  bool foundID = false;
  Employee* foundEmployee;
  for (int i = 0; i < employeeList.size(); i++) {
    if (username == employeeList[i]->get_username()) {
      foundID = true;
      foundEmployee = employeeList[i];
    }
  }
  if (foundID) {
    return foundEmployee;
  } else {
    return nullptr;
  }
}

void Company::assignShares(Employee* receivingEmp, int shareAmount) {
  // adds the designated amount of shares to the employee
  for (int i = 0; i < shareAmount; i++) {
    receivingEmp->shareList.push_back(companyRep->shareList.back());
    companyRep->shareList.pop_back();
  }

  std::cout << "\n==================== Share Allotment Statement "
               "====================\n\n";
  std::cout << "Allotted " << shareAmount << " shares to "
            << receivingEmp->get_name() << "\n"
            << std::endl;
}

void Company::buyBackShare(Employee* targetEmp) {
  // buys back all of the shares from the employee
  int sharesBoughtBack = targetEmp->shareList.size();
  for (int i = 0; i < sharesBoughtBack; i++) {
    companyRep->shareList.push_back(targetEmp->shareList.back());
    targetEmp->shareList.pop_back();
  }
  std::cout << "\n==================== Share Buyback Statement "
               "====================\n\n";
  std::cout << "Bought back " << sharesBoughtBack << " shares from "
            << targetEmp->get_name() << "\n"
            << std::endl;
}

// function randomly changes the share price by a slight positive increase on
// average, but is capable of going -4.98% to 5.02% increase
void Company::changeTotalShareValue() {
  double randDouble = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

  randDouble = randDouble * 2;
  randDouble = randDouble - 1;

  Share::shareValue =
      Share::shareValue +
      ((Share::shareValue * 0.21 * randDouble) + 0.01 * Share::shareValue) / 7;
}

//   std::srand(static_cast<unsigned int>(time(nullptr)));
//   float randomValue =
//       static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX) / 2) -
//       1;
//   Share::shareValue =
//       Share::shareValue + 0.002 + (Share::shareValue * 0.05 * randomValue);
// }

// void Company::increaseTotalShareNum(int increase) {
//     if (increase <= 0 || increase > 20000) {
//     std::cout << "did not increase share value" << std::endl;
//   } else if (increase > 0 && increase < 20000) {
//     double tempShareValues = Share::shareValue;

//     Share::numTotalShares += increase;

//     // dilutes the share value to accompany for the newly issued shares.
//     Share::shareValue = tempShareValues / Share::numTotalShares;

//   }

// }

// double Company::returnTotalShareValue() {
//   return (Share::shareValue * Share::numTotalShares);
// }
