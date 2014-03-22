#include "logging.h"
#include "buffer.h"

#include <iostream>

int main() {
  Logging::Instance().config("log.txt", 1);
  int p = 45;
  Logging::Instance().logInfo("Starting logging");
  Logging::Instance().logWarning("Take it easy");
  Logging::Instance().logWarning("p = " + std::to_string(p));

  for (int i = 0; i < 513; ++i) {
    Logging::Instance().logDebug("1234567");
  }

  return 0;
}

