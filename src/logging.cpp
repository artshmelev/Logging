#include <ctime>
#include <future>

#include "logging.h"

Buffer Logging::buffer_;
int Logging::level_ = Logging::kDebug;

void Logging::Config(const std::string& path, int log_level) const {
  buffer_.set_path(path);
  level_ = log_level;
}

void Logging::LogDebug(const std::string& message) const {
  if (level_ <= kDebug)
    auto fut = std::async(std::launch::async, &Buffer::Add, &buffer_,
                          "DEBUG    [" + GetDateTime() + "] " + message);
}

void Logging::LogInfo(const std::string& message) const {
  if (level_ <= kInfo)
    auto fut = std::async(std::launch::async, &Buffer::Add, &buffer_,
                          "INFO     [" + GetDateTime() + "] " + message);
}

void Logging::LogWarning(const std::string& message) const {
  if (level_ <= kWarning)
    auto fut = std::async(std::launch::async, &Buffer::Add, &buffer_,
                          "WARNING  [" + GetDateTime() + "] " + message);
}

void Logging::LogError(const std::string& message) const {
  if (level_ <= kError)
    auto fut = std::async(std::launch::async, &Buffer::Add, &buffer_,
                          "ERROR    [" + GetDateTime() + "] " + message);
}

void Logging::LogCritical(const std::string& message) const {
  auto fut = std::async(std::launch::async, &Buffer::Add, &buffer_,
                        "CRITICAL [" + GetDateTime() + "] " + message);
}

const std::string Logging::GetDateTime() const {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  return buf;
}

