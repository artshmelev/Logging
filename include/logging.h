#ifndef LOGGING_H_
#define LOGGING_H_

#include <string>

#include "buffer.h"

class Logging {
public:
  static const Logging& Instance() {
    static Logging single_instance;
    return single_instance;
  }
  
  void Config(const std::string& path, int log_level) const;
  void LogDebug(const std::string& message) const;
  void LogInfo(const std::string& message) const;
  void LogWarning(const std::string& message) const;
  void LogError(const std::string& message) const;
  void LogCritical(const std::string& message) const;
  enum {kDebug = 0, kInfo, kWarning, kError, kCritical};

private:
  Logging() {};
  Logging(const Logging&);
  Logging& operator=(const Logging&);
  
  const std::string GetDateTime() const;
  static Buffer buffer_;
  static int level_;
};

#endif // LOGGING_H_
