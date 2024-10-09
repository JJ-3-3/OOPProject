#include "Share.h"

Share::Share() {
  *shareValue = 1.25;
  *numTotalShares = 250000;
}

Share::Share(int* n, double* sharePointer) {
  shareValue = sharePointer;
  numTotalShares = n;
}
