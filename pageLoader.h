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
  pageLoader(Company* company);
  ~pageLoader();
  void navigateToPage(int pageIndex);
  void loadFinancePage();
  void loadTimesheetPage();
  void loadLogInPage();
  void loadEmployeeManagementPage();
  void loadMainPage();
};

#endif