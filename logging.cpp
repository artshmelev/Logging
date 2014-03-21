#include "logging.h"

#include <ctime>

std::string Logging::pathToFile = "";
Buffer Logging::buffer;

void Logging::config(const std::string& path, int level) const {
  pathToFile = path;
}

void Logging::print(const std::string& message) const {
  std::cout << message << std::endl;
}

void Logging::logDebug(const std::string& message) const {
  std::cout << "DEBUG    [" << getDateTime() << "] " << message << std::endl;
}

void Logging::logInfo(const std::string& message) const {
  std::cout << "INFO     [" << getDateTime() << "] " << message << std::endl;
  buffer.add("INFO     [" + getDateTime() + "] " + message);
  std::ofstream outputFile;
  outputFile.open(pathToFile);
  outputFile << "INFO     [" << getDateTime() << "] " << message << std::endl;
  outputFile.close();
  buffer.writeToFile("ffs");
}

void Logging::logWarning(const std::string& message) const {
  std::cout << "WARNING  [" << getDateTime() << "] " << message << std::endl;
}

void Logging::logError(const std::string& message) const {
  std::cout << "ERROR    [" << getDateTime() << "] " << message << std::endl;
}

void Logging::logCritical(const std::string& message) const {
  std::cout << "CRITICAL [" << getDateTime() << "] " << message << std::endl;
}

const std::string Logging::getDateTime() const {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  return buf;
}

