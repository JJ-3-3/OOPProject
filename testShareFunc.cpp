// testing shareprice change
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

double changeTotalShareValue(double share) {
  double randDouble = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

  randDouble = randDouble * 2;
  randDouble = randDouble - 1;

  double answer;
  answer = share + ((share * 0.21 * randDouble) + 0.01 * share) / 7;
  return answer;
}

int main(void) {
  double shareValue = 10.99;
  // init random seed
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  for (int i = 0; i < 365; i++) {
    shareValue = changeTotalShareValue(shareValue);

    std::cout << "iteration change number " << i + 1 << ": " << shareValue
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // sleep(1);
  }
  return 0;
}