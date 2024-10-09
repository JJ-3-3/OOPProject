#ifndef SHARE_H
#define SHARE_H

class Share {
 public:
  double *shareValue;
  int *numTotalShares;

 public:
  Share();
  Share(int *n, double *sharePointer);
};
#endif  // SHARE_H