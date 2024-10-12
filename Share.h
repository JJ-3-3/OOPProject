

#ifndef SHARE_H
#define SHARE_H

class Share {
 public:
  static double shareValue;
  static int numTotalShares;

 public:
  Share();
  Share(double shareValue, int numTotalShares);
};

#endif  // SHARE_H