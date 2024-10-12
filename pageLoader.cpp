#include "pageLoader.h"

#include "Company.h"

int pageLoader::currentPage = 1;

pageLoader::pageLoader(Company* theCompany) {
  loadLogInPage(theCompany);
  this->currentPage = currentPage;
}

pageLoader::~pageLoader() {}

void pageLoader::navigateToPage(int pageIndex) {
  if (pageIndex >= 1 && pageIndex <= 3) {
    // adds a bunch of endlines if it is going to a new page
    std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
  }
  if (pageIndex == 1) {
  }
}

void pageLoader::loadFinancePage() {}

void pageLoader::loadTimesheetPage() {}

void pageLoader::loadLogInPage(Company* company) {
  std::string inputUsername;
  std::string inputPassword;

  Employee* loggedUser;

  bool hasLoggedIn = false;
  Employee* fetchedEmployee;

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
  bool isAdmin = false;

  std::cout << "~~~~~~~~~~~~~~~~" << std::endl;

  if (loggedUser->isAnAdmin()) {
    isAdmin = true;
  }

  std::cout << "Logged in as: " << loggedUser->get_name() << std::endl;

  navigateToPage(2);
}

void pageLoader::loadMainPage() {}
