// testing

#include <iostream>

// #include "Employee.cpp"
#include <chrono>
#include <thread>

#include "Accounting.h"
#include "CEO.h"
#include "Company.h"
#include "Employee.h"
#include "Intern.h"
#include "Manager.h"
#include "Share.h"
#include "pageLoader.h"

// using namespace std;
void runShareValueUpdate(Company &company) {
  while (true) {
    company.changeTotalShareValue();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  bool hasFinished = false;

  CEO ethan(1, "Ethan Lawrie", "elawrie", "test123");
  Manager john(2, "John Doe", "jdoe", "strongpassword");
  Accounting billy(2, "Billy Doe", "bdoe", "be");
  Intern alpha(3, "Hello World", "hworld", "hello");

  CEO companyPlaceholder(0, "Company", "company", "companypassword");
  CEO defaultUser(-1, "User", "user", "default");

  std::vector<Employee *> employeeVect;

  employeeVect.push_back(&companyPlaceholder);
  employeeVect.push_back(&defaultUser);
  employeeVect.push_back(&billy);
  employeeVect.push_back(&alpha);
  // employeeVect.push_back(&defaultUser);
  // employeeVect.push_back(&companyPlaceholder);

  employeeVect.push_back(&ethan);
  employeeVect.push_back(&john);

  Company company(0.95, 0.2, employeeVect);

  // change share value every second to replicate real changes

  company.companyRep = &companyPlaceholder;

  std::vector<Share *> initialShares;

  int shareAmount = 12500000;

  Share::numTotalShares = shareAmount;

  for (int i = 0; i < shareAmount; i++) {
    Share *newshare = new Share();
    initialShares.push_back(newshare);
  }

  for (int i = 0; i < initialShares.size(); i++) {
    companyPlaceholder.addShare(initialShares[i]);
  }

  // assign new thread to run sharevalueupdates every second
  std::thread shareValueThread(runShareValueUpdate, std::ref(company));
  shareValueThread.detach();  // Detach the thread so it runs in the
  // background

  // initialises system loader and the rest of the process
  pageLoader systemLoader = pageLoader(&company);

  // std::this_thread::sleep_for(std::chrono::seconds(8));
  // int navigatedPageIndex;
  // std::string inputString;
  // int inputInt;
  return 0;
}