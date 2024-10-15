#include "Company.h"

// finds an employee in the company's employee list by their username
Employee* Company::findEmployee(std::string username) {
  bool foundID = false;  // Flag to check if the employee is found
  Employee* foundEmployee;

  // iterate through the employee list to find a matching username, mark and
  // then store
  for (int i = 0; i < employeeList.size(); i++) {
    if (username == employeeList[i]->get_username()) {
      foundID = true;
      foundEmployee = employeeList[i];
    }
  }

  // return the found employee if found, otherwise return nullptr
  if (foundID) {
    return foundEmployee;
  } else {
    return nullptr;
  }
}

// assigns a specified number of shares to an employee
void Company::assignShares(Employee* receivingEmp, int shareAmount) {
  for (int i = 0; i < shareAmount; i++) {
    receivingEmp->shareList.push_back(
        companyRep->shareList.back());  // Add share to employee
    companyRep->shareList.pop_back();  // Remove share from company's share list
  }

  // console output
  std::cout << "\n==================== Share Allotment Statement "
               "====================\n\n";
  std::cout << "Allotted " << shareAmount << " shares to "
            << receivingEmp->get_name() << "\n"
            << std::endl;
}

// buys back all shares from a given employee
void Company::buyBackShare(Employee* targetEmp) {
  // get the number of shares the employee owns
  int sharesBoughtBack = targetEmp->shareList.size();

  // transfer all shares back to company
  for (int i = 0; i < sharesBoughtBack; i++) {
    companyRep->shareList.push_back(targetEmp->shareList.back());
    targetEmp->shareList.pop_back();
  }

  // uutput to console
  std::cout << "\n==================== Share Buyback Statement "
               "====================\n\n";
  std::cout << "Bought back " << sharesBoughtBack << " shares from "
            << targetEmp->get_name() << "\n"
            << std::endl;
}

// randomly changes the total share value within a small range and a generally
// upwards trend
void Company::changeTotalShareValue() {
  // dividing by max possible number it can generate in order for range to be 0
  // to 1
  double randDouble = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

  // double and then subract 1 to change range from -1 to 1
  randDouble = randDouble * 2;
  randDouble = randDouble - 1;

  // initially designed for a weekly change, up or down less than ~20 percent
  // max in one week, then divided by 7 for a daily change
  Share::shareValue =
      Share::shareValue +
      ((Share::shareValue * 0.21 * randDouble) + 0.01 * Share::shareValue) / 7;
  // adding 0.01*Share::shareValue in order for an upwards trend
  // over long periods of time

  // bug fix
  if (Share::shareValue < 0) {
    Share::shareValue == 0;
  };
}

// Additional unused methods for share operations are commented out below.
// These may be implemented or revised in the future, depending on requirements.

// Increases the total number of shares and adjusts the share value to
// account for dilution.
void Company::increaseTotalShareNum(int increase) {
  if (increase <= 0 || increase > 20000) {
    std::cout << "Did not increase share value" << std::endl;
  } else if (increase > 0 && increase <= 20000) {
    double tempShareValues = Share::shareValue;
    Share::numTotalShares = Share::numTotalShares + increase;
    Share::shareValue = tempShareValues / Share::numTotalShares;
    numTotalShares = Share::numTotalShares;

    // for (int i = 0; i < increase; i++) {
    //   Share* newshare = new Share();
    //   employeeList[0]->shareList.push_back(newshare);
    // }

    // Dilute
    // the share value.
  }
}

// // Returns the total value of all shares combined.
// double Company::returnTotalShareValue() {
//   return (Share::shareValue * Share::numTotalShares);
// }
