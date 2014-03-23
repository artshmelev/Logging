#include "logging.h"

#include <iostream>
#include <thread>

void func(int id) {
  for (int i = 0; i < 10; ++i) {
    std::cout << "thread " << id << " is in\n";
    Logging::Instance().logInfo("I am thread " + std::to_string(id));
    std::cout << "thread " << id << " is out\n";
  }
}

int main() {
  Logging::Instance().config("log.txt", 1);
  int p = 45;
  double d = 4.0;
  Logging::Instance().logInfo("Starting logging");
  Logging::Instance().logError("Test ERROR message");
  Logging::Instance().logCritical("Test CRITICAL message");
  Logging::Instance().logWarning("p = " + std::to_string(p));
  Logging::Instance().logInfo("d = " + std::to_string(d));

  for (int i = 0; i < 513; ++i) {
    Logging::Instance().logDebug("1234567");
  }

  std::thread thread1(func, 1);
  std::thread thread2(func, 2);

  thread1.join();
  thread2.join();

  Logging::Instance().logInfo("Finishing logging");

  return 0;
}

