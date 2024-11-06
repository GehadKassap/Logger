#include "Logger.h"

Logger::Logger()
{
    logfile.open("logs/Logfile.log", std::ios::app);
}

Logger::~Logger()
{
    if (logfile.is_open())
    {
        logfile.close();
    }
}

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

std::string Logger::getTime()
{
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now);
    std::ostringstream oss;
    oss << (localTime->tm_year + 1900) << "-"
        << (localTime->tm_mon + 1) << "-"
        << localTime->tm_mday << " "
        << localTime->tm_hour << ":"
        << localTime->tm_min << ":"
        << localTime->tm_sec;
    return oss.str();
}

void Logger::log(const std::string &message)
{
    std::lock_guard<std::mutex> lock(mtx);
    logfile << "[" << getTime() << "] " << message << std::endl;
}
