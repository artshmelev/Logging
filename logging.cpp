#include "logging.h"

#include <ctime>

Buffer Logging::buffer;

void Logging::config(const std::string& path, int level) const {
  buffer.setPath(path);
}

void Logging::logDebug(const std::string& message) const {
  buffer.add("DEBUG    [" + getDateTime() + "] " + message);
}

void Logging::logInfo(const std::string& message) const {
  buffer.add("INFO     [" + getDateTime() + "] " + message);
}

void Logging::logWarning(const std::string& message) const {
  buffer.add("WARNING  [" + getDateTime() + "] " + message);
}

void Logging::logError(const std::string& message) const {
  buffer.add("ERROR    [" + getDateTime() + "] " + message);
}

void Logging::logCritical(const std::string& message) const {
  buffer.add("CRITICAL [" + getDateTime() + "] " + message);
}

const std::string Logging::getDateTime() const {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  return buf;
}

