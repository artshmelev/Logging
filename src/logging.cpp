#include <atomic>
#include <cstring>
#include <ctime>
#include <fstream>
#include <memory>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>

#include "logging.h"

using namespace logging;

namespace
{

const std::string levelToStr(Level aLevel)
{
    switch (aLevel)
    {
    case kDebug: return "DEBUG";
    case kInfo : return "INFO ";
    case kWarn : return "WARN ";
    case kError: return "ERROR";
    case kCrit : return "CRIT ";
    default:     return "     ";
    }
}

const std::string getDateTime()
{
    time_t sNow = ::time(NULL);
    struct tm sTstruct;
    char sBuf[80];
    sTstruct = *localtime(&sNow);
    strftime(sBuf, sizeof(sBuf), "%Y-%m-%d %X", &sTstruct);
    return sBuf;
}

class Logging
{
public:
    ~Logging();
    void setConfig(const std::string& aPath, Level aLevel);
    void debug(const std::string& aMsg);
    void info(const std::string& aMsg);
    void warn(const std::string& aMsg);
    void error(const std::string& aMsg);
    void crit(const std::string& aMsg);

private:
    typedef std::shared_ptr<Config>  ConfigPtr;
    typedef std::vector<std::string> Storage;

private:
    ConfigPtr config() const { return m_Config; }
    void log(const std::string& aMsg, Level aLevel);
    void flush();
    void flush(std::mutex& aLock);

private:
    ConfigPtr        m_Config;
    Storage          m_Storage;
    std::mutex       m_Mutex;
    std::thread      m_FlushThread = std::thread([this] { flush(); });
    std::atomic_bool m_IsStopping{false};
};

Logging::~Logging()
{
    m_IsStopping = true;
    if (m_FlushThread.joinable())
        m_FlushThread.join();
}

void Logging::setConfig(const std::string& aPath, Level aLevel)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Config.reset(new Config(aPath, aLevel));
}

void Logging::debug(const std::string& aMsg)
{
    log(aMsg, kDebug);
}

void Logging::info(const std::string& aMsg)
{
    log(aMsg, kInfo);
}

void Logging::warn(const std::string& aMsg)
{
    log(aMsg, kWarn);
}

void Logging::error(const std::string& aMsg)
{
    log(aMsg, kError);
}

void Logging::crit(const std::string& aMsg)
{
    log(aMsg, kCrit);
}

void Logging::log(const std::string& aMsg, Level aLevel)
{
    if (config()->m_Level <= aLevel)
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        m_Storage.push_back(getDateTime() + "    " + levelToStr(aLevel) +
                            "    " + aMsg + "\n");
    }
}

void Logging::flush()
{
    while (!m_IsStopping)
    {
        ::sleep(1);
        m_Mutex.lock();
        flush(m_Mutex);
    }
}

void Logging::flush(std::mutex& aLock)
{
    auto sCopy = m_Storage;
    m_Storage.clear();
    aLock.unlock();

    std::ofstream sOut(config()->m_Path, std::ios_base::app);
    for (auto& s: sCopy)
        sOut.write(s.c_str(), s.length());
    sOut.close();
}

Logging gLogging;

} // namespace anonymous


void logging::setConfig(const std::string& aPath, Level aLevel)
{
    gLogging.setConfig(aPath, aLevel);
}

void logging::debug(const std::string& aMsg)
{
    gLogging.debug(aMsg);
}

void logging::info(const std::string& aMsg)
{
    gLogging.info(aMsg);
}

void logging::warn(const std::string& aMsg)
{
    gLogging.warn(aMsg);
}

void logging::error(const std::string& aMsg)
{
    gLogging.error(aMsg);
}

void logging::crit(const std::string& aMsg)
{
    gLogging.crit(aMsg);
}
