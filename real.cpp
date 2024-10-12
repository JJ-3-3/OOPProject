// testing

#include <iostream>

// #include "Employee.cpp"
#include <chrono>
#include <thread>

#include "Company.h"
#include "Employee.h"
#include "Share.h"
#include "pageLoader.h"

// using namespace std;

int main() {
  bool hasFinished = false;

  Employee ethan(1, "Ethan Lawrie", "elawrie", "test123");
  Employee john(2, "John Doe", "jdoe", "strongpassword");

  Employee companyPlaceholder(0, "Company", "company", "companypassword");
  Employee defaultUser(-1, "User", "user", "default");

  std::vector<Employee*> employeeVect;

  employeeVect.push_back(&defaultUser);
  employeeVect.push_back(&companyPlaceholder);

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company company(10, 0.2, employeeVect);

  Share share1;
  Share share2;
  Share share3;
  Share share4;
  Share share5;
  Share share6;
  Share share7;
  Share share8;
  Share share9;
  Share share10;
  std::vector<Share> initialShares = {share1, share2, share3, share4, share5,
                                      share6, share7, share9, share10};

  for (int i = 0; i < initialShares.size(); i++) {
    companyPlaceholder.addShare(&initialShares[i]);
  }

  std::cout << "Welcome to the share registry" << std::endl;

  pageLoader systemLoader = pageLoader(&company);

  // system("cls");

  // systemLoader

  // navigateToPage

  // std::this_thread::sleep_for(std::chrono::seconds(8));
  int navigatedPageIndex;
  std::string inputString;
  int inputInt;

  std::cout << std::endl;

  // std::cout << "Navigate to where? (1:Timesheet, 2:Finance): ";
  // std::cin >> inputInt;

  // if (inputInt == 1) {
  //   // clrscr();
  //   std::cout << "Timesheet" << std::endl;

  //   Employee* employeeManaged = loggedUser;

  //   if (isAdmin) {
  //     std::cout
  //         << "Would you like to manage another employees timesheet? (Y/N): ";
  //     std::cin >> inputString;
  //     if (inputString == "Y") {
  //       std::cout << "\nPlease enter employee username: ";
  //       std::cin >> inputString;

  //       employeeManaged = company.findEmployee(inputString);
  //     }
  //   }

  //   std::cout << std::endl;

  //   bool canLeave = false;

  //   while (!canLeave) {
  //     std::cout
  //         << "Would you like to: \n1. View Timesheet for current employee
  //         \n2. "
  //            "Enter in a timesheet working slot for the current employee \n3.
  //            " "Clock in for the current employee \n4. Clock out for the
  //            current " "employee \nEnter your choice here: ";

  //     std::cin >> inputInt;

  //     std::cout << std::endl;

  //     int breakLength;
  //     std::string theWorkingType;
  //     double hoursMult;

  //     switch (inputInt) {
  //       case 1:
  //         employeeManaged->printTimesheetEntries();
  //         break;

  //       case 2:
  //         // TODO

  //       case 3:
  //         employeeManaged->clock();
  //         break;

  //       case 4:

  //         std::cout << "\nPlease enter your work type for the period (Normal,
  //         "
  //                      "Sick, Travel): ";
  //         std::cin >> theWorkingType;

  //         if (theWorkingType == "Normal") {
  //           hoursMult = 1;
  //         } else if (theWorkingType == "Sick") {
  //           hoursMult = 0.8;
  //         } else if (theWorkingType == "Travel") {
  //           hoursMult = 1.5;
  //         } else {
  //           hoursMult = 1;
  //         }

  //         std::cout << "Please set break duration: ";
  //         std::cin >> breakLength;
  //         if (breakLength < 0 || breakLength > 1000) {
  //           breakLength = 0;
  //         }

  //         if (isAdmin) {
  //           std::cout << "Please set the hours multiplier: ";
  //           std::cin >> hoursMult;
  //         }

  //         employeeManaged->clockOut(theWorkingType, hoursMult, breakLength);
  //         break;

  //       default:
  //         canLeave = true;
  //         break;
  //     }
  //   }
  // }

  return 0;
}
