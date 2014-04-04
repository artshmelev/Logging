#include <iostream>
#include <thread>

#include "logging.h"

void Func(int id) {
  for (int i = 0; i < 10; ++i)
    Logging::Instance().LogInfo("I am thread " + std::to_string(id));
}

int main() {
  Logging::Instance().Config("log.txt", Logging::kDebug);
  int p = 45;
  double d = 4.0;
  Logging::Instance().LogInfo("Starting logging");
  Logging::Instance().LogError("Test ERROR message");
  Logging::Instance().LogCritical("Test CRITICAL message");
  Logging::Instance().LogWarning("p = " + std::to_string(p));
  Logging::Instance().LogInfo("d = " + std::to_string(d));

  for (int i = 0; i < 513; ++i) {
    Logging::Instance().LogDebug("1234567");
  }

  std::thread thread1(Func, 1);
  std::thread thread2(Func, 2);

  thread1.join();
  thread2.join();

  Logging::Instance().LogInfo("Finishing logging");

  return 0;
}

