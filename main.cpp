#include "logging.h"
#include "buffer.h"

#include <iostream>

int main() {
  Logging::Instance().config("log.txt", 1);
  Logging::Instance().logInfo("Starting logging");
  Logging::Instance().logWarning("Take it easy");

  Buffer buf;
  buf.add("hello world");
  buf.writeToFile("sdad");
  return 0;
}

