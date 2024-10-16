#include "pageLoader.h"

#include <math.h>

#include <chrono>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

#include "Accounting.h"
#include "CEO.h"
#include "Company.h"
#include "Employee.h"
#include "Generic.h"
#include "Intern.h"
#include "Manager.h"
#include "Receptionist.h"
#include "Sales.h"

// set to page one for initialisation
int pageLoader::currentPage = 1;

void clearScreen() {
  // for other ones
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  // for current testing (wsl/lnux)
  system("clear");
#endif
}

// coverts a string to time for clocking in and out
bool stringToTime(const std::string& dateStr, time_t& resultTime) {
  struct tm tm;
  memset(&tm, 0, sizeof(struct tm));  // Makes tm zero

  // Parse the date string
  char* ret = strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
  if (ret == nullptr || *ret != '\0') {
    // didnt work
    return false;
  }

  // Accouts for daylight savings
  tm.tm_isdst = -1;

  // Converts to time_t
  resultTime = mktime(&tm);
  if (resultTime == -1) {
    return false;
  }

  return true;
}

// load page for the company object
pageLoader::pageLoader(Company* theCompany) {
  this->company = theCompany;
  this->currentPage = currentPage;

  // neatness and readability
  clearScreen();
  std::cout << "==============================================================="
               "===================\n\n";
  std::cout << "=====               Welcome to the employee management system! "
               "               ~~~~\n\n";
  std::cout << "==============================================================="
               "===================\n\n\n\n";

  // allow employees to log in using credentials
  loadLogInPage();
}

// destructor
pageLoader::~pageLoader() {}

// functionto navigate through pages
void pageLoader::navigateToPage(int pageIndex) {
  if (pageIndex >= 1 && pageIndex <= 4) {
    // adds a bunch of endlines if it is going to a new page
    // std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
    clearScreen();
    currentPage = pageIndex;
  }

  // switch statement for each page that is desired
  switch (pageIndex) {
    case 1:
      loadMainPage();
      break;
    case 2:
      loadTimesheetPage();
      break;

    case 3:
      loadFinancePage();
      break;

    case 4:
      loadManagePage();
      break;

    default:
      std::cout << "Not a valid page index! \n" << std::endl;
      break;
  }
}

// loads the finance page
void pageLoader::loadFinancePage() {
  std::string inputString;
  std::string exitString = "Q";

  // run while loop to allow for abuse cases and display finance page
  while (exitString == "Q") {
    std::cout << "==================== Finance Page ====================\n\n";

    // display basic details on current company state
    std::cout << "Current Share Price is: $" << Share::shareValue << std::endl;
    std::cout << "Current Number of Issued Shares is: " << Share::numTotalShares
              << std::endl;
    std::cout << "Total Company value: $" << std::fixed << std::setprecision(2)
              << Share::shareValue * Share::numTotalShares << "\n";

    // selection of options for next page to navigate to
    std::cout << "Please choose an option:\n";
    std::cout << "  1. Process payments for current user\n";
    std::cout << "  2. View share holding statement\n";
    if (isAdmin) {
      std::cout << "  3. Process payments for all users\n";
      std::cout << "  4. View payment history for a specific user\n";
      std::cout << "  5. Process payments for a specific user\n";
    }

    std::cout << "  Q. Return to main page\n";
    std::cout << "  E. Exit program (finish)\n\n";
    std::cout << "Enter your choice: ";

    std::cin >> inputString;
    std::cout << std::endl;

    /************************************************************************************
    options to be run
    ************************************************************************************/

    if (inputString == "1") {
      curEmployee->calculatePay(company);
    } else if (inputString == "5") {
      Employee* fetchedEmployee;
      bool foundEmp = false;
      std::string inputUsername;

      if (!isAdmin) {
        fetchedEmployee = curEmployee;
      } else {
        while (!foundEmp) {
          std::cout << "Please enter employee username: ";
          std::cin >> inputUsername;
          fetchedEmployee = company->findEmployee(inputUsername);

          if (fetchedEmployee == nullptr) {
            std::cout << "Couldn't find employee!\n" << std::endl;

          } else {
            foundEmp = true;
          }
        }
      }

      fetchedEmployee->calculatePay(company);

    } else if (inputString == "3") {
      curEmployee->calculateAllPay(company);
    } else if (inputString == "4") {
      Employee* fetchedEmployee;
      bool foundEmp = false;
      std::string inputUsername;

      while (!foundEmp) {
        std::cout << "Please enter employee username: ";
        std::cin >> inputUsername;
        fetchedEmployee = company->findEmployee(inputUsername);

        if (fetchedEmployee == nullptr) {
          std::cout << "Couldn't find employee!\n" << std::endl;

        } else {
          foundEmp = true;
        }
      }

      fetchedEmployee->printPayments();
    } else if (inputString == "2") {
      curEmployee->printShareSummary();
    } else if (inputString == "E" || inputString == "e") {
      exit(0);
    } else if (inputString == "Q" || inputString == "q") {
      navigateToPage(1);
    }

    /************************************************************************************
    options to be run
    ************************************************************************************/
  }

  // curEmployee->printPayments();
}

// loads the timesheet page
void pageLoader::loadTimesheetPage() {
  std::string inputString;
  int inputInt;

  std::cout << "=================== Timesheet Page ===================\n\n";

  Employee* employeeManaged = this->curEmployee;

  if (isAdmin) {
    std::cout
        << "Would you like to manage another employees timesheet? (Y/N): ";
    std::cin >> inputString;
    if (inputString == "Y" || inputString == "y") {
      // std::cout << "\nPlease enter employee username: ";
      // std::cin >> inputString;

      // employeeManaged = company->findEmployee(inputString);
      Employee* fetchedEmployee;
      bool foundEmp = false;
      std::string inputUsername;

      while (!foundEmp) {
        std::cout << "Please enter employee username: ";
        std::cin >> inputUsername;
        fetchedEmployee = company->findEmployee(inputUsername);

        if (fetchedEmployee == nullptr) {
          std::cout << "Couldn't find employee!\n" << std::endl;

        } else {
          foundEmp = true;
        }
      }
      employeeManaged = fetchedEmployee;
    }
  }

  bool canLeave = false;

  while (!canLeave) {
    // clearScreen();
    std::cout << "Please choose an option:\n";
    std::cout << "  1. View timesheet\n";
    std::cout << "  2. Enter a timesheet working slot\n";
    std::cout << "  3. Clock in \n";
    std::cout << "  4. Clock out\n";
    std::cout << "  Q. Return to main page\n\n";
    std::cout << "Enter your choice: ";

    std::cin >> inputString;
    std::cout << std::endl;

    int breakLength;
    std::string theWorkingType;
    double hoursMult;

    if (inputString == "1") {
      employeeManaged->printTimesheetEntries();

    } else if (inputString == "2") {
      bool validInput = false;
      time_t startingTime;
      time_t endingTime;
      std::string inputStartDate = "";
      std::string inputStartTime = "";
      std::string inputEndDate = "";
      std::string inputEndTime = "";
      std::string endTime;
      std::string startTime;

      while (!validInput) {
        std::cout << "Enter the shift start date (YYYY-MM-DD): ";
        std::cin >> inputStartDate;

        std::cout << std::endl;

        std::cout << "Enter the shift end date (YYYY-MM-DD): ";
        std::cin >> inputEndDate;

        std::cout << std::endl;

        std::cout << "Enter the shift start time (HH:MM:SS eg. 18:10:32): ";
        std::cin >> inputStartTime;

        std::cout << std::endl;

        std::cout << "Enter the shift end time (HH:MM:SS eg. 18:10:32): ";
        std::cin >> inputEndTime;

        std::cout << std::endl;

        std::string startDateTime = inputStartDate + " " + inputStartTime;
        std::string endDateTime = inputEndDate + " " + inputEndTime;

        if (stringToTime(startDateTime, startingTime) == true &&
            stringToTime(endDateTime, endingTime) == true &&
            endDateTime > startDateTime) {
          validInput = true;
        } else {
          std::cout << "Invalid input - Try again \n" << std::endl;
        }
      }

      while (!(theWorkingType == "Normal" || theWorkingType == "Travel" ||
               theWorkingType == "Sick" || theWorkingType == "Other")) {
        std::cout << "\nPlease enter your work type for the period (Normal, "
                     "Sick, Travel, Other): ";
        std::cin >> theWorkingType;

        if (theWorkingType != "Normal" && theWorkingType != "Travel" &&
            theWorkingType != "Sick" && theWorkingType != "Other") {
          std::cout << "Please enter a valid working type! \n" << std::endl;
        }
      }

      if (theWorkingType == "Normal") {
        hoursMult = 1;
      } else if (theWorkingType == "Sick") {
        hoursMult = 0.8;
      } else if (theWorkingType == "Travel") {
        hoursMult = 1.5;
      } else {
        hoursMult = 1;
      }

      std::cout << "Please set break duration (minutes): ";
      if (!(std::cin >> breakLength)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Can't do that. Break length is now set to zero\n";
        breakLength = 0;
      } else if (breakLength < 0 || breakLength > 1000) {
        std::cout << "Can't do that. Break length is now set to zero\n";
        breakLength = 0;
      }

      if (isAdmin) {
        std::cout << "Please set the hours multiplier: ";
        if (!(std::cin >> hoursMult)) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Can't do that. Hours multiplier set to 1\n";
          hoursMult = 1;
        } else if (hoursMult <= 0 || hoursMult >= 5) {
          std::cout << "Can't do that. Hours multiplier set to 1\n";
          hoursMult = 1;
        }
      }

      employeeManaged->clockFullEntry(startingTime, endingTime, theWorkingType,
                                      hoursMult, breakLength);

      std::cout << "Shift entry added! \n\n";

    } else if (inputString == "3") {
      employeeManaged->clock();
    } else if (inputString == "4") {
      while (!(theWorkingType == "Normal" || theWorkingType == "Travel" ||
               theWorkingType == "Sick" || theWorkingType == "Other")) {
        std::cout << "\nPlease enter your work type for the period (Normal, "
                     "Sick, Travel, Other): ";
        std::cin >> theWorkingType;

        if (theWorkingType != "Normal" && theWorkingType != "Travel" &&
            theWorkingType != "Sick" && theWorkingType != "Other") {
          std::cout << "Please enter a valid working type! \n" << std::endl;
        }
      }

      if (theWorkingType == "Normal") {
        hoursMult = 1;
      } else if (theWorkingType == "Sick") {
        hoursMult = 0.8;
      } else if (theWorkingType == "Travel") {
        hoursMult = 1.5;
      } else {
        hoursMult = 1;
      }

      std::cout << "Please set break duration (minutes): ";
      if (!(std::cin >> breakLength)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Can't do that. Break length is now set to zero\n";
        breakLength = 0;
      } else if (breakLength < 0 || breakLength > 1000) {
        std::cout << "Can't do that. Break length is now set to zero\n";
        breakLength = 0;
      }

      if (isAdmin) {
        std::cout << "Please set the hours multiplier: ";
        if (!(std::cin >> hoursMult)) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Can't do that. Hours multiplier set to 1\n";
          hoursMult = 1;
        } else if (hoursMult <= 0 || hoursMult >= 5) {
          std::cout << "Can't do that. Hours multiplier set to 1\n";
          hoursMult = 1;
        }
      }

      employeeManaged->clockOut(theWorkingType, hoursMult, breakLength);
    } else if (inputString == "Q" || inputString == "q") {
      canLeave = true;
      navigateToPage(1);
    } else {
      std::cout << "Please try again.\n" << std::endl;
    }
  }
  inputString = "";
  inputInt = 0;
  navigateToPage(1);
}

// loads the login page
void pageLoader::loadLogInPage() {
  std::string inputUsername;
  std::string inputPassword;

  Employee* loggedUser;

  bool hasLoggedIn = false;
  Employee* fetchedEmployee;

  std::cout << "==================== Login Page ====================\n\n";

  // not logged in

  while (!hasLoggedIn) {
    std::cout << "Please enter your username: ";
    std::cin >> inputUsername;

    fetchedEmployee = company->findEmployee(inputUsername);

    if (fetchedEmployee == nullptr) {
      std::cout << "Couldn't find employee!\n" << std::endl;

    } else {
      for (int i = 0; i < 4; i++) {
        std::cout << "Please enter your password: ";
        std::cin >> inputPassword;

        if (inputPassword == fetchedEmployee->get_password()) {
          hasLoggedIn = true;
          loggedUser = fetchedEmployee;
          break;
        } else if (i == 3) {
          std::cout << "too many login attempts! Try again\n" << std::endl;
        }
      }
    }
  }
  // bool isAdmin = false;

  std::cout << "~~~~~~~~~~~~~~~~" << std::endl;

  if (loggedUser->isAnAdmin()) {
    this->isAdmin = true;
  } else {
    this->isAdmin = false;
  }

  std::cout << "\nLogin successful!\n";
  std::cout << "Welcome, " << loggedUser->get_name() << "!" << std::endl;
  if (loggedUser->isAnAdmin()) {
    std::cout << "You have admin access\n" << std::endl;
  } else {
    std::cout << "You have non-admin access\n" << std::endl;
  }

  // wait for 4 seconds to display the message (as it will navigate to a new
  // page)

  std::this_thread::sleep_for(std::chrono::seconds(4));

  this->curEmployee = loggedUser;

  navigateToPage(1);
}

// loads employee management page
void pageLoader::loadEmployeeManagementPage() {}

// loads main page
void pageLoader::loadMainPage() {
  std::cout << "=================== Main Page ===================\n\n";
  std::cout << "Welcome to the main page for managing employees and navigating "
               "to other pages\n\n";

  while (currentPage == 1) {
    std::string inputString;

    std::cout << "Please choose an option:\n";
    std::cout << "  1. Timesheet\n";
    std::cout << "  2. Finance\n";
    if (isAdmin) {
      std::cout << "  3. Employee Management\n";
    }
    std::cout << "  E. Exit the program\n\n";
    std::cout << "Enter your choice: ";

    std::cin >> inputString;
    std::cout << std::endl;

    if (inputString == "1") {
      navigateToPage(2);  // Timesheet page
    } else if (inputString == "2") {
      navigateToPage(3);  // finance page
    } else if (inputString == "3" && isAdmin) {
      navigateToPage(4);  // employee management page
    } else if (inputString == "E" || inputString == "e") {
      exit(0);
    } else {
      std::cout << "Please try again.\n" << std::endl;
    }
  }
}

// loads the manage page, only accessible to admins
void pageLoader::loadManagePage() {
  std::cout
      << "=================== Manage Employees Page ===================\n\n";

  std::cout << "Welcome to the manage employee page" << std::endl;

  while (currentPage == 4) {
    std::string inputString;

    std::cout << "Please choose an option:\n";
    std::cout << "  1. Add an employee\n";

    std::cout << "  Q. Return to main page\n\n";
    std::cout << "Enter your choice: ";

    std::cin >> inputString;
    std::cout << std::endl;

    if (inputString == "1") {
      int inputInt;
      std::string fullname, username, password, employeeType;

      int payrate;

      std::cout << "What will be the full name of the employee?: ";
      // std::cin >> inputString;
      std::getline(std::cin >> std::ws, inputString);

      fullname = inputString;

      std::cout << "What will be the username of the employee? (no spaces): ";
      std::cin >> inputString;

      username = inputString;

      std::string confirmString = "o";
      while (confirmString != "Y" && confirmString != "y") {
        std::cout << "What will be the password of the employee?: ";
        std::cin >> inputString;

        std::cout << "Are you sure you want to use this password? (Y/N) -> "
                  << inputString << ": ";
        std::cin >> confirmString;
      }

      // std::cout << "What will be the pay rate of the employee? (in dollars
      // per "
      //              "hour eg. 50): ";
      // std::cin >> inputInt;

      // payrate = inputInt;

      // if (!(std::cin >> inputInt)) {
      //   std::cin.clear();
      //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      //   std::cout << "Can't do that. The pay rate is now set to $30/h\n";
      //   payrate = 30;
      // } else if (inputInt < 0 || inputInt > 1000) {
      //   std::cout << "Can't do that. The pay rate is now set to $30/h\n";
      //   payrate = 30;
      // }

      std::cout << "\n\nWhat job role is the employee? \n";

      std::cout << "  1. Manager\n";
      std::cout << "  2. General\n";
      std::cout << "  3. Sales\n";
      std::cout << "  4. Accounting\n";
      std::cout << "  5. Intern\n";
      std::cout << "  6. CEO\n";
      std::cout << "  7. Receptionist\n";
      std::cout << "Please choose an option:\n";
      std::cin >> inputString;

      employeeType = inputString;

      confirmString = "o";
      while (confirmString != "Y" && inputString != "y" &&
             confirmString != "N" && inputString != "n") {
        std::cout << "These are your intending settings for the new employee: "
                  << std::endl;
        std::cout << "  Name: " << fullname << std::endl;
        std::cout << "  Username: " << username << std::endl;
        std::cout << "  Password: " << password << std::endl;
        std::cout << "Are you happy with these settings? (Y/N): ";
        std::cin >> confirmString;
      }
      if (confirmString == "Y" || confirmString == "y") {
        if (inputString == "1") {
          Manager* newEmp = new Manager(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "2") {
          Generic* newEmp = new Generic(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "3") {
          Sales* newEmp = new Sales(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "4") {
          Accounting* newEmp = new Accounting(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "5") {
          Intern* newEmp = new Intern(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "6") {
          CEO* newEmp = new CEO(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "7") {
          Receptionist* newEmp =
              new Receptionist(0, fullname, username, password);
          company->employeeList.push_back(newEmp);
        } else if (inputString == "2") {
        }
      }

    } else if (inputString == "Q" || inputString == "q") {
      navigateToPage(1);
    } else {
      std::cout << "Please try again.\n" << std::endl;
    }
  }
}