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

  Employee ethan(1, "Ethan Lawrie", "elawrie", "test123", true);
  Employee john(2, "John Doe", "jdoe", "strongpassword", false);

  Employee companyPlaceholder(0, "Company", "company", "companypassword", true);
  Employee defaultUser(-1, "User", "user", "default", false);

  std::vector<Employee*> employeeVect;

  employeeVect.push_back(&defaultUser);
  // employeeVect.push_back(&companyPlaceholder);

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company company(10, 0.2, employeeVect);

  company.companyRep = &companyPlaceholder;

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

  // initialises system loader and the rest of the process
  pageLoader systemLoader = pageLoader(&company);

  // std::this_thread::sleep_for(std::chrono::seconds(8));
  // int navigatedPageIndex;
  // std::string inputString;
  // int inputInt;
  return 0;
}
