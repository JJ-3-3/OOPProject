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

void Company::increaseTotalShareNum(int increase) {
  // increase the total share price
  //(total number + increase)/ share price

  // can only increase shares, cannot decrease and maximum of 20 000 shares
  // issued.

  // stores temporarily the total share value at the moment, pre increase

  if (increase <= 0 || increase > 20000) {
    std::cout << "did not increase share value" << std::endl;
  } else if (increase > 0 && increase < 20000) {
    double tempShareValues = returnTotalShareValue();

    Share::numTotalShares += increase;

    // dilutes the share value to accompany for the newly issued shares.
    Share::shareValue = tempShareValues / Share::numTotalShares;
  }
}

double Company::returnTotalShareValue() {
  return (Share::shareValue * Share::numTotalShares);
}
