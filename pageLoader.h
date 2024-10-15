#ifndef PAGELOADER_H
#define PAGELOADER_H

#include <iostream>

#include "Company.h"
#include "Employee.h"

class pageLoader {
 private:
  static int currentPage;
  Company* company;
  Employee* curEmployee;
  bool isAdmin;
  /* data */
 public:
  // loads a page
  pageLoader(Company* company);

  // destructor for the page loader
  ~pageLoader();

  // function to navigate to pages
  void navigateToPage(int pageIndex);

  // loads finance page
  void loadFinancePage();

  // loads timesheet page
  void loadTimesheetPage();

  // loads login page
  void loadLogInPage();

  // loads employee managemnt page
  void loadEmployeeManagementPage();

  // loads main page
  void loadMainPage();

  // loads manage page, only accessible by admins
  void loadManagePage();
};

#endif