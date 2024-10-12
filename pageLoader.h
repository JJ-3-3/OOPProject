#ifndef PAGELOADER_H
#define PAGELOADER_H

#include <iostream>

#include "Company.h"

class pageLoader {
 private:
  static int currentPage;
  /* data */
 public:
  pageLoader(Company* company);
  ~pageLoader();
  void navigateToPage(int pageIndex);
  void loadFinancePage();
  void loadTimesheetPage();
  void loadLogInPage(Company* company);
  void loadMainPage();
};

#endif