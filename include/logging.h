#ifndef LOGGING_H_
#define LOGGING_H_

namespace logging
{

enum Level
{
    kDebug = 0,
    kInfo,
    kWarn,
    kError,
    kCrit
};

struct Config
{
    Config(const std::string& aPath, Level aLevel)
        : m_Path(aPath)
        , m_Level(aLevel) {}

    std::string m_Path;
    Level       m_Level;
};

void setConfig(const std::string& aPath, Level aLevel);
void debug(const std::string& aMsg);
void info(const std::string& aMsg);
void warn(const std::string& aMsg);
void error(const std::string& aMsg);
void crit(const std::string& aMsg);

} // namespace logging

#endif // LOGGING_H_
