#include "logging.h"

#include <iostream>

int main() {
  Logging::Instance().config("log.txt", 1);
  Logging::Instance().logInfo("Starting logging");
  Logging::Instance().logWarning("Take it easy");
  return 0;
}

