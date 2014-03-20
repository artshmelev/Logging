#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
#include <fstream>
#include <string>

class Logging {
public:
  static const Logging& Instance() {
    static Logging theSingleInstance;
    return theSingleInstance;
  }
  
  void config(const std::string& path, int level) const;
  void print(const std::string& message) const;
  void logDebug(const std::string& message) const;
  void logInfo(const std::string& message) const;
  void logWarning(const std::string& message) const;
  void logError(const std::string& message) const;
  void logCritical(const std::string& message) const;

private:
  Logging() {};
  Logging(const Logging& root);
  Logging& operator=(const Logging&);
  
  const std::string getDateTime() const;
  static std::string pathToFile;
};

#endif // LOGGING_H
